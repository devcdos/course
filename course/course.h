#ifndef _COURSE_H
#define _COURSE_H
#include<QMap>
#include<QVector>

#include<QDebug>
#include<QFile>
#include <QTextCodec>
#include <QMessageBox>

using namespace std;

typedef QVector<QString>::iterator vec_it;
typedef QMap<QString,int>::iterator map_it;
typedef QMap<QString,QString>::iterator _map_it;
typedef QMultiMap<QString,int>::iterator m_map_it;


/*基本功能算是实现了，但还有很多可以改进的地方。
 * 1：总人数是本科生和研究生一起算的，课表只显示一个用户，且退出后不会保存，无法检测是否为重复登录。
 * 2：课表显示的方法可做成动态控件，由于对信号槽机制的不熟练，改用编辑器输出。
 * 3：代码逻辑相对混乱，各种头文件包来包去，可进行进一步的逻辑优化
*/
class Course
{
	private: 
		QMap<QString,int> dis_class_name;			//
		QMap<QString,int> spec_class_name;
		QMap<QString,int> pro_class_name;
		 //可进行封装的写法
		int _num_English_course=0;			//
		int _num_Math_course=0;
		int _num_Physics_course=0;
		int _num_Politic_course=0;
		int _num_Progamming_course=0;
		int _num_Database_course=0;
		int _num_Computer_course=0;
		int _num_Huibian_course=0;
		int _num_OOP_course=0;
		int _num_bianyi_course=0;
		int _num_weiji_course=0;
		int _num_internet_course=0;
		int _sum_all_course=0;
		//
	public:
		Course();
		static int _class_type;	//课程种类
		bool _cal_num_each_course(map_it);		//计算每门课选课人数
		int _cal_sum_all_course();
		map_it find_course(QString&&);
		int course_num(int) const;
		//bool value_to_save_course(vec_it,int);
		//vec_it return_save_course();
		QVector<QString> save_course;
		~Course();
};

class Student
{
	private:					
		int _num_of_course=0;			//
		int _all_credit;			//
		int tui_tion=0;			//
	protected:
	  QString _stu_id;				//
	  QString name;				  //
	  QVector<QString> _course;		//
	  QMap<QString,QString> stu_info;   //
	public:
	       explicit Student(QString&,QString&);
		explicit Student();
		virtual bool confirm_();			//
		bool add_course(map_it,Course*);	//把选的课加进来
		virtual int show_tuition() const;
		void num_of_course();
		int return_num_of_course();
		int show_credit() const;
		virtual void cal_tuition(int,int);
		bool _display_course(Course*);		//
		virtual const QString show_teacher_info();
		QString& show_name();
		virtual ~Student();
		//QVector<QString> course_info_1();
     /* signals:
      void Chang_box();
*/
 };
 
class UGstudent:public Student
 {	
 	private:
                QMultiMap<QString,int> class_teacher;
 		//string class_teacher;
 	public:
        explicit UGstudent(QString&,QString&);
                const QString show_teacher_info();
 		virtual ~UGstudent();
 		//bool _display_course() const;
 		
};
  
class Gstudent:public Student
{
	private:
	QMap<QString,QString> G_info;
	QMultiMap<QString,int> class_teacher;
	int tu_ition=0;		    //
	public:
		explicit Gstudent(QString&,QString&);//
 		virtual ~Gstudent();
                int show_tuition() const;
 		bool confirm_();
 		void cal_tuition(int,int);
                //bool _display_course() const;
                const QString show_teacher_info();
};


#endif
