/*#ifndef COURSE_INFO__H
#define COURSE_INFO__H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class Course_info_ : public QWidget
{
  Q_OBJECT

public:
 Course_info_(QWidget *parent = nullptr);
 ~Course_info_();

private:
  void Init();
  QLabel* course_text;
  QLabel* person_text;
  //QLabel  course_text_;
  QHBoxLayout *cmdLayout;
  QVBoxLayout *dmcLayout;
public slots:
  bool  Change_BOX();
};
#endif // COURSE_INFO__H
*/
