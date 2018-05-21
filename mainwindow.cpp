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

ufunction_warning_txtedit->setText(tr("尊敬的用户，为了您和他人的使用方便，请遵守以下规定："
                                      "\n"
                                      "1、请勿损坏书籍；"
                                      "\n"
                                      "2、请勿逾期不还；"
                                      "\n"
                                      "3、如果违反，管理员有权注销您的借书权限！"));

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


void MainWindow::goto_afunction_window(bool flag){

if(flag==0)

return;

else{

//必要的初始化

afunction_window=new QWidget();

afunction_add_btn=new QPushButton(tr("书籍入库"));//添加书籍

afunction_add_ok_btn=new QPushButton(tr("提交书籍入库信息"));

afunction_delete_btn=new QPushButton(tr("删除用户"));//删除用户

afunction_search_btn=new QPushButton(tr("搜索图书"));//搜索图书

afunction_show_all_btn=new QPushButton(tr("显示库中所有书籍"));//显示所有书籍

afunction_show_order_btn=new QPushButton(tr("按库存量排序(降序)"));

afunction_show_user_btn=new QPushButton(tr("显示用户表"));

afunction_show_loan_btn=new QPushButton(tr("显示借阅表"));

afunction_search_le=new QLineEdit;

afunction_tableview=new QTableView;

afunction_vblo_main=new QVBoxLayout;

afunction_hblo_sub1=new QHBoxLayout;

afunction_hblo_sub2=new QHBoxLayout;

afunction_hblo_sub3=new QHBoxLayout;

afunction_vblo_combine123=new QVBoxLayout;

afunction_window->setWindowTitle(tr("您当前处在管理员界面"));

afunction_tablemodel=new QSqlTableModel(afunction_window);

afunction_tablemodel->setTable("book");



//中间表格显示

afunction_tableview->setModel(afunction_tablemodel);



//布局添加控件

afunction_vblo_main->addWidget(afunction_tableview);

afunction_hblo_sub1->addWidget(afunction_search_le);

afunction_hblo_sub1->addWidget(afunction_search_btn);

afunction_hblo_sub1->addWidget(afunction_delete_btn);

afunction_hblo_sub2->addWidget(afunction_show_all_btn);

afunction_hblo_sub2->addWidget(afunction_show_order_btn);

afunction_hblo_sub2->addWidget(afunction_add_btn);

afunction_hblo_sub2->addWidget(afunction_add_ok_btn);

afunction_hblo_sub3->addWidget(afunction_show_user_btn);

afunction_hblo_sub3->addWidget(afunction_show_loan_btn);



//布局嵌套

afunction_vblo_combine123->addLayout(afunction_hblo_sub1);

afunction_vblo_combine123->addLayout(afunction_hblo_sub2);

afunction_vblo_combine123->addLayout(afunction_hblo_sub3);

afunction_vblo_main->addLayout(afunction_vblo_combine123);



//显示

afunction_window->setLayout(afunction_vblo_main);

afunction_window->resize(800,600);

afunction_window->show();



//连接槽

connect(afunction_search_btn,SIGNAL(clicked()),this,SLOT(afunction_search()));

connect(afunction_delete_btn,SIGNAL(clicked()),this,SLOT(afunction_delete()));

connect(afunction_show_all_btn,SIGNAL(clicked()),this,SLOT(afunction_show_all()));

connect(afunction_show_order_btn,SIGNAL(clicked()),this,SLOT(afunction_sort()));

connect(afunction_add_btn,SIGNAL(clicked()),this,SLOT(afunction_add()));

connect(afunction_add_ok_btn,SIGNAL(clicked()),this,SLOT(afunction_add_submit()));

connect(afunction_show_user_btn,SIGNAL(clicked()),this,SLOT(afunction_show_user()));

connect(afunction_show_loan_btn,SIGNAL(clicked()),this,SLOT(afunction_show_loan()));

}

}






/*
bool MainWindow::createConnection(){

//连接MySQL数据库

db=QSqlDatabase::addDatabase("QMYSQL");

//设置主机名

db.setHostName("localhost");

//设置数据库名

db.setDatabaseName("mybms");

//设置账号名

db.setUserName("xxx");

//设置密码名

db.setPassword("csdbs");

//设置端口

db.setPort(3306);

if(!db.open()){

QMessageBox::critical(0,QObject::tr("error"),db.lastError().text());

returnfalse;

}

}
*/
