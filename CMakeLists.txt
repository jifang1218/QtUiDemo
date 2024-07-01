cmake_minimum_required(VERSION 3.5)

set(PROJ_NAME QtUiDemo)
project(${PROJ_NAME} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# for Xcode project
if(CMAKE_GENERATOR STREQUAL "Xcode")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

# Qt config
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# *.cpp
file(GLOB_RECURSE SOURCES "*.cpp")
# exclude temporary files in CMakeFiles directory.
list(FILTER SOURCES EXCLUDE REGEX "/CMakeFiles/")

# *.h
file(GLOB_RECURSE HEADERS "*.h")
# exclude temporary files in CMakeFiles directory.
list(FILTER HEADERS EXCLUDE REGEX "/CMakeFiles/")

# *.ui
file(GLOB_RECURSE FORMS "*.ui")
# exclude temporary files in CMakeFiles directory.
list(FILTER FORMS EXCLUDE REGEX "/CMakeFiles/")

# *.qrc
file(GLOB_RECURSE RESOURCES "*.qrc")
# exclude temporary files in CMakeFiles directory.
list(FILTER RESOURCES EXCLUDE REGEX "/CMakeFiles/")

if(QT_VERSION_MAJOR EQUAL 5)
	qt5_wrap_ui(WRAP_FILES ${FORMS}) 
	qt5_add_resources(QT_RESOURCES ${RESOURCES})
elseif(QT_VERSION_MAJOR EQUAL 6)
	qt6_wrap_ui(WRAP_FILES ${FORMS})
	qt6_add_resources(QT_RESOURCES ${RESOURCES})
endif()


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJ_NAME}
        MANUAL_FINALIZATION
		${WRAP_FILES}
		${SOURCES}
		${HEADERS}
		${RESOURCES}
		${QT_RESOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(${PROJ_NAME} SHARED
			${SOURCES} ${HEADERS} ${WRAP_FILES} ${QT_RESOURCES} ${RESOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(${PROJ_NAME}
			${SOURCES}
			${HEADERS}
			${WRAP_FILES}
			${QT_RESOURCES}
			${RESOURCES}
        )
    endif()
endif()

target_include_directories(${PROJ_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# link dir
target_link_libraries(${PROJ_NAME}
	PRIVATE Qt${QT_VERSION_MAJOR}::Core 
	PRIVATE Qt${QT_VERSION_MAJOR}::Widgets 
	PRIVATE Qt${QT_VERSION_MAJOR}::Gui
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.${PROJ_NAME})
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ${PROJ_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJ_NAME})
endif()

