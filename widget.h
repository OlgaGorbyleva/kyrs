#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QDialog>
#include <QSpinBox>
#include <QTextEdit>
#include <QIODevice>
#include <QTextStream>
QT_BEGIN_NAMESPACE

namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_add_clicked();

    void on_delete_2_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_save_clicked();

    void on_vivod_clicked();

    void process_line(QString line);

private:

    Ui::Widget *ui;
    int row;
    enum Columna
    {
        FIRSTNAME,NAME,LASTNAME,YEAR,ROST,VES
    };
};
#endif // WIDGET_H
