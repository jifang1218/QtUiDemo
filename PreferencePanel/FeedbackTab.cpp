#include "FeedbackTab.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QDebug>

FeedbackTab::FeedbackTab(QWidget *parent) : QWidget(parent) { 
    constructUi();
}

FeedbackTab::~FeedbackTab() {
    qDebug()<<"Feedback Tab destructed.";
}

void FeedbackTab::constructUi() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // link
    QLabel *text = new QLabel("Our Help Center is regulary updated with answers to common questions. <a href=\"https://support.cloudflarewarp.com/hc/en-us\"> Visit Help Center </a>", this);
    text->setOpenExternalLinks(true);
    mainLayout->addWidget(text);

    // grid
    QGridLayout *grid = new QGridLayout();

    // email
    text = new QLabel("Email address: ", this);
    grid->addWidget(text, 0, 0, Qt::AlignRight);
    QLineEdit *lineEdit = new QLineEdit(this);
    //grid->addWidget(lineEdit, 0, 1, Qt::AlignLeft);
    grid->addWidget(lineEdit, 0, 1, 1, 1);

    // subject
    text = new QLabel("Subject: ", this);
    grid->addWidget(text, 1, 0, Qt::AlignRight);
    lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Briefly describe the issue.");
    //grid->addWidget(lineEdit, 1, 1, Qt::AlignLeft);
    grid->addWidget(lineEdit, 1, 1, 1, 1);

    // desc
    text = new QLabel("Description: ", this);
    grid->addWidget(text, 2, 0, Qt::AlignRight);
    QPlainTextEdit *textEdit = new QPlainTextEdit(this);
    textEdit->setPlaceholderText("Describe the issue/improvement in as much detail as you can. \nInclude steps to replicate if relevant.");
    //grid->addWidget(textEdit, 2, 1, Qt::AlignLeft);
    grid->addWidget(textEdit, 2, 1, 1, 1);

    // checkbox, buttons
    QHBoxLayout *line = new QHBoxLayout();
    QCheckBox *share = new QCheckBox("Share debug information", this);
    share->setChecked(true);
    line->addWidget(share);
    line->addStretch();
    QPushButton *button = new QPushButton("View Logs", this);
    button->setAutoDefault(false);
    line->addWidget(button);
    button = new QPushButton("Submit feedback", this);
    button->setAutoDefault(false);
    line->addWidget(button);

    grid->addLayout(line, 3, 1, Qt::AlignLeft);

    mainLayout->addLayout(grid);
}