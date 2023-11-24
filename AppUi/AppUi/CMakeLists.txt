cmake_minimum_required(VERSION 3.5)

project(AppUi VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# mac
set(CMAKE_PREFIX_PATH "/usr/local/opt/qt5/lib/cmake/Qt5")

# linux 
#set(CMAKE_PREFIX_PATH "/home/jifang/apps/Qt5/5.15.2/gcc_64/include")

# win
#set(CMAKE_PREFIX_PATH "D:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake\\Qt5")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        widgets/SwitchButton.cpp
        widgets/SwitchButton.h
        widgets/SettingsMenu.h
        widgets/SettingsMenu.cpp
        MainPanel.cpp
        MainPanel.h
        PreferencePanel/PreferencePanel.h
        PreferencePanel/PreferencePanel.cpp
        PreferencePanel/GeneralTab.h
        PreferencePanel/GeneralTab.cpp
        PreferencePanel/ConnectionTab.h
        PreferencePanel/ConnectionTab.cpp
        PreferencePanel/AccountTab.h
        PreferencePanel/AccountTab.cpp
        PreferencePanel/DnsTab.h
        PreferencePanel/DnsTab.cpp
        PreferencePanel/FeedbackTab.h
        PreferencePanel/FeedbackTab.cpp
        PreferencePanel/AdvancedTab.h
        PreferencePanel/AdvancedTab.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(AppUi
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET AppUi APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(AppUi SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(AppUi
            ${PROJECT_SOURCES}
        )
    endif()
endif()

qt5_add_resources(RESOURCES res/demo.qrc)
target_sources(${PROJECT_NAME} PRIVATE ${RESOURCES})

target_link_libraries(AppUi PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.AppUi)
endif()
set_target_properties(AppUi PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS AppUi
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AppUi)
endif()
