#include <QtQuick>

int main(int argc, char **argv)
{
    QCoreApplication::setOrganizationName("QM_modules");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath(":/QML_modules/");

    const QUrl url("qrc:/QML_modules/ClientApp/customModules/Main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl)
                     { if (!obj && url == objUrl) QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}