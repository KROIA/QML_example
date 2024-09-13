#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "QML_example.h"

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    static QQmlApplicationEngine engine;
    Q_INIT_RESOURCE(QML);
    const QUrl url(QStringLiteral("qrc:/table.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        qApp, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl) {
                QCoreApplication::exit(-1);
            }
        }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
