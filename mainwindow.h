#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QBoxLayout>
/*
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QtSql>
#include<QSqlTableModel>
#include<QSqlRelationalTableModel>
#include<QSqlError>
*/
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void goto_ufunction_window(bool flag);

    QWidget* ufunction_window;

    QTextEdit* ufunction_warning_txtedit;

    QLabel* ufunction_borrow_lb;

    QLabel* ufunction_return_lb;

    QLineEdit* ufunction_borrow_le;

    QLineEdit* ufunction_return_le;

    QPushButton* ufunction_borrow_btn;

    QPushButton* ufunction_return_btn;

    QVBoxLayout* ufunction_vblo_main;

    QHBoxLayout* ufunction_hblo_bottom;

    //   以上是用户界面的UI

    void goto_afunction_window(bool flag);

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

    // 管理员界面UI


    //bool MainWindow::createConnection();

    // Qsqldatabase db；

    // sql相关

    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
