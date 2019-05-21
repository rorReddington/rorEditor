#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

#include "generalsettingsform.h"
#include "stylesettingsform.h"
#include "compilingsettingsform.h"

#include "settings.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

signals:
   void toolBar_enable(bool a);
   void statusBar_enable(bool a);
   void plainTextEdit_fontChange(const QString&);
   void plainTextEdit_fontSizeChange(int);

private slots:

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_toolBarEnable_stateChange(int a);

    void on_statusBarEnable_stateChange(int a);

    void on_font_change(const QString&);

    void on_fontSize_change(const QString&);

private:
    Ui::SettingsWindow *ui;
    GeneralSettingsForm *generalSettings;
    StyleSettingsForm *styleSettings;
    CompilingSettingsForm *compilingSettings;

    Settings *settings;
};

#endif // SETTINGSWINDOW_H
