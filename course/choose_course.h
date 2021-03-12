#ifndef CHOOSE_COURSE_H
#define CHOOSE_COURSE_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
  class Choose_course;
}

class Choose_course : public QWidget
{
  Q_OBJECT

public:
  explicit Choose_course(QWidget *parent = nullptr);
  ~Choose_course();

private slots:

 void on_Confirm_course_clicked();

 void on_back_2_clicked();

private:
  Ui::Choose_course *ui;
  int check_btn();
  QButtonGroup *test;
};

#endif // CHOOSE_COURSE_H
