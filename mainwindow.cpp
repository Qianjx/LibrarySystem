#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//用户界面

void MainWindow::goto_ufunction_window(bool flag){

if(flag==0)

return;

else{

//必要的初始化

ufunction_window=new QWidget();

ufunction_warning_txtedit=new QTextEdit;

ufunction_borrow_lb=new QLabel;

ufunction_return_lb=new QLabel;

ufunction_borrow_le=new QLineEdit;

ufunction_return_le=new QLineEdit;

ufunction_borrow_btn=new QPushButton(tr("点击借阅"));

ufunction_return_btn=new QPushButton(tr("点击归还"));

ufunction_vblo_main=new QVBoxLayout;

ufunction_hblo_bottom=new QHBoxLayout;



//QTextEdit和QLabel的文字



ufunction_window->setWindowTitle(tr("您已进入用户界面"));

ufunction_warning_txtedit->setText(tr("尊敬的用户，为了您和他人的使用方便，请遵守以下规定："));

ufunction_borrow_lb->setText(tr("输入需要借阅的书籍编号："));

ufunction_return_lb->setText(tr("输入需要归还的书籍编号:"));

ufunction_hblo_bottom->addStretch();

ufunction_hblo_bottom->addWidget(ufunction_borrow_lb);

ufunction_hblo_bottom->addWidget(ufunction_borrow_le);

ufunction_hblo_bottom->addWidget(ufunction_borrow_btn);

ufunction_hblo_bottom->addStretch();

ufunction_hblo_bottom->addWidget(ufunction_return_lb);

ufunction_hblo_bottom->addWidget(ufunction_return_le);

ufunction_hblo_bottom->addWidget(ufunction_return_btn);

ufunction_hblo_bottom->addStretch();



//给布局添加控件

ufunction_vblo_main->addWidget(ufunction_warning_txtedit,Qt::AlignHCenter);

ufunction_vblo_main->addLayout(ufunction_hblo_bottom);



ufunction_window->setLayout(ufunction_vblo_main);

ufunction_window->resize(800,600);

ufunction_window->show();



//连接槽，负责借书、还书

connect(ufunction_borrow_btn,SIGNAL(clicked()),this,SLOT(ufunction_user_borrow()));

connect(ufunction_return_btn,SIGNAL(clicked()),this,SLOT(ufunction_user_return()));

}

}
