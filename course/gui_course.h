#ifndef GUI_COURSE_H
#define GUI_COURSE_H

#include <QMainWindow>
#include "ug_or_g.h"
#include "course.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GUI_course; }
QT_END_NAMESPACE

class GUI_course : public QMainWindow
{
    Q_OBJECT

public:
    GUI_course(QWidget *parent = nullptr);
    //static QString stu_id;
    //static QString stu_passwd;
    ~GUI_course();

private slots:

    void on_btn_cancel_clicked();

    void on_btn_log_clicked();

private:
    Ui::GUI_course *ui;
    //void Init();
    Ug_or_g dia_log1;
    //Course stu_course;
    //QString stu_id;				//
   // QString stu_passwd;

};
#endif // GUI_COURSE_H
