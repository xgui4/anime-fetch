#include <QtWidgets/QDialog>
#include <QtWidgets/QApplication>
#include <qboxlayout.h>
#include <qdebug.h>
#include <qimage.h>
#include <qlabel.h>
#include <qmainwindow.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qpixmap.h>
#include <qsize.h>
#include <qstringview.h>
#include <qsysinfo.h>
#include <qwidget.h>
#include <QLabel>
#include <QBoxLayout>
#include <QDir>
#include <QDebug>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QMainWindow * mainWindow = new QMainWindow();

    mainWindow->setMinimumHeight(500); 
    mainWindow->setMinimumWidth(500); 

    QWidget *centralWidget = new QWidget(mainWindow);

    QBoxLayout * box = new QHBoxLayout(centralWidget); 

    box->setSpacing(5);

    QSysInfo systemInfo; 

    const QString HOSTNAME_STR = systemInfo.machineHostName(); 
    const QString KERNEL_NAME_STR = systemInfo.kernelType() + " " + systemInfo.kernelVersion(); 
    const QString OS_NAME_STR = systemInfo.prettyProductName(); 

    QLabel * label = new QLabel("Hostname: " + HOSTNAME_STR + "\n" + "Kernel: " + KERNEL_NAME_STR + "\n" + "OS: " + OS_NAME_STR); 

    QString os_tan_img_path; 

    // QString logo_img_path; 

    #ifdef __win32__
        os_tan_img_path = ".anime-fetch/images/os-tan/windows/win11-os-tan-temp.png"; 
    #elif __apple__
        os_tan_img_path =  ".anime-fetch/images/os-tan/mac/system-tan.png"; 
    #elif __linux__
        os_tan_img_path = ".anime-fetch/images/os-tan/linux/arch-1-tan.png";
    #elif __FreeBSD__
        os_tan_img_path = ".anime-fetch/images/os-tan/others/free-bsd-tan.png";
    #elif __unix__
        os_tan_img_path = ".anime-fetch/images/os-tan/others/solaris-tan.png";
    #else
        os_tan_img_path = ".anime-fetch/images/os-tan/windows/os-tan7.png"; 
    #endif

    const QString HOME_PATH = QDir::homePath(); 

    qDebug() << HOME_PATH + "/" + os_tan_img_path << Qt::endl;

    #ifdef __win32__
        QPixmap image = QPixmap(    HOME_PATH + "\\" + os_tan_img_path);
    #else
        QPixmap image = QPixmap(    HOME_PATH + "/" + os_tan_img_path);
    #endif

    QLabel* imgLabel = new QLabel();
    imgLabel->setPixmap(image); 

    box->addWidget(label); 
    box->addWidget(imgLabel); 

    mainWindow->setCentralWidget(centralWidget);

    mainWindow->setWindowTitle("Anime Fetch");
    mainWindow->show();

    return app.exec();
}
