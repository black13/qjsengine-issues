#include <QCoreApplication>
#include <QJSEngine>
#include <QJSValue>
#include <QFile>

#include "console.h"

bool loadAndEvaluate(const QString &filepath, QJSEngine &jsEngine, Console &console)
{
    QFile f(filepath);
    f.open(QFile::ReadOnly);
    QString source = QString::fromUtf8(f.readAll());
    f.close();
    QJSValue res = jsEngine.evaluate(source, filepath);
    if (res.isError()) {
        console.error(res.property("stack").toVariant());
        return false;
    }
    return true;
}

int main(int argc, char *argv[], const char *envp[])
{
    Q_UNUSED(envp);

    QCoreApplication app(argc, argv);

    QJSEngine jsEngine(&app);
    Console console(&app);

    QJSValue g = jsEngine.globalObject();
    QObject ex;

    g.setProperty("ex", jsEngine.newQObject(&ex));
    g.setProperty("console", jsEngine.newQObject(&console));

    if (!loadAndEvaluate(":/app.js", jsEngine, console)) {
        return -1;
    }

    return 0;
}

// vim:ts=4:sw=4:sts=4:et:
