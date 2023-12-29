#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFile>

#include "../include/StepsModel/StepsModelsController.h"
#include "../include/TemplateModel/TemplatesModelsController.h"
#include "../include/InitExtendLibs.h"

int main(int argc, char *argv[])
{
    StepsModelsController model;
    TemplatesController templateModel;

    InitExtendLibs initlibs;
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("theModel", &model);
    engine.rootContext()->setContextProperty("templateModel", &templateModel);
    engine.rootContext()->setContextProperty("initExtenalObj", &initlibs);

    const QUrl url(QStringLiteral("qrc:/src/qml/main.qml"));
    engine.load(url);


    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
