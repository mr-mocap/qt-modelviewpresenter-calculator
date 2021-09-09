#include <QGuiApplication>
#include <QQmlApplicationEngine>

// calc_lib
#include <QCalculatorPresenter.h>
#include <QCalculatorView.h>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    // Register our types in Qt
    QCalculatorPresenter::RegisterType();
    QCalculatorView::RegisterType();

    QGuiApplication app(argc, argv);

    // This should allow us to basically generate any type of GUI
    // main objects.
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
