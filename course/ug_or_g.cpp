#include "ug_or_g.h"
#include "ui_ug_or_g.h"
#include "gui_course.h"
#include "Filespace.h"
Student* stu;
extern Course* cou_rse;
Ug_or_g::Ug_or_g(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Ug_or_g)
{
  ui->setupUi(this);
}

Ug_or_g::~Ug_or_g()
{
  //delete stu;
  delete ui;
}


void Ug_or_g::on_btn_UG_clicked()
{
  stu=new UGstudent(File::stu_id,File::stu_passwd);
  if(stu->confirm_())
    {
    select_mode.show();
   cou_rse->_cal_sum_all_course();
    }
  this->close();
}

void Ug_or_g::on_btn_G_clicked()
{
 // stu_id = File::file_read(path_id);

  //stu_name = File::file_read(path_name);
 stu=new Gstudent(File::stu_id,File::stu_passwd);
 if(stu->confirm_())
  {select_mode.show();
  cou_rse->_cal_sum_all_course();}
 this->close();
}
