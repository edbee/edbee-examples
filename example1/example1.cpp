
#include <QApplication>
#include <QMainWindow>
#include "edbee/texteditorwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow win;

    edbee::TextEditorWidget editor;
    win.setCentralWidget( &editor );
    win.show();

    return a.exec();
}
