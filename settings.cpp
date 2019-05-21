#include "settings.h"

Settings::Settings()
{
    toolBar = new ToolBar();
    statusBar = new StatusBar();
    compiler = new Compiler();
    style = new Style();
}

Settings::~Settings()
{
    delete toolBar;
    delete statusBar;
    delete compiler;
    delete style;
}

bool Settings::ToolBar::getEnable() { return enable; }

void Settings::ToolBar::setEnable(bool a) { enable = a; }

bool Settings::StatusBar::getEnable() { return enable; }

void Settings::StatusBar::setEnable(bool a) { enable = a; }

const QString Settings::Compiler::getPath() { return path; }

void Settings::Compiler::setPath(QString newPath) { path = newPath; }

const QString Settings::Compiler::getParams() { return params; }

void Settings::Compiler::setParams(QString newParams) { path = newParams; }

const QString Settings::Style::getFont() { return fontName; }

int Settings::Style::getTabSize() { return tabSize; }

int Settings::Style::getFontSize() { return fontSize; }

QColor Settings::Style::getFontColor() { return font; }

QColor Settings::Style::getBackgroundColor() { return background; }

bool Settings::Style::setFont(QString font)
{
    if (font.isEmpty())
        return false;

    fontName = font;
    return true;
}

void Settings::Style::setTabSize(int size)
{
    if (size < 0)
        return;

    tabSize = size;
}

void Settings::Style::setFontSize(int size)
{
    fontSize = size;
}

void Settings::Style::setFontColor(QColor color)
{
    font = color;
}

void Settings::Style::setBackgroundColor(QColor color)
{
    background = color;
}
