#include"course.h"
void GUI(Student*);
int main()
{
	//vector<Student> stu;
	//vector<Student>::iterator st;
	int stu_id;
	string name,course,judge;
	cout<<"Enter your student id"<<endl;
	cin>>stu_id;
	cout<<"Enter your name:"<<endl;
	cin>>name;
	Student stu_dent(stu_id,name);
	Gstudent Gstu_dent(stu_id,name);
	UGstudent UGstu_dent(stu_id,name);	
	Course cou_rse;
	Student *stu;
	cout<<"G or UG?"<<endl;
	cin>>judge;
	if(judge=="UG")
		stu=&UGstu_dent; 
	else if(judge=="G") 
		stu=&Gstu_dent; 
	else cout<<"failed";
	if(stu->confirm_())
	{	
	GUI(stu);
	string select;
	while(cin>>select)
	{
	if(select=="exit")
	{
		cout<<"exit successfully";
		break;
	}
	else if(select=="2")
		stu->_display_course();
	else if(select=="3")
	{
		stu->show_tuition();
	}
	else if(select=="4")
	{
		stu->show_credit();
	}
	else if(select=="1")
		{
		cout<<"Enter your course"<<endl;
		while(cin>>course)
		{
			if(course=="quit")
			{
				GUI(stu);
				break;
			}
			if("false"==cou_rse.find_course(course)->first)
				{
				cout<<"No such course"<<endl;
				}
			else {
				stu->add_course(cou_rse.find_course(course));
				stu->cal_tuition(cou_rse.find_course(course)->second,Course::_class_type);
				stu->num_of_course();
				cou_rse._cal_num_each_course(cou_rse.find_course(course));
		}	
		}
	}
	else {
	cout<<"failed"<<endl;
	break;
		}
	}
	
   }
   else cout<<"failed";
}
void GUI(Student* stu)
{
	cout<<"Welcome "<<stu->show_name()<<endl
	<<"select your mode(Enter 1,2 or 3)(exit to quit)"<<endl
	<<"1:choose course"<<endl
	<<"2:display information"<<endl
	<<"3:tuition"<<endl
	<<"4:credit"<<endl;
	}
