#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int  operations_size = 0, chisla_size = 0, sin_size = 0, cos_size = 0, tg_size = 0, ctg_size = 0;
    double *chisla = new double[1];
    double *operations = new double[1];
    double *sin_array = new double [1];
    double *cos_array = new double [1];
    double *tg_array = new double [1];
    double *ctg_array = new double [1];
    double numbers_buffer;
    QString number=nullptr, last=nullptr, last_type=nullptr, save=nullptr, save_button=nullptr;
    bool op = 0, pow = 0, trg = 1;
    int dot = 0, ctrl = 0;

private:
    Ui::MainWindow *ui;

private slots:
    void print_numbers();
    void print_operations();
    void priority();
    void on_pushButton_result_clicked();
    void on_pushButton_dot_clicked();
    void triganometry();
    void on_pushButton_back_clicked();
    void on_pushButton_delete_all_clicked();
    void keyPressEvent(QKeyEvent *event);
    void on_pushButton_pow_clicked();
    void print_pow(QString value);
};

#endif // MAINWINDOW_H
