#include "stackdlg.h"
#include <QHBoxLayout>
StackDlg::StackDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("StackedWidget"));
    list = new QListWidget(this);
    list->insertItem(0, tr("Window1"));
    list->insertItem(1, tr("Window2"));
    list->insertItem(2, tr("Window3"));

    label1 = new QLabel(tr("WindowTest1"));
    label2 = new QLabel(tr("WindowTest2"));
    label3 = new QLabel(tr("WindowTest3"));

    stack = new QStackedWidget(this);
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(5);//设置对话框的边距
    mainLayout->setSpacing(5);//设置各个控件之间的间距
    mainLayout->addWidget(list);
    mainLayout->addWidget(stack, 0, Qt::AlignHCenter);
    mainLayout->setStretchFactor(list, 1);//将控件设置为可伸缩控件，第一个参数指定设置的控件，第儿歌参数大于0则表示此控件为可伸缩控件。
    mainLayout->setStretchFactor(stack, 3);
    connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));
}

StackDlg::~StackDlg()
{

}
