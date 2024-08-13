#include <QApplication>
#include <QQuickView>
#include <QUrl>
#include <QQmlEngine>
#include <QApplication>

#include "FileWatcher.h"
#include "ClientManager.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QQuickView view;

  const QDir DIRECTORY("/Users/test/Documents/chat_app");
  const QUrl SOURCE_URL = QUrl::fromLocalFile(DIRECTORY.filePath("./customModules/Main.qml"));

  const QUrl url("qrc:/QML/ClientApp/customModules/Main.qml");
  view.setSource(url);
  view.setWidth(500);
  view.setHeight(800);
  view.show();

  FileWatcher watcher([&view, SOURCE_URL]()
                      { view.engine()->clearComponentCache();
                        view.setSource(SOURCE_URL); });

  watcher.set_directory(DIRECTORY.absolutePath());

  QObject::connect(&app, &QCoreApplication::aboutToQuit, []()
                   { ClientManager::cleanup(); });

  return app.exec();
}