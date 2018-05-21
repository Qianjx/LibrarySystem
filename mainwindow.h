#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QBoxLayout>


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

    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
