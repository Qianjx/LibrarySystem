#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createConnection();
    user_borrow_id_int=0;
    user_borrow_id='0';

    model=new QSqlTableModel(this);
    model->setTable("book");
    ui->show_tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
    db.removeDatabase("mybms");
}


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
                                        "3.不得损坏图书"
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

ufunction_window->resize(400,400);

ufunction_window->show();



//连接槽，负责借书、还书

connect(ufunction_borrow_btn,SIGNAL(clicked()),this,SLOT(ufunction_user_borrow()));

connect(ufunction_return_btn,SIGNAL(clicked()),this,SLOT(ufunction_user_return()));

}

}
//用户界面
void MainWindow::goto_afunction_window(bool flag){

if(flag==0)

return;

else{

//必要的初始化

    QWidget* afunction_window;

    QTextEdit* afunction_warning_txtedit;

    QLabel* afunction_borrow_lb;

    QLabel* afunction_return_lb;

    QLineEdit* afunction_borrow_le;

    QLineEdit* afunction_return_le;

    QPushButton* afunction_borrow_btn;

    QPushButton* afunction_return_btn;

    QVBoxLayout* afunction_vblo_main;

    QHBoxLayout* afunction_hblo_bottom;

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

afunction_show_all_btn=new QPushButton(tr("所有图书"));
//显示所有书籍

afunction_show_order_btn=new QPushButton(tr("按顺序排列"));

afunction_show_user_btn=new QPushButton(tr("所有用户"));

afunction_show_loan_btn=new QPushButton(tr("所有借阅"));

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
//管理员界面
void MainWindow::on_admin_login_btn_clicked()
{
    //必要的初始化
    alogin_window=new QWidget();
    alogin_welcome_lb=new QLabel;
    alogin_n_lb=new QLabel;
    alogin_name_lb=new QLabel;
    alogin_pwd_lb=new QLabel;
    alogin_name_le=new QLineEdit;
    alogin_pwd_le=new QLineEdit;
    alogin_ok_btn=new QPushButton(tr("登录"));
    alogin_grid_lo=new QGridLayout;

    alogin_window->setWindowTitle(tr("管理员登录对话框"));
    alogin_welcome_lb->setText(tr("嘿嘿嘿，欢迎管理员大大(●'◡'●)ﾉ♥"));
    alogin_n_lb->setText("\n");
    alogin_name_lb->setText(tr("请输入管理员名称:"));
    alogin_pwd_lb->setText(tr("请输入密码:"));

    alogin_pwd_le->setEchoMode(QLineEdit::Password);

    alogin_grid_lo->addWidget(alogin_welcome_lb,0,0,Qt::AlignLeft);
    alogin_grid_lo->addWidget(alogin_n_lb,0,1,Qt::AlignLeft);
    alogin_grid_lo->addWidget(alogin_name_lb,1,0,Qt::AlignLeft);
    alogin_grid_lo->addWidget(alogin_name_le,1,1,Qt::AlignHCenter);
    alogin_grid_lo->addWidget(alogin_pwd_lb,2,0,Qt::AlignLeft);
    alogin_grid_lo->addWidget(alogin_pwd_le,2,1,Qt::AlignHCenter);
    alogin_grid_lo->addWidget(alogin_ok_btn,3,2,Qt::AlignRight);

    alogin_window->setLayout(alogin_grid_lo);
    alogin_window->resize(400,300);
    alogin_window->show();

    connect(alogin_ok_btn,SIGNAL(clicked()),this,SLOT(admin_login()));
}
//点击管理员登录按钮
void MainWindow::admin_login(){
    bool admin_login_success_flag=0;
    QSqlQuery query;

    //根据用户输入的用户名，在manager表中查询其密码
    query.exec("select password from manager where manager_name = '"+alogin_name_le->text()+"'");
    if(!query.isActive()){
        return;
    }

    //判断密码是否与结果一致
    if(query.next()){
        QString admin_pwd = query.value(0).toString();
        if(QString::compare(admin_pwd,alogin_pwd_le->text())==0){
            admin_login_success_flag=1;
            alogin_window->close();
        }
        else{
            QMessageBox::critical(NULL, "Error", "密码错误",QMessageBox::Yes);
            return;
        }
    }

    //如果数据库中没有此用户名，给出警告
    else{
        QMessageBox::critical(NULL, "Error","管理员不存在",QMessageBox::Yes);
        return;
    }
    goto_afunction_window(admin_login_success_flag);//去到管理员界面
}
//管理员登录函数
//查询图书
void MainWindow::afunction_search()
{
    QString book_name=afunction_search_le->text();
    afunction_tablemodel->setFilter(QString("book_name='%1'").arg(book_name));
    afunction_tablemodel->select();
}
//删除用户
void MainWindow::afunction_delete(){
    int cur_row=afunction_tableview->currentIndex().row();
    int ok=QMessageBox::warning(this,tr("删除这个用户"),tr("您确定删除当前行吗？"),
                                QMessageBox::Yes,QMessageBox::No);
    if(ok==QMessageBox::Yes){
        afunction_tablemodel->removeRow(cur_row);
        afunction_tablemodel->submitAll();
    }
    else
        return;
}
//显示所有图书
void MainWindow::afunction_show_all(){
    afunction_tablemodel->setTable("book");
    afunction_tablemodel->select();
}
//显示user表
void MainWindow::afunction_show_user(){
    afunction_tablemodel->setTable("user");
    afunction_tablemodel->select();
}
//显示loan表
void MainWindow::afunction_show_loan(){
    afunction_tablemodel->setTable("loan");
    afunction_tablemodel->select();
}
//添加书籍
void MainWindow::afunction_add(){
    int row_num=afunction_tablemodel->rowCount();
    QString book_id;
    afunction_tablemodel->insertRow(row_num);
    afunction_tablemodel->setData(afunction_tablemodel->index(row_num,0),book_id);
    //afunction_tablemodel->submitAll();
}
//提交添加书籍的修改
void MainWindow::afunction_add_submit(){
    afunction_tablemodel->database().transaction();
    if(afunction_tablemodel->submitAll()){
        if(afunction_tablemodel->database().commit())
            QMessageBox::information(this,tr("数据库反馈"),tr("书籍入库成功"));
            QMessageBox::about(0,"mybms",tr("书籍入库成功！"));
    }
    else{
        afunction_tablemodel->database().rollback();
        QMessageBox::warning(this,tr("数据库反馈"),
                             tr("发生错误:%1").arg(afunction_tablemodel->lastError().text()),
                             QMessageBox::Ok);
    }

}
//排序
void MainWindow::afunction_sort(){
    afunction_tablemodel->setSort(5,Qt::AscendingOrder);
    afunction_tablemodel->select();
}

void MainWindow::on_query_btn_clicked(){
    QString book_name=ui->name_lineEdit->text();
    model->setFilter(QString("book_name='%1'").arg(book_name));
    model->select();
}
//点击查询按钮
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

/*
尊敬的用户欢迎您使用图书管理系统
1.使用本系统前请先到图书馆前台办理借书证并缴纳押金
2.借书证只限本人使用，不得转让、外借，一经发现将被取消借书资格并不再归还押金
3.每次借书数量不限，但是相同的书只能借一本
4.借书有效期限是30天，从结束当天开始计算
5.如果逾期不还，您将被取消结束资格并没收押金
6.如有任何问题，请联系：
*/

notice_line1->setText(tr("1.使用本系统前请先到图书馆前台办理借书证并缴纳押金"));

QFont font1(0,15,0);

notice_line1->setFont(font1);

notice_line2->setText(tr("2.借书证只限本人使用，不得转让、外借，一经发现将被取消借书资格并不再归还押金"));

QFont font2(0,15,0);

notice_line2->setFont(font2);

notice_line3->setText(tr("3.借书有效期限是30天，从结束当天开始计算,超过会取消您的借书资格"));

QFont font3(0,15,0);

notice_line3->setFont(font3);

//notice_line4->setText(tr("4.。。。\n"));

//QFont font4(0,15,0);

//notice_line4->setFont(font4);

//notice_line5->setText(tr("5.。。。\n"));

//QFont font5(0,15,0);

//notice_line5->setFont(font5);

notice_line6->setText(tr("如有任何问题，请联系：PB15151800 钱劲翔\n"));

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
//点击注意事项
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
//用户注册
void MainWindow::on_register_btn_clicked()
{
    //必要的初始化
    register_window=new QWidget();
    register_notice_lb=new QLabel;
    register_name_lb=new QLabel;
    register_pwd_lb=new QLabel;
    register_pwd_check_lb=new QLabel;
    register_name_le=new QLineEdit;
    register_pwd_le=new QLineEdit;
    register_pwd_check_le=new QLineEdit;
    register_ok_btn=new QPushButton(tr("确定"));
    register_grid_lo=new QGridLayout;

    //文字提示
    register_window->setWindowTitle(tr("register"));
    register_notice_lb->setText(tr("only available after register^_^"));
    register_name_lb->setText(tr("username:"));
    register_pwd_lb->setText(tr("password:"));
    register_pwd_check_lb->setText(tr("password again:"));

    register_pwd_le->setEchoMode(QLineEdit::Password);
    register_pwd_check_le->setEchoMode(QLineEdit::Password);

    //采用网格布局
    register_grid_lo->addWidget(register_notice_lb,0,0,Qt::AlignHCenter);
    register_grid_lo->addWidget(register_name_lb,1,0,Qt::AlignHCenter);
    register_grid_lo->addWidget(register_name_le,1,1,Qt::AlignHCenter);
    register_grid_lo->addWidget(register_pwd_lb,2,0,Qt::AlignHCenter);
    register_grid_lo->addWidget(register_pwd_le,2,1,Qt::AlignHCenter);
    register_grid_lo->addWidget(register_pwd_check_lb,3,0,Qt::AlignHCenter);
    register_grid_lo->addWidget(register_pwd_check_le,3,1,Qt::AlignHCenter);
    register_grid_lo->addWidget(register_ok_btn,4,0,Qt::AlignRight);

    register_window->setLayout(register_grid_lo);
    register_window->resize(400,300);
    register_window->show();

    connect(register_ok_btn,SIGNAL(clicked()),this,SLOT(user_register()));
}
//点击注册按钮
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

QMessageBox::critical(NULL,"Error","用户名不存在",QMessageBox::Yes);

return;

}

goto_ufunction_window(user_login_success_flag);//去到用户界面

}
//用户用户登录函数
void MainWindow::on_user_login_btn_clicked(){

    //必要的初始化
    ulogin_window=new QWidget();
    ulogin_name_lb=new QLabel;
    ulogin_pwd_lb=new QLabel;
    ulogin_name_le=new QLineEdit;
    ulogin_pwd_le=new QLineEdit;
    ulogin_ok_btn=new QPushButton(tr("登录"));
    ulogin_grid_lo=new QGridLayout;

    ulogin_window->setWindowTitle(tr("login in welcome"));
    ulogin_name_lb->setText(tr("username:"));
    ulogin_pwd_lb->setText(tr("password:"));

    ulogin_pwd_le->setEchoMode(QLineEdit::Password);

    ulogin_grid_lo->addWidget(ulogin_name_lb,0,0,Qt::AlignHCenter);
    ulogin_grid_lo->addWidget(ulogin_name_le,0,1,Qt::AlignHCenter);
    ulogin_grid_lo->addWidget(ulogin_pwd_lb,1,0,Qt::AlignHCenter);
    ulogin_grid_lo->addWidget(ulogin_pwd_le,1,1,Qt::AlignHCenter);
    ulogin_grid_lo->addWidget(ulogin_ok_btn,2,2,Qt::AlignRight);

    ulogin_window->setLayout(ulogin_grid_lo);
    ulogin_window->resize(400,300);
    ulogin_window->show();

    connect(ulogin_ok_btn,SIGNAL(clicked()),this,SLOT(user_login()));

}
//点击登录按钮
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

//QMessageBox::about(NULL,tr("数据库反馈"),tr("借书成功"));
QMessageBox::about(0,tr("feedback from database"),tr("loan success"));
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

    //QMessageBox::about(NULL,tr("数据库反馈"),tr("归还成功，感谢您的使用"));
    QMessageBox::about(0,tr("feedback from database"),tr("return successful"));

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
db.setUserName("root");
//设置密码名
db.setPassword("740832Qjx");
//设置端口
db.setPort(3306);

if(!db.open())
{
QMessageBox::critical(0,QObject::tr("error"),db.lastError().text());
return false;

}
return true;
}
//创建mysql连接

