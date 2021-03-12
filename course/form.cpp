#include "form.h"
#include "ui_form.h"
#include "course.h"


extern Student* stu;
extern Course* cou_rse;
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_choose_course_clicked()
{
    w2.show();
}

void Form::on_back_1_clicked()
{
    this->close();
}

void Form::on_show_credit_clicked()
{
    QMessageBox::information(NULL,"提示", QString::number(stu->show_credit()));
}

void Form::on_show_tuition_clicked()
{
    QMessageBox::information(NULL, "提示", QString::number(stu->show_tuition()));
}


void Form::on_my_info_clicked()
{
    QMessageBox::information(NULL, "提示",stu->show_teacher_info());
}

void Form::on_course_info_clicked()
{

  //connect(stu,SIGNAL(Change_box()),&w3,SLOT(Change_BOX()));
  //w3.show();
 // emit stu->Chang_box();
  stu->_display_course(cou_rse);
}

/*Form* Form::return_this()
{
  return this;
}*/
