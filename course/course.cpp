#include"course.h"

int Course::_class_type=0;

Course::Course()
{
	dis_class_name["英语口语"]=4;
	dis_class_name["高等数学"]=2;
	dis_class_name["大学物理"]=1;
	dis_class_name["政治经济学"]=1;
	spec_class_name["程序设计"]=2;
	spec_class_name["数据结构"]=2;
	spec_class_name["计算机原理"]=3;
	spec_class_name["汇编语言"]=3;
	pro_class_name["OOP程序设计"]=2;
	pro_class_name["编译原理"]=2;
	pro_class_name["微机原理"]=3;
	pro_class_name["计算机网络"]=3;
	save_course.push_back("failed");
}


bool Course::_cal_num_each_course(map_it course)
{
       QString cour_se=course.key();
    if(cour_se=="英语口语"  and _num_English_course<=15)
                 {
        _num_English_course++;
        //qDebug()<<_num_English_course;
        return true;
                  }
    else if(cour_se=="高等数学" and _num_Math_course<=15)
                {
        _num_Math_course++;
        return true;
      }
    else if(cour_se=="大学物理" and _num_Physics_course<=15)
                {
        _num_Physics_course++;
        return true;
      }
    else if(cour_se=="政治经济学" and _num_Politic_course<=15)
                {
            _num_Politic_course++;
            return true;
        }
	else if(cour_se=="程序设计" and _num_Progamming_course<=15)
		{
	    _num_Progamming_course++;
	    return true;
	}
	else if(cour_se=="数据结构" and  _num_Database_course<=15)
		 {
	    _num_Database_course++;
	    return true;
	}
	else if(cour_se=="计算机原理" and _num_Computer_course<=15)
		{
	    _num_Computer_course++;
	    return true;
	}
	else if(cour_se=="汇编语言" and _num_Huibian_course<=15)
		{
	    _num_Huibian_course++;
	    return true;
	}
	else if(cour_se=="OOP程序设计" and _num_OOP_course<=15)
		{
	    _num_OOP_course++;
	    return true;
	}
    else if(cour_se=="编译原理" and  _num_bianyi_course<=15)
                {
            _num_bianyi_course++;
        return true;
        }
    else if(cour_se=="微机原理" and  _num_weiji_course<=15)
                {
            _num_weiji_course++;
            return true;
        }
    else if(_num_internet_course<=15)
                {
            _num_internet_course++;
            return true;
          }
	//return _num_each_course;
    return false;
}


int Course::_cal_sum_all_course()
{
		
    _sum_all_course++;
    return 1;
}

map_it Course::find_course(QString &&c)
{
	QMap<QString,int> temp;
	temp["false"]=0;
	if(dis_class_name.end()!=dis_class_name.find(c))
	{
		_class_type=1;
		return dis_class_name.find(c);
	}
	else if(spec_class_name.end()!=spec_class_name.find(c))
		{
		_class_type=2;
		return spec_class_name.find(c);
		}
	else if(pro_class_name.end()!=pro_class_name.find(c))
	{
		_class_type=3;
		return pro_class_name.find(c);
	}
	else return temp.begin();
}


int Course::course_num(int a) const
{
  switch (a) {
    case 0:return _num_English_course;break;		//
      case 1: return _num_Math_course;break;
      case 2: return _num_Physics_course;break;
      case 3:return _num_Politic_course;break;
      case 4: return _num_Progamming_course;break;
      case 5:return _num_Database_course;break;
      case 6: return _num_Computer_course;break;
      case 7: return _num_Huibian_course;break;
      case 8:return  _num_OOP_course;break;
      case 9: return _num_bianyi_course;break;
      case 10:return  _num_weiji_course;break;
     case 11:return _num_internet_course;break;
      case 12: return _sum_all_course;break;
    default:return -1;

    }
}


/*bool Course::value_to_save_course(vec_it pd,int n)//pd=begin
{
  while(n>0)
    {
      save_course.push_back(*pd);
      pd++;
      qDebug()<<*pd;
      n--;
    }
  return true;
}

vec_it Course::return_save_course()
{
  vec_it pd=save_course.begin();
  return pd;
}*/

Course::~Course()
{
  //delete cou_rse;
}

