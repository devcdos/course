#include"course.h"
#include <QDebug>
#include <QMessageBox>


  Student::Student(QString &a,QString &b)
{	
	_all_credit=0;
	tui_tion=0;
	_stu_id=a;
	name=b;
	QTextCodec *codec=QTextCodec::codecForName("GBK");
	QByteArray temp;
	QString temp1;
	QString temp2;
	QFile is("D:\\jisuanjizuoye\\QT4\\course\\233.txt");
	if(!is.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl<<is.exists();
    }
    while (!is.atEnd()) {
            temp=is.readLine();
            temp1=codec->toUnicode(temp.mid(10,7));
            temp2=codec->toUnicode(temp.mid(18));
            stu_info.insert(temp1,temp2);
}

  }
  Student::Student()
    {
            _all_credit=0;
            tui_tion=0;
            _stu_id=name="failed";
            stu_info.insert(_stu_id,name);
    }

bool Student::_display_course(Course* c)
{

        vec_it pd1=c->save_course.begin();
        if(_course.size()!=0)
          c->save_course=_course;
        if(c->save_course.size()==0)
          {
          qDebug()<<"No info";
          return false;
          }
          /*for(pd1=c->save_course.begin();pd1!=c->save_course.end();++pd1)
            {
              qDebug()<<*pd1<<endl;
            }*/
        for(pd1=c->save_course.begin();pd1!=c->save_course.end();++pd1)
                  {
                 if(*pd1=="英语口语")
                              {
                     qDebug()<<*pd1<<c->course_num(0);
                     //return true;
                               }
                 else if(*pd1=="高等数学")
                             {
                     qDebug()<<*pd1<<c->course_num(1);
                     //return true;
                   }
                 else if(*pd1=="大学物理")
                             {
                     qDebug()<<*pd1<<c->course_num(2);
                     //return true;
                   }
                 else if(*pd1=="政治经济学")
                             {
                     qDebug()<<*pd1<<c->course_num(3);
                     //return true;
                     }
                     else if(*pd1=="程序设计")
                             {
                     qDebug()<<*pd1<<c->course_num(4);
                     //return true;
                     }
                     else if(*pd1=="数据结构")
                              {
                     qDebug()<<*pd1<<c->course_num(5);
                     //return true;
                     }
                     else if(*pd1=="计算机原理")
                             {
                     qDebug()<<*pd1<<c->course_num(6);
                     //return true;
                     }
                     else if(*pd1=="汇编语言" )
                             {
                     qDebug()<<*pd1<<c->course_num(7);
                    // return true;
                     }
                     else if(*pd1=="OOP程序设计")
                             {
                     qDebug()<<*pd1<<c->course_num(8);
                     //return true;
                     }
                 else if(*pd1=="编译原理")
                             {
                     qDebug()<<*pd1<<c->course_num(9);
                     //return true;
                     }
                 else if(*pd1=="微机原理")
                             {
                     qDebug()<<*pd1<<c->course_num(10);
                     //return true;
                     }
                 else if(*pd1=="计算机网络")
                             {
                     qDebug()<<*pd1<<c->course_num(11);
                    // return true;
                       }
                  }
        qDebug()<<"总人数"<<c->course_num(12);
        qDebug()<<"---------------";
	return true;
}

bool Student::add_course(map_it c,Course* cour_se)
{
	  if(_course.size()==0)
	    {
	      _course.push_back(c.key());
	      _all_credit+=c.value();
	      if(cour_se->_cal_num_each_course(c))
	      {
		this->cal_tuition(c.value(),Course::_class_type);
		QMessageBox::information(NULL, "提示", "选课成功");
		return true;
	      }
	      else  QMessageBox::information(NULL, "提示", "选课人数已满");
	      return false;
		  }
	 else for(vec_it pd=_course.begin();pd!=_course.end();++pd)//首尾迭代器相等？
	   {
	     if(*pd==c.key())
	    {
		 QMessageBox::information(NULL, "提示", "选课重复!");
		 return false;
	       }
	   }
	  if(cour_se->_cal_num_each_course(c))
	  {
	      _course.push_back(c.key());
	      _all_credit+=c.value();
	      this->cal_tuition(c.value(),Course::_class_type);
	      QMessageBox::information(NULL, "提示","选课成功");
	      return true;
	    }
	  else QMessageBox::information(NULL, "提示", "选课人数已满");
	  return false;

}

/*QVector<QString> Student::course_info_1()
{
  return _course;
}*/

void Student::cal_tuition(int cre,int type)
{
	if(type==1)
		tui_tion=tui_tion+cre*200;
	else if(type==2)
		tui_tion=tui_tion+cre*150;
	else if(type==3)
		tui_tion=tui_tion+cre*100;
}

int Student::show_tuition() const
{
	return tui_tion;
}

int Student::show_credit() const
{	
	return _all_credit;
}

void Student::num_of_course()
{
	_num_of_course++;
}

int Student::return_num_of_course()
{
	return _num_of_course;
}

bool Student::confirm_()
{	
	QString name1=name+'\n';
	for(_map_it pd=stu_info.begin();pd!=stu_info.end();++pd)
	{
		if(pd.key() ==_stu_id and name1==pd.value())
			return true;
	}
	QMessageBox::information(NULL, "提示", "用户名或密码错误");
	return false;
}

QString& Student::show_name()
{
	return name;
}

const QString Student::show_teacher_info()
{
	  return "fail";
}

/*void Student::Chang_box()
{
    qDebug()<<"emit success";
}*/


Student::~Student()
{

}



