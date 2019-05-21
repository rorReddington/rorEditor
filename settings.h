#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtCore>
#include <QColor>

class Settings
{
private:

    class ToolBar {
    private:
        bool enable;
    public:
        bool getEnable();
        void setEnable(bool a);
    };

    class StatusBar {
    private:
        bool enable;
    public:
        bool getEnable();
        void setEnable(bool a);
    };

    class Compiler {
    private:
        QString path;
        QString params;
    public:
        const QString getPath();
        const QString getParams();

        void setPath(const QString newPath);
        void setParams(const QString newParams);
    };

    class Style {
    private:
        QString fontName;
        int fontSize;
        int tabSize;
        QColor background;
        QColor font;
    public:
        bool setFont(const QString font);
        const QString getFont();

        void setFontSize(int size);
        int getFontSize();

        void setTabSize(int size);
        int getTabSize();

        void setBackgroundColor(QColor color);
        QColor getBackgroundColor();

        void setFontColor(QColor color);
        QColor getFontColor();
    };

public:
    Settings();
    ~Settings();

    ToolBar* toolBar;
    StatusBar* statusBar;
    Compiler* compiler;
    Style* style;

    bool save();
};

#endif // SETTINGS_H
