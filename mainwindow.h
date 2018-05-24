#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QBoxLayout>
#include <QTableView>
#include <QMessageBox>

#include<QSqlDatabase>
#include<QSqlQuery>
#include<QtSql>
#include<QSqlTableModel>
#include<QSqlRelationalTableModel>
#include<QSqlError>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void goto_ufunction_window(bool flag);
    //用户界面函数
    void user_login();
    //用户登录函数
    void ufunction_user_borrow();
    //用户借书函数
    void ufunction_user_return();
    //用户还书函数
    QTextEdit* ulogin_name_le,*u_login_pwd_le;
    //用户登录用的密码和用户名

    void goto_afunction_window(bool flag);
    // 管理员界面
\
    QSqlDatabase db;

    QSqlTableModel* afunction_tablemodel;

    bool createConnection();
    // sql相关

    void user_register();
    //用户注册函数
    QLineEdit* register_name_le,* register_pwd_le,*register_pwd_check_le;
    // 用户注册相关参数

    void on_notice_btn_clicked();
    //用户须知界面

    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
