#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QDebug>

#include "calendar.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

	/*Calendar cal("Test");
	qDebug() << cal.newMonth("Ordelius", 41)->name();
	qDebug() << cal.newMonth("Caslistrius", 41)->name();
	cal.close();*/

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
