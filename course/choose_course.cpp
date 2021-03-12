#include "choose_course.h"
#include "ui_choose_course.h"
#include "course.h"


extern Student* stu;
extern Course* cou_rse;

Choose_course::Choose_course(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Choose_course)
{
  ui->setupUi(this);
  //QObject::connect(pb,&QPushButton::clicked,&temp,&QMessageBox::show);
}

int Choose_course::check_btn()
{
  test=new QButtonGroup(this);
  test->addButton(ui->English,0);
  test->addButton(ui->Mathematics,1);
  test->addButton(ui->Physics,2);
  test->addButton(ui->Politics,3);
  test->addButton(ui->Programming,4);
  test->addButton(ui->Data_structure,5);
  test->addButton(ui->Computer_theory,6);
  test->addButton(ui->Assembly_language,7);
  test->addButton(ui->OOP_programming,8);
  test->addButton(ui->Complie_fud,9);
  test->addButton(ui->Microcomputer,10);
  test->addButton(ui->Comp_networks,11);
  return test->checkedId();
}


Choose_course::~Choose_course()
{
  //delete test;
  delete ui;
}

void Choose_course::on_Confirm_course_clicked()
{
    switch(check_btn()){
      case 0:stu->add_course(cou_rse->find_course("英语口语"),cou_rse);
              break;//没触发
      case 1:stu->add_course(cou_rse->find_course("高等数学"),cou_rse);
              break;
      case 2:stu->add_course(cou_rse->find_course("大学物理"),cou_rse);
              break;
      case 3:stu->add_course(cou_rse->find_course("政治经济学"),cou_rse);
              break;
      case 4:stu->add_course(cou_rse->find_course("程序设计"),cou_rse);
              break;
      case 5:stu->add_course(cou_rse->find_course("数据结构"),cou_rse);
              break;
      case 6:stu->add_course(cou_rse->find_course("计算机原理"),cou_rse);
              break;
      case 7:stu->add_course(cou_rse->find_course("汇编语言"),cou_rse);
              break;
      case 8:stu->add_course(cou_rse->find_course("OOP程序设计"),cou_rse);
              break;
      case 9:stu->add_course(cou_rse->find_course("编译原理"),cou_rse);
              break;
      case 10:stu->add_course(cou_rse->find_course("微机原理"),cou_rse);
              break;
      case 11:stu->add_course(cou_rse->find_course("计算机网络"),cou_rse);
              break;

      }
}

void Choose_course::on_back_2_clicked()
{
    this->close();
}
