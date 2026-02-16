#include <QtWidgets/QDialog>
#include <QtWidgets/QApplication>
#include <qboxlayout.h>
#include <qmainwindow.h>
#include <qnamespace.h>
#include <qsize.h>
#include <qwidget.h>
#include <QLabel>
#include <QBoxLayout>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QMainWindow * mainWindow = new QMainWindow();
    QWidget *centralWidget = new QWidget(mainWindow);

    QBoxLayout *  box = new QHBoxLayout(centralWidget); 
    
    QLabel * label = new QLabel("Hello World"); 

    box->addWidget(label); 

    label->setAlignment(Qt::AlignCenter); 

    mainWindow->setWindowTitle("Anime Fetch");
    mainWindow->show();

    return app.exec();
}
