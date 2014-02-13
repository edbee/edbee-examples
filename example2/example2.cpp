
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QMainWindow>

#include "edbee/edbee.h"
#include "edbee/models/textdocument.h"
#include "edbee/models/textgrammar.h"
#include "edbee/texteditorwidget.h"
#include "edbee/views/textrenderer.h"
#include "edbee/views/texttheme.h"


/// This is an example that shows how to load a grammar file and a theme file
/// manually and initialise the editor with it
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // initialize edbee
    edbee::Edbee* edbee = edbee::Edbee::instance();
    edbee->autoInit();

    // read the grammar file
    edbee::TextGrammarManager* grammarManager = edbee->grammarManager();
    edbee::TextGrammar* grammar = grammarManager->readGrammarFile( "HTML.tmLanguage" );
    if( !grammar ) {
        qDebug() << "Grammar couldn't be loaded: " << grammarManager->lastErrorMessage();
        edbee->shutdown(); // call this method manuall to prevent memory leak warnings. When the exec method is called this isn't required
        return 1;
    }

    // read the theme file
    edbee::TextThemeManager* themeManager = edbee->themeManager();
    edbee::TextTheme* theme = themeManager->readThemeFile( "SpaceCadet.tmTheme" );
    if( !theme) {
        qDebug() << "Theme couldn't be loaded: " << themeManager->lastErrorMessage();
        edbee->shutdown(); // call this method manuall to prevent memory leak warnings. When the exec method is called this isn't required
        return 1;
    }

    // next create the main window and the editor
    QMainWindow win;
    edbee::TextEditorWidget editor;
    editor.textDocument()->setLanguageGrammar( grammar );
    editor.textRenderer()->setTheme( theme );

    // set some initial text
    editor.textDocument()->setText("<html>\n\t<body>\n\t\t<h1>Hello World</h1>\n\t</body>\n</html>\n");

    // show the window
    win.setCentralWidget( &editor );
    win.show();
    return a.exec();
}
