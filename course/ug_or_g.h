#ifndef UG_OR_G_H
#define UG_OR_G_H

#include <QWidget>
#include "form.h"
#include "course.h"

namespace Ui {
  class Ug_or_g;
}

class Ug_or_g : public QWidget
{
  Q_OBJECT

public:
  explicit Ug_or_g(QWidget *parent = nullptr);
  ~Ug_or_g();
private slots:

  void on_btn_UG_clicked();

  void on_btn_G_clicked();

private:
  Ui::Ug_or_g *ui;
  Form select_mode;
  //Student *stu;
};


#endif // UG_OR_G_H
