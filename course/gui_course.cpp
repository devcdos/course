#include "gui_course.h"
#include "ui_gui_course.h"
#include "Filespace.h"
using File::stu_id;
using File::stu_passwd;

Course* cou_rse=new Course();
extern Student* stu;
GUI_course::GUI_course(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GUI_course)
{
    ui->setupUi(this);

}


GUI_course::~GUI_course()
{
    delete stu;
    delete cou_rse;
    delete ui;
}


void GUI_course::on_btn_cancel_clicked()
{
    this->close();
}

void GUI_course::on_btn_log_clicked()
{
  File::stu_id=ui->lineEdit_stu_id->text();
  File::stu_passwd=ui->lineEdit_pass_wd->text();
  dia_log1.show();
}

