#include"course.h"

UGstudent::UGstudent(QString& a,QString& b):Student(a,b)
{

          QTextCodec *codec=QTextCodec::codecForName("GBK");
          QByteArray temp;
          QString temp1;
          QString temp2;
          QFile is("D:\\jisuanjizuoye\\QT4\\course\\233.txt");
              if(!is.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                  qDebug()<<"Can't open the file!"<<endl<<is.exists();
                  }
              while (!is.atEnd()) {
                temp=is.readLine();
                temp1=codec->toUnicode(temp.mid(10,7));
                temp2=codec->toUnicode(temp.mid(3,6));
                class_teacher.insert(temp2,temp1.toInt());
}
}

const QString UGstudent::show_teacher_info()
{
  for(m_map_it pd=class_teacher.begin();pd!=class_teacher.end();++pd)
  {
      if(pd.value() ==_stu_id.toInt())
              return pd.key();
  }
  return "No info";
}

 UGstudent::~UGstudent()
{
	
}
