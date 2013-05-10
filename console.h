#ifndef CONSOLE_H
#define CONSOLE_H

#include <QObject>
#include <QVariant>

class Console : public QObject
{
    Q_OBJECT

public:
    explicit Console(QObject *parent = 0);

signals:
    void signal() const;

public slots:
    void log(const QVariant &value) const;
    void error(const QVariant &value) const;

    void emitSignal() const;
};

#endif // CONSOLE_H

// vim:ts=4:sw=4:sts=4:et:
