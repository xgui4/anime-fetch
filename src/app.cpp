// Source - https://stackoverflow.com/a/72251462
// Posted by 0x8ff
// Retrieved 2026-02-16, License - CC BY-SA 4.0

#include <QtWidgets/QDialog>
#include <QtWidgets/QApplication>

class MyWindow : public QDialog {
public:
    MyWindow(QWidget* parent = nullptr);
};

MyWindow::MyWindow(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("MyWindow");

    // Make widgets, etc...
}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    auto win = new MyWindow;
    win->show();

    return app.exec();
}
