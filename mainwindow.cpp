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

QWidget* ufunction_window=new QWidget();

QTextEdit* ufunction_warning_txtedit=new QTextEdit;

QLabel* ufunction_borrow_lb=new QLabel;

QLabel* ufunction_return_lb=new QLabel;

QLineEdit* ufunction_borrow_le=new QLineEdit;

QLineEdit* ufunction_return_le=new QLineEdit;

QPushButton* ufunction_borrow_btn=new QPushButton(tr("点击借阅"));

QPushButton* ufunction_return_btn=new QPushButton(tr("点击归还"));

QVBoxLayout* ufunction_vblo_main=new QVBoxLayout;

QHBoxLayout* ufunction_hblo_bottom=new QHBoxLayout;



//QTextEdit和QLabel的文字


ufunction_window->setWindowTitle(tr("您已进入用户界面"));

ufunction_warning_txtedit->setText(tr("尊敬的用户，为了您和他人的使用方便，请遵守以下规定："
										"\n"
										"1.最多借八本书"
										"\n"
                                        "2.不得重复借同一本书"
                                        "\n"
                                        "3.遵守以上两条规定"
                                      ));

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

    QWidget* afunction_window;

   // QTextEdit* afunction_warning_txtedit;

   // QLabel* afunction_borrow_lb;

   // QLabel* afunction_return_lb;

   // QLineEdit* afunction_borrow_le;

   // QLineEdit* afunction_return_le;

   // QPushButton* afunction_borrow_btn;

   // QPushButton* afunction_return_btn;

      QVBoxLayout* afunction_vblo_main;

   // QHBoxLayout* afunction_hblo_bottom;

    QPushButton* afunction_add_btn;

    QPushButton* afunction_add_ok_btn;

    QPushButton* afunction_delete_btn;

    QPushButton* afunction_search_btn;

    QPushButton* afunction_show_all_btn;

    QTableView* afunction_tableview;

    QHBoxLayout* afunction_hblo_sub1;

    QHBoxLayout* afunction_hblo_sub2;

    QHBoxLayout* afunction_hblo_sub3;

    QVBoxLayout* afunction_vblo_combine123;

    QPushButton* afunction_show_order_btn;

    QPushButton* afunction_show_user_btn;

    QPushButton* afunction_show_loan_btn;

    QLineEdit* afunction_search_le;

afunction_window=new QWidget();

afunction_add_btn=new QPushButton(tr("书籍入库"));//添加书籍

afunction_add_ok_btn=new QPushButton(tr("提交书籍入库信息"));

afunction_delete_btn=new QPushButton(tr("删除用户"));
//删除用户

afunction_search_btn=new QPushButton(tr("搜索图书"));
//搜索图书

afunction_show_all_btn=new QPushButton(tr("all"));
//显示所有书籍

afunction_show_order_btn=new QPushButton(tr("order"));

afunction_show_user_btn=new QPushButton(tr("user"));

afunction_show_loan_btn=new QPushButton(tr("loan"));

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
void MainWindow::on_query_btn_clicked(){

QString book_name=ui->name_lineEdit->text();

model->setFilter(QString("book_name='%1'").arg(book_name));

model->select();

}
*/

void MainWindow::on_notice_btn_clicked(){

QWidget* notice_window=new QWidget();

QVBoxLayout* notice_vblo=new QVBoxLayout;

QLabel* notice_head=new QLabel;

QLabel* notice_line1=new QLabel;

QLabel* notice_line2=new QLabel;

QLabel* notice_line3=new QLabel;

QLabel* notice_line4=new QLabel;

QLabel* notice_line5=new QLabel;

QLabel* notice_line6=new QLabel;

notice_head->setText(tr("尊敬的用户，欢迎您使用图书管理系统，以下是使用须知：\n"));

QFont font_head("MicrosoftYaHei",15,75);

notice_head->setFont(font_head);

notice_line1->setText(tr("1.。。。\n"));

QFont font1(0,15,0);

notice_line1->setFont(font1);

notice_line2->setText(tr("2.。。。\n"));

QFont font2(0,15,0);

notice_line2->setFont(font2);

notice_line3->setText(tr("3.。。。\n"));

QFont font3(0,15,0);

notice_line3->setFont(font3);

notice_line4->setText(tr("4.。。。\n"));

QFont font4(0,15,0);

notice_line4->setFont(font4);

notice_line5->setText(tr("5.。。。\n"));

QFont font5(0,15,0);

notice_line5->setFont(font5);

notice_line6->setText(tr("6.如有任何问题，请联系：xxx\n"));

QFont font6(0,15,0);

notice_line6->setFont(font6);

//给布局添加控件

notice_vblo->addWidget(notice_head);

notice_vblo->addWidget(notice_line1);

notice_vblo->addWidget(notice_line2);

notice_vblo->addWidget(notice_line3);

notice_vblo->addWidget(notice_line4);

notice_vblo->addWidget(notice_line5);

notice_vblo->addWidget(notice_line6);

//显示

notice_window->setLayout(notice_vblo);

notice_window->resize(800,600);

notice_window->show();

}

void MainWindow::user_register(){

//检测用户是否输入了全部的信息

if(register_name_le->text().isEmpty()||register_pwd_le->text().isEmpty()||register_pwd_check_le->text().isEmpty())
{

QMessageBox::critical(NULL,"Error",tr("missing imformation"),QMessageBox::Yes);

return;

}

//检测密码是否一致

if(register_pwd_le->text().compare(register_pwd_check_le->text())!=0){

QMessageBox::critical(NULL,"Error",tr("password inconsistent"),QMessageBox::Yes);

return;

}

//查询用户名是否已存在于数据库

QSqlQuery query;

query.exec("select user_name from user where user_name='"+register_name_le->text()+"'");

if(query.next()){

QMessageBox::critical(NULL,"Error",tr("regitered user name"),QMessageBox::Yes);

return;

}

//向user表中插入用户信息

query.exec("insert into user values('"+register_name_le->text()+"','"+register_pwd_check_le->text()+"')");

if(query.isActive()){

QMessageBox::about(0,"mybms",tr("register successful"));

//register_window->close();//注册成功之后将注册窗口关闭

}

else{

QMessageBox::critical(NULL,"Error",tr("注册失败"),QMessageBox::Yes);

return;

}

}


void MainWindow::user_login(){

bool user_login_success_flag=0;//一开始设为零表示登录不成功

QSqlQuery query;



//根据用户输入的用户名，在user表中查询其密码

query.exec("select password from user where user_name ='"+ulogin_name_le->text()+"'");

if(!query.isActive()){

return;

}
//判断密码是否与结果一致

if(query.next()){

QString user_pwd=query.value(0).toString();

if(QString::compare(user_pwd,ulogin_pwd_le->text())==0){

user_login_success_flag=1;

ulogin_window->close();

}

else{

QMessageBox::critical(NULL,"Error","密码错误",QMessageBox::Yes);

return;
}

}

//如果数据库中没有此用户名，给出警告

else{

QMessageBox::critical(NULL,"Error","该用户名不存在",QMessageBox::Yes);

return;

}

goto_ufunction_window(user_login_success_flag);//去到用户界面

}



void MainWindow::ufunction_user_borrow(){

//先检查这本书有没有被当前用户借过


QSqlQuery check_query;

check_query.exec("select book_id,user_name from loan wherebook_id='"+ufunction_borrow_le->text()+"'");

if(check_query.next()){

QString check_name=check_query.value(1).toString();

if(check_name==ulogin_name_le->text()){

QMessageBox::critical(NULL,"Error",tr("每本书只能借一次！"),QMessageBox::Yes);

return;

}

}


QSqlQuery query;

bool find_ok_flag=0;

query.exec("select book_id,book_name from book where book_id='"+ufunction_borrow_le->text()+"'");

if(!query.isActive()){

return;

}

if(query.next()){

QString book_id=query.value(0).toString();

QString book_name=query.value(1).toString();

if(QString::compare(book_id,ufunction_borrow_le->text())==0){

find_ok_flag=1;

query.exec("update book set storage=storage-1 where book_id='"+ufunction_borrow_le->text()+"'");



user_borrow_id_int++;

user_borrow_id=QString::number(user_borrow_id_int,10);



query.exec("insert into loan values('"+user_borrow_id+"','"+book_id+"','"+book_name+"','"+ulogin_name_le->text()+"')");

QMessageBox::about(0,tr("数据库反馈"),tr("借书成功！"));

}

}

else{

QMessageBox::critical(NULL,"Error","借阅失败，请检查您的拼写！",QMessageBox::Yes);

}

}
//用户借书函数
void MainWindow::ufunction_user_return(){

QSqlQuery query;

bool return_ok_flag=0;

query.exec("select loan_id,book_id from loan where book_id='"+ufunction_return_le->text()+"'");

if(!query.isActive()){

return;

}

if(query.next()){

    QString loan_id=query.value(0).toString();

    QString book_id=query.value(1).toString();

    if(QString::compare(book_id,ufunction_return_le->text())==0){

    return_ok_flag=1;

    query.exec("update book set storage=storage+1 where book_id='"+ufunction_return_le->text()+"'");

    query.exec("deletefromloanwhereloan_id='"+loan_id+"'");

    QMessageBox::about(0,tr("数据库反馈"),tr("归还成功，感谢您的使用！"));

    }

    }
}
//用户还书函数
bool MainWindow::createConnection()
{

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

return false;

}

}

