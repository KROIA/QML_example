#include "QML_windowOpener.h"
#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include <QObject>

namespace QML_example
{

	void QML_windowOpener::show()
	{
        static bool onceSetup = false;
        if (onceSetup)
            return;
        onceSetup = true;
        static QQmlApplicationEngine engine;
        Q_INIT_RESOURCE(QML);
        const QUrl url(QStringLiteral("qrc:/QML/main.qml"));

        QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
            qApp, [url](QObject* obj, const QUrl& objUrl) {
                if (!obj && url == objUrl) {
                    QCoreApplication::exit(-1);
                }
            }, Qt::QueuedConnection);

        engine.load(url);
	}
}