#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}
QString  Dialog::firstname() const
{
    return ui->fname->text();
}
QString Dialog::name() const
{
    return ui->name->text();
}
QString Dialog::lastname() const
{
    return ui->lname->text();
}
QString Dialog::year() const
{
    return ui->year->text();
}
QString Dialog::rost() const
{
    return ui->rost->text();
}
QString Dialog::ves() const
{
    return ui->ves->text();
}

