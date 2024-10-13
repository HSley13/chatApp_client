#include <QApplication>
#include <QCoreApplication>
#include <QDir>
#include <QQmlEngine>
#include <QQuickView>
#include <QUrl>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QQmlEngine engine;
  engine.addImportPath(QCoreApplication::applicationDirPath() +
                       "/../Resources/qml");

  QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath() +
                                   "/../PlugIns");

  QQuickView view;

  const QUrl url("qrc:/QML/ClientApp/customModules/Main.qml");
  view.setSource(url);
  view.setWidth(500);
  view.setHeight(800);
  view.show();

  return app.exec();
}
