#include <QtWidgets/QDialog>
#include <QtWidgets/QApplication>
#include <qboxlayout.h>
#include <qdebug.h>
#include <qicon.h>
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
#include <vector>
#include "os_type.hpp"
#include "services/system_info_service.h" 

int main(int argc, char** argv)
{
	int height = 500; 
    int width = 500; 

    QApplication app(argc, argv);
    auto * mainWindow = new QMainWindow();

    mainWindow->setMinimumHeight(height); 
    mainWindow->setMinimumWidth(width); 

    auto *centralWidget = new QWidget(mainWindow);

    auto * box = new QHBoxLayout(centralWidget); 

    box->setSpacing(5);

    QSysInfo systemInfo; 
    SystemInfoService systemInfoService; 

    const QString HOSTNAME_STR = systemInfo.machineHostName(); 
    const QString KERNEL_NAME_STR = systemInfo.kernelType() + " " + systemInfo.kernelVersion(); 
    const QString OS_NAME_STR = systemInfo.prettyProductName(); 
    std::vector<CPUInfo> cpus = systemInfoService.getCpuInfo(); 

    QString cpus_info_string = ""; 

    for (int i = 0; i < cpus.size(); i++) {
        cpus_info_string += cpus.at(i).display(); 
    }

    std::vector<GPUInfo> gpus = systemInfoService.getGpuInfo(); 

    QString gpus_info_string = ""; 

    for (int i = 0; i < gpus.size(); i++) {
        gpus_info_string += gpus.at(i).display(); 
    }

    const QString MEMORY_STR = QString::fromStdString(systemInfoService.getMemoryInfo()); 

    auto * systemFetchLabel = new QLabel(
        "Hostname: " + HOSTNAME_STR + "\n" + 
        "Kernel: " + KERNEL_NAME_STR + "\n" + 
        "OS: " + OS_NAME_STR + "\n" + 
        cpus_info_string + "\n" +
        gpus_info_string  + "\n"
        "Memory : " + MEMORY_STR
    ); 

    QString os_tan_img_path; 

    // QString logo_img_path; 

    if (systemInfoService.getOsType() == OS_TYPE::Windows) {
        os_tan_img_path = ".anime-fetch\\images\\os-tan\\windows\\windows11-tan.png"; 
        qDebug() << systemInfo.productVersion() << Qt::endl;
    }
    else if (systemInfoService.getOsType() == OS_TYPE::MacOS) {
        os_tan_img_path =  ".anime-fetch/images/os-tan/mac/system-tan.png"; 
    }
    else if (systemInfoService.getOsType() == OS_TYPE::Linux) {
        os_tan_img_path = ".anime-fetch/images/os-tan/linux/arch-1-tan.png";
    }
    else if (systemInfoService.getOsType() == OS_TYPE::BSD) {
        os_tan_img_path = ".anime-fetch/images/os-tan/bsd/free-bsd-tan.png";
    }
    else if (systemInfoService.getOsType() == OS_TYPE::Unix) {
        os_tan_img_path = ".anime-fetch/images/os-tan/others/solaris-tan.png";
    }
    else {
        os_tan_img_path = ".anime-fetch/images/os-tan/windows/windows7-tan.png"; 
    }

    const QString HOME_PATH = QDir::homePath(); 

    auto image = QPixmap(HOME_PATH + "/" + os_tan_img_path);
	qDebug() << HOME_PATH + "/" + os_tan_img_path << Qt::endl;

    auto* imgLabel = new QLabel();
    imgLabel->setPixmap(image); 
    imgLabel->setScaledContents(true);

    box->addWidget(systemFetchLabel); 
    box->addWidget(imgLabel); 

    mainWindow->setCentralWidget(centralWidget);

    mainWindow->setWindowTitle("Anime Fetch GUI");
    mainWindow->setWindowIcon(QIcon(HOME_PATH + "/.anime-fetch/icons/appicon.png"));
    mainWindow->show();

    return app.exec();
}
