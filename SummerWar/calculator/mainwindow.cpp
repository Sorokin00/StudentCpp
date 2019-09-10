#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(print_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(print_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(print_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(print_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(print_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(print_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(print_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(print_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(print_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(print_numbers()));

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->pushButton_multiplication, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->pushButton_division, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->pushButton_radix, SIGNAL(clicked()), this, SLOT(print_operations()));

    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(triganometry()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(triganometry()));
    connect(ui->pushButton_tg, SIGNAL(clicked()), this, SLOT(triganometry()));
    connect(ui->pushButton_ctg, SIGNAL(clicked()), this, SLOT(triganometry()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void push(double *&old_array, int &size,  double value)
{
    double *new_array = new double[size + 1];
    for (int i = 0; i < size; i++)
        new_array[i] = old_array[i];
    new_array[size] = value;
    size++;
    delete[] old_array;
    old_array = new_array;
}

void array_zeroing(double *&old_array)
{
    double *new_array = new double[1];
    delete[] old_array;
    old_array = new_array;
}

void calculation(double chisla[], double operations[], int &chisla_size, int &operations_size, int operation_index, int operation_number)
{
    switch (operation_index)
    {
    case 1:
        chisla[operation_number] = chisla[operation_number] + chisla[operation_number + 1];
        break;
    case 2:
        chisla[operation_number] = chisla[operation_number] - chisla[operation_number + 1];
        break;
    case 3:
        chisla[operation_number] = chisla[operation_number] * chisla[operation_number + 1];
        break;
    case 4:
        chisla[operation_number] = chisla[operation_number] / chisla[operation_number + 1];
        break;
    case 5:
        chisla[operation_number] = pow(chisla[operation_number] , chisla[operation_number + 1]);
        break;
    case 6:

        chisla[operation_number] = pow(chisla[operation_number + 1] , 1 / chisla[operation_number]);
        break;
    }

    operations[operation_number] = operations[operation_number + 1];
    operation_number++;
    for (int i = operation_number; i < operations_size; i++)
        operations[i] = operations[i + 1];
    for (int i = operation_number; i < chisla_size; i++)
        chisla[i] = chisla[i + 1];
    chisla_size--;
}

void MainWindow::priority()
{
    double pi= 3.14159265;
    for (int i = 0; i < sin_size; i++)
    {
        int position = sin_array[i];
        chisla[position]=sin(chisla[position] * pi / 180);
    }
    for (int i = 0; i < cos_size; i++)
    {
        int position = cos_array[i];
        chisla[position]=cos(chisla[position] * pi / 180);
    }
    for (int i = 0; i < tg_size; i++)
    {
        int position = tg_array[i];
        chisla[position]=tan(chisla[position] * pi / 180);
    }
    for (int i = 0; i < ctg_size; i++)
    {
        int position = ctg_array[i];
        chisla[position]=1 / tan(chisla[position] * pi / 180);
    }

    for (int i = 0; i < chisla_size; i++)
    {
        if (operations[i] == 5 || operations[i] == 6)
        {
            calculation(chisla, operations, chisla_size, operations_size, operations[i], i);
            i--;
        }
    }
    for (int i = 0; i < chisla_size; i++)
    {
        if (operations[i] == 3 || operations[i] ==  4)
        {
            calculation(chisla, operations, chisla_size, operations_size, operations[i], i);
            i--;
        }
    }
    for (int i = 0; i < chisla_size; i++)
    {
        if (operations[i] == 1 || operations[i] == 2)
        {
            calculation(chisla, operations, chisla_size, operations_size, operations[i], i);
            i--;
        }
    }
}

void MainWindow::print_pow(QString value)
{
    QString print_pow_value;
    if (value=="0")
        print_pow_value="⁰";
    else if (value=="1")
        print_pow_value="¹";
    else if (value=="2")
        print_pow_value="²";
    else if (value=="3")
        print_pow_value="³";
    else if (value=="4")
        print_pow_value="⁴";
    else if (value=="5")
        print_pow_value="⁵";
    else if (value=="6")
        print_pow_value="⁶";
    else if (value=="7")
        print_pow_value="⁷";
    else if (value=="8")
        print_pow_value="⁸";
    else if (value=="9")
        print_pow_value="⁹";
    ui->show_result->setText(ui->show_result->text()+print_pow_value);
}

void MainWindow::print_numbers()
{
    if(dot==0)
        dot = 1;
    op = 1;
    trg=0;
    if (save_button==nullptr)
    {
        QPushButton *button = (QPushButton*) sender();
        number=number+button->text();
        last=button->text();
        if (pow==1)
        { print_pow(button->text());}
        else
        { ui->show_result->setText(ui->show_result->text()+button->text());}
    }
    else
    {
        number=number+save_button;
        last=save_button;
        if (pow==1)
        {print_pow(save_button);}
        else
        {ui->show_result->setText(ui->show_result->text()+save_button);}
    }
    last_type="number";    
}

void MainWindow::print_operations()
{
    if(op==1)
    {
        op = 0;
        dot = 0;
        pow=0;
        trg=1;
        save=number;
        numbers_buffer = number.toDouble();
        push(chisla, chisla_size, numbers_buffer);
        numbers_buffer=0;
        number=nullptr;
        QString operation;
        if (save_button==nullptr)
        {
            QPushButton *button = (QPushButton*) sender();
            operation = button->text();
        }
        else
        {
            operation = save_button;
        }
        double index;
        if (operation=='+')
            index = 1;
        else if (operation=="-")
            index = 2;
        else if (operation=="*")
            index = 3;
        else if (operation=="/")
            index = 4;
        else if (operation=="√")
            index = 6;
        last_type="operation";
        last=operation;
        ui->show_result->setText(ui->show_result->text()+operation);
        push(operations, operations_size, index);
    }
}

void MainWindow::on_pushButton_result_clicked()
{
    numbers_buffer = number.toDouble();
    push(chisla, chisla_size, numbers_buffer);
    priority();
    QString line;
    line = QString::number(chisla[0]);
    ui->show_result->setText(line);
    double save_first = chisla[0];
    number=QString::number(save_first);
    array_zeroing(chisla);
    array_zeroing(operations);
    array_zeroing(sin_array);
    array_zeroing(cos_array);
    array_zeroing(tg_array);
    array_zeroing(ctg_array);
    operations_size = 0;
    chisla_size = 0;
    sin_size = 0;
    cos_size = 0;
    tg_size = 0;
    ctg_size = 0;
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(dot==1)
    {
        number=number+".";
        last_type="dot";
        last=".";
        ui->show_result->setText(ui->show_result->text()+".");
        dot = 2;
        op = 0;
    }
}

void MainWindow::triganometry()
{
    if (trg==1)
    {
        QPushButton *button = (QPushButton*) sender();
        trg=0;
        QString operation;
        operation = button->text();
        last_type="triganometry";
        last=operation;
        double position = chisla_size;
        if (operation=="sin")
        {
            push(sin_array, sin_size, position);
        } else if (operation=="cos")
        {
            push(cos_array, cos_size, position);
        } else if (operation=="tg")
        {
            push(tg_array, tg_size, position);
        } else if (operation=="ctg")
        {
            push(ctg_array, ctg_size, position);
        }
        ui->show_result->setText(ui->show_result->text()+operation);
    }
}

void MainWindow::on_pushButton_back_clicked()
{
    ui->show_result->setText(ui->show_result->text().remove(last));
    if (last_type=="number")
    {
        number=number.remove(last);
    } else if (last_type=="operation")
    {
        op=1;
        trg=0;
        number=save;
        chisla_size--;
        operations_size--;
    } else if (last_type=="pow")
    {
        op=1;
        trg=0;
        pow=0;
        number=save;
        chisla_size--;
        operations_size--;
    } else if (last_type=="dot")
    {
        op=1;
        number=number.remove(last);
    }  else if (last_type=="triganometry")
    {
        trg=1;
        if (last=="sin")
        {
            sin_size--;
        } else if (last=="cos")
        {
            cos_size--;
        } else if (last=="tg")
        {
            tg_size--;
        } else if (last=="ctg")
        {
            ctg_size--;
        }
    }
}

void MainWindow::on_pushButton_delete_all_clicked()
{
    ui->show_result->setText(nullptr);
    number=nullptr;
    array_zeroing(chisla);
    array_zeroing(operations);
    array_zeroing(sin_array);
    array_zeroing(cos_array);
    array_zeroing(tg_array);
    array_zeroing(ctg_array);
    operations_size = 0;
    chisla_size = 0;
    sin_size = 0;
    cos_size = 0;
    tg_size = 0;
    ctg_size = 0;
}

void MainWindow:: keyPressEvent(QKeyEvent *event)
{
    switch (event -> key())
    {
    case Qt::Key_Control:
        ctrl = 2;
        break;
    case Qt::Key_0:
        save_button="0";
        print_numbers();
        break;
    case Qt::Key_1:
        save_button="1";
        print_numbers();
        break;
    case Qt::Key_2:
        save_button="2";
        print_numbers();
        break;
    case Qt::Key_3:
        save_button="3";
        print_numbers();
        break;
    case Qt::Key_4:
        save_button="4";
        print_numbers();
        break;
    case Qt::Key_5:
        save_button="5";
        print_numbers();
        break;
    case Qt::Key_6:
        save_button="6";
        print_numbers();
        break;
    case Qt::Key_7:
        save_button="7";
        print_numbers();
        break;
    case Qt::Key_8:
        save_button="8";
        print_numbers();
        break;
    case Qt::Key_9:
        save_button="9";
        print_numbers();
        break;
    case Qt::Key_Plus:
        save_button="+";
        print_operations();
        break;
    case Qt::Key_Minus:
        save_button="-";
        print_operations();
        break;
    case Qt::Key_multiply:
        save_button="*";
        print_operations();
        break;
    case Qt::Key_division:
        save_button="/";
        print_operations();
        break;
    case Qt::Key_Z:
        if (ctrl==1)
        {
            ctrl = false;
            on_pushButton_back_clicked();
        }
        break;
    case Qt::Key_Delete:
        on_pushButton_delete_all_clicked();
        break;
    case Qt::Key_Enter:
        on_pushButton_result_clicked();
        break;
    }
    ctrl--;
    save_button=nullptr;
}

void MainWindow::on_pushButton_pow_clicked()
{
    if (op==1)
    {
        op=0;
        dot = 0;
        trg=1;
        pow=1;
        numbers_buffer = number.toDouble();
        push(chisla, chisla_size, numbers_buffer);
        numbers_buffer=0;
        number=nullptr;
        push(operations, operations_size, 5);
        last_type="pow";
        last=5;
    }
}
