#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

#include "generalsettingsform.h"
#include "stylesettingsform.h"
#include "compilingsettingsform.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

    void setPointers(QToolBar*, QStatusBar*);

private slots:

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::SettingsWindow *ui;
    GeneralSettingsForm *generalSettings;
    StyleSettingsForm *styleSettings;
    CompilingSettingsForm *compilingSettings;
};

#endif // SETTINGSWINDOW_H
