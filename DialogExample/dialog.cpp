#include "dialog.h"
#include <QGridLayout>
#include <QFileDialog>
#include <QPushButton>
#include <QColorDialog>
#include <QFontDialog>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("各种标准对话框的实例"));
    fileBtn = new QPushButton;
    fileBtn->setText(tr("文件标准对话框实例"));
    fileLineEdit = new QLineEdit;

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileBtn, 0, 0);
    mainLayout->addWidget(fileLineEdit, 0, 1);
    connect(fileBtn, SIGNAL(clicked()), this, SLOT(showFile()));

    colorBtn = new QPushButton;
    colorBtn->setText(tr("颜色标准对话框实例"));
    colorFrame = new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);//根据用户选择的不同颜色更新不同的背景

    mainLayout->addWidget(colorBtn, 1, 0);
    mainLayout->addWidget(colorFrame, 1, 1);
    connect(colorBtn, SIGNAL(clicked()), this, SLOT(showColor()));

    fontBtn = new QPushButton;
    fontBtn->setText(tr("字体标准对话框实例"));
    fontLineEdit = new QLineEdit;
    fontLineEdit->setText(tr("Welcome!"));

    mainLayout->addWidget(fontBtn, 2, 0);
    mainLayout->addWidget(fontLineEdit, 2, 1);
    connect(fontBtn, SIGNAL(clicked(bool)), this, SLOT(showFont()));

    inputBtn = new QPushButton;
    inputBtn->setText(tr("标准输入对话框实例"));
    mainLayout->addWidget(inputBtn, 3, 0);
    connect(inputBtn, SIGNAL(clicked(bool)), this, SLOT(showInputDlg()));

    MsgBtn = new QPushButton;
    MsgBtn->setText(tr("标准消息对话框实例"));
    mainLayout->addWidget(MsgBtn, 3, 1);
    connect(MsgBtn, SIGNAL(clicked(bool)), this, SLOT(showMsgDlg()));

}

void Dialog::showFile()
{
    QString s = QFileDialog::getOpenFileName(this, "open file dialog", "/", "C++ files(*.cpp)::C files(*.c)::Head files(*.h)");
    fileLineEdit->setText(s);
}
void Dialog::showColor()
{
    QColor c = QColorDialog::getColor(Qt::blue);
    if(c.isValid())
    {
        colorFrame->setPalette(QPalette(c));
    }
}
void Dialog::showFont()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok);
    if(ok)
    {
        fontLineEdit->setFont(f);
    }
}
void Dialog::showInputDlg()
{
    inputDlg = new InputDlg(this);
    inputDlg->show();
}
void Dialog::showMsgDlg()
{
    msgDlg = new MsgBoxDlg();
    msgDlg->show();
}

Dialog::~Dialog()
{

}
