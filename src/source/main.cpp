#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFile>

#include "../include/StepsModelsController.h"
#include "../include/InitExtendLibs.h"

int main(int argc, char *argv[])
{

    QFile file(":/src/source/TreeModel/default.txt");
    file.open(QIODevice::ReadOnly);
    StepsModelsController model(file.readAll());
    file.close();
    InitExtendLibs initlibs;
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("theModel", &model);
    engine.rootContext()->setContextProperty("initExtenalObj", &initlibs);

    const QUrl url(QStringLiteral("qrc:/src/qml/main.qml"));
    engine.load(url);


    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
