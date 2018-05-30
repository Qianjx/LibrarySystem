#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QSqlError>
#include <QString>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>
#include <QTextEdit>
#include <QTableView>
#include <QFont>

class QSqlTableModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_query_btn_clicked();//查询
    void on_register_btn_clicked();//用户注册
    void user_register();//用户注册的逻辑
    void user_login();//用户登录的逻辑

    void on_user_login_btn_clicked();//用户登录



    void on_admin_login_btn_clicked();//管理员登陆
    void admin_login();//管理员登录

    /*管理员的槽函数*/
    void afunction_search();
    void afunction_delete();
    void afunction_show_all();
    void afunction_sort();
    void afunction_add();
    void afunction_add_submit();
    void afunction_show_user();
    void afunction_show_loan();

    /*以下都是用户的槽函数*/
    void ufunction_user_borrow();
    void ufunction_user_return();

    void on_notice_btn_clicked();


private:
    Ui::MainWindow *ui;

    /*需要的变量*/

    //常量，用户借书号
    QString user_borrow_id;
    int user_borrow_id_int;

    //数据库相关
    QSqlDatabase db;
    QSqlQuery query;
    QSqlTableModel *model;

    //用户须知相关
/*
尊敬的用户欢迎您使用图书管理系统
1.使用本系统前请先到图书馆前台办理借书证并缴纳押金
2.借书证只限本人使用，不得转让、外借，一经发现将被取消借书资格并不再归还押金
3.每次借书数量不限，但是相同的书只能借一本
4.借书有效期限是30天，从结束当天开始计算
5.如果逾期不还，您将被取消结束资格并没收押金
6.如有任何问题，请联系：
*/
    QWidget *notice_window;
    QLabel *notice_head;
    QLabel *notice_line1;
    QLabel *notice_line2;
    QLabel *notice_line3;
    QLabel *notice_line4;
    QLabel *notice_line5;
    QLabel *notice_line6;

    QVBoxLayout *notice_vblo;

    //用户注册窗口
    QWidget *register_window;
    QLabel *register_notice_lb;
    QLabel *register_name_lb;
    QLabel *register_pwd_lb;
    QLabel *register_pwd_check_lb;
    QLineEdit *register_name_le;
    QLineEdit *register_pwd_le;
    QLineEdit *register_pwd_check_le;
    QPushButton *register_ok_btn;
    QGridLayout *register_grid_lo;

    //用户登录窗口
    QWidget *ulogin_window;
    QLabel *ulogin_name_lb;
    QLabel *ulogin_pwd_lb;
    QLineEdit *ulogin_name_le;
    QLineEdit *ulogin_pwd_le;
    QPushButton *ulogin_ok_btn;
    QGridLayout *ulogin_grid_lo;

    //用户功能界面
    QWidget *ufunction_window;
    QTextEdit *ufunction_warning_txtedit;//感觉叫warning很爽啊
    QLabel *ufunction_borrow_lb;
    QLabel *ufunction_return_lb;
    QLineEdit *ufunction_borrow_le;
    QLineEdit *ufunction_return_le;
    QPushButton *ufunction_borrow_btn;
    QPushButton *ufunction_return_btn;

    QVBoxLayout *ufunction_vblo_main;
    QHBoxLayout *ufunction_hblo_bottom;

    //管理员登录窗口
    QWidget *alogin_window;
    QLabel *alogin_welcome_lb;
    QLabel *alogin_n_lb;//用来占位
    QLabel *alogin_name_lb;
    QLabel *alogin_pwd_lb;
    QLineEdit *alogin_name_le;
    QLineEdit *alogin_pwd_le;
    QPushButton *alogin_ok_btn;
    QGridLayout *alogin_grid_lo;

    //管理员功能界面(实现书籍添加、用户管理)
    QWidget *afunction_window;
    QPushButton *afunction_add_btn;//书籍添加
    QPushButton *afunction_add_ok_btn;//确认添加按钮
    QPushButton *afunction_delete_btn;//删除用户
    QPushButton *afunction_search_btn;//搜索图书
    QPushButton *afunction_show_all_btn;//显示所有书籍
    QPushButton *afunction_show_order_btn;//库存量排序（降序）
    QPushButton *afunction_show_user_btn;//显示数据库中的用户记录
    QPushButton *afunction_show_loan_btn;//显示借阅表
    QLineEdit *afunction_delete_le;
    QLineEdit *afunction_search_le;

    QTableView *afunction_tableview;
    QSqlTableModel *afunction_tablemodel;

    QVBoxLayout *afunction_vblo_main;
    QHBoxLayout *afunction_hblo_sub1;
    QHBoxLayout *afunction_hblo_sub2;
    QHBoxLayout *afunction_hblo_sub3;
    QVBoxLayout *afunction_vblo_combine123;


    /*函数*/
    bool createConnection();//建立数据库连接
    void goto_ufunction_window(bool flag);//切换到用户界面
    void goto_afunction_window(bool flag);//切换到管理员界面
};

#endif // MAINWINDOW_H
