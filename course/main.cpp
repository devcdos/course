#include <QApplication>
#include "gui_course.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QString test("啊");
    qDebug()<<test;
    qDebug()<<"啊";
    QApplication a(argc, argv);
    GUI_course w;
    w.show();
    return a.exec();
}
