#include"course.h"
Gstudent::Gstudent(QString& a,QString& s):Student(a,s)
{
	tu_ition=0;
	_stu_id=a;
	name=s;
	QTextCodec *codec=QTextCodec::codecForName("GBK");
	QByteArray temp;
	QString temp1,temp2,temp3;
	QFile is("D:\\jisuanjizuoye\\QT4\\course\\yanjiusheng.txt");
	if(!is.open(QIODevice::ReadOnly | QIODevice::Text)) {
	    qDebug()<<"Can't open the file!"<<endl<<is.exists();
	}
	while (!is.atEnd()) {
		  temp=is.readLine();
		  temp1=temp.mid(10,7);
		  temp2=codec->toUnicode(temp.mid(18));
		  temp3=codec->toUnicode(temp.mid(3,6));
		  G_info.insert(temp1,temp2);
		  //qDebug()<<temp3<<temp1;
		  class_teacher.insert(temp3,temp1.toInt());//map删除相同元素
	}
}

int Gstudent::show_tuition() const
{
    return tu_ition;
}

void Gstudent::cal_tuition(int cre,int type)
{
	if(type==1)
		tu_ition=tu_ition+cre*200;
	else if(type==2)
		tu_ition=tu_ition+cre*180;
	else if(type==3)
		tu_ition=tu_ition+cre*150;
}

/*bool Gstudent::_display_course() const
{
	if(_course.size()==0)
		{
		qDebug()<<"No info"<<endl;
		return false;
		}
	else
		for(auto pd:_course)
			qDebug()<<pd<<endl;
	qDebug()<<"---------------";
	return true;
}*/


bool Gstudent::confirm_()
{
	QString name1=name+'\n';
	for(_map_it pd=G_info.begin();pd!=G_info.end();++pd)
	{
	    if(pd.key() ==_stu_id and name1==pd.value())
		    return true;
	}
	QMessageBox::information(NULL, "提示", "用户名或密码错误");
	return false;
}

const QString Gstudent::show_teacher_info()
{
  for(map_it pd=class_teacher.begin();pd!=class_teacher.end();++pd)
  {
      if(pd.value() ==_stu_id.toInt())
              return pd.key();
  }
  return "No info";
}

Gstudent::~Gstudent()
{
}
