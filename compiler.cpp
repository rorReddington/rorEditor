#include "compiler.h"

Compiler::Compiler(const QString newPath) { path = newPath; }

void Compiler::changePath(const QString newPath) { path = newPath; }

void Compiler::compiling(const QString file, const QString params)
{
    QString compiler;

    if (params.isEmpty()) compiler = path + file;
    else compiler = path + file + params;

    system(compiler.toStdString().c_str());
}
