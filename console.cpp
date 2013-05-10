#include "console.h"

#include <iostream>

// public:

Console::Console(QObject *parent)
    : QObject(parent)
{
}

// public slots:

void Console::log(const QVariant &value) const
{
    std::cout << qPrintable(value.toString()) << std::endl;
}

void Console::error(const QVariant &value) const
{
    std::cerr << qPrintable(value.toString()) << std::endl;
}

void Console::emitSignal() const
{
    emit signal();
}

// vim:ts=4:sw=4:sts=4:et:
