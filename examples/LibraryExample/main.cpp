#include <QGuiApplication>
#include "QML_example.h"

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    QML_example::QML_windowOpener::show();

    return app.exec();
}
