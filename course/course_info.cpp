/*#include "course_info_.h"
#include "course.h"
#include <QMessageBox>


extern Student* stu;

Course_info_::Course_info_(QWidget *parent)
  : QWidget(parent)
{
  //Init();
  //怎么传UGORG类的对象？
}

void Course_info_::Init()
{
  //QLabel course_text_("课程信息");
 course_text=new QLabel("课程信息");
  person_text=new QLabel("选课人数");
  cmdLayout=new QHBoxLayout;
  cmdLayout->addWidget(course_text);
  cmdLayout->addWidget(person_text);
  this->setLayout(cmdLayout);
  //course_text->setText("课程信息");
  //person_text->setText("选课人数");
}


bool Course_info_::Change_BOX()
{
  int temp=stu->course_info_1().size();
  if(temp==0) return false;
  vec_it pd=stu->course_info_1().begin();
  course_text=new QLabel[stu->course_info_1().size()];
  while(temp)
    {
      course_text->setText(*pd);
      dmcLayout->addWidget(course_text);
      pd++;
      course_text++;
      temp--;
    }
  this->setLayout(dmcLayout);
  return true;
}

Course_info_::~Course_info_()
{
 // delete [] course_text;
  delete course_text;
  delete person_text;
  delete cmdLayout;
}
*/
