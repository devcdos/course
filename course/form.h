#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "choose_course.h"
//#include "course_info_.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
  //Form* return_this();

private slots:

  void on_choose_course_clicked();

  void on_back_1_clicked();

  void on_show_credit_clicked();

  void on_show_tuition_clicked();

  void on_my_info_clicked();

  void on_course_info_clicked();

private:
    Ui::Form *ui;
    Choose_course w2;
    //Course_info_ w3;
    //Student stu;


};

#endif // FORM_H
