#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"
#include <QFile>
#include <QTextStream>

using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList titulos;
    setWindowTitle("Картотека");
    ui->tableWidget->setColumnCount(6);
    titulos<<"Фамилия"<<"Имя"<<"Отчество"<<"Год рождения"<<"Рост"<<"Вес";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_add_clicked()
{
    int res;
    QString firstname;
    QString name;
    QString lastname;
    QString year;
    QString rost;
    QString ves;
    Dialog pd(this);
    pd.setWindowTitle("Картотека");
    res = pd.exec();
    if (res==QDialog::Rejected)
        return;
    firstname=pd.firstname();
    name=pd.name();
    lastname=pd.lastname();
    year=pd.year();
    rost=pd.rost();
    ves=pd.ves();
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,FIRSTNAME, new QTableWidgetItem(firstname));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,NAME, new QTableWidgetItem(name));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,LASTNAME, new QTableWidgetItem(lastname));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,YEAR, new QTableWidgetItem(year));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,ROST, new QTableWidgetItem(rost));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,VES, new QTableWidgetItem(ves));
}


void Widget::on_delete_2_clicked()
{
    ui->tableWidget->removeRow(row);
}



void Widget::on_tableWidget_clicked(const QModelIndex &index)
{
    row=index.row();
}




void Widget::on_save_clicked()
{
    QFile file("D:\\QT\\file.txt");
    if (file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        //QDataStream stream(&file);
        QTextStream stream(&file);
        int row(ui->tableWidget->rowCount()),column(ui->tableWidget->columnCount());
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < column; ++j)
                //ui->tableWidget->item(i,j)->write(stream);
            {
                stream<<(ui->tableWidget->item(i,j))->text()<<"\n";
            }
        file.close();
    }

}


void Widget::process_line(QString line)
{
    static int row = 0;
    QStringList ss = line.split('\t');
    if(ui->tableWidget->rowCount() < row/6+1)
        ui->tableWidget->setRowCount(row/6+1);
    if(ui->tableWidget->columnCount() < ss.size())
        ui->tableWidget->setColumnCount( ss.size());
    for( int column = 0; column < ss.size(); column++)
    {
        QTableWidgetItem *newItem = new QTableWidgetItem( ss.at(column) );
        ui->tableWidget->setItem(column, row, newItem);

    }
    row++;
}

void Widget::on_vivod_clicked()
{
    QFile file("D:\\QT\\file.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    while (!file.atEnd()) {
        QString line = file.readLine();
        line.removeLast();
        process_line(line);
    }

}

