#ifndef COMPILER_H
#define COMPILER_H

#include <QString>


class Compiler
{
public:
    Compiler(const QString path);
    void changePath(const QString path);
    void compiling(const QString file, const QString params = nullptr);
private:
    QString path;
};

#endif // COMPILER_H
