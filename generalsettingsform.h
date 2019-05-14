#ifndef GENERALSETTINGSFORM_H
#define GENERALSETTINGSFORM_H

#include <QWidget>
#include <QToolBar>
#include <QStatusBar>

namespace Ui {
class GeneralSettingsForm;
}

class GeneralSettingsForm : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralSettingsForm(QWidget *parent = nullptr);
    ~GeneralSettingsForm();

    void setPointers(QToolBar* tool, QStatusBar* status);

private slots:
    void on_checkBoxStatusBarHide_stateChanged(int arg1);

    void on_checkBoxToolBarHide_stateChanged(int arg1);

private:
    Ui::GeneralSettingsForm *ui;

    QToolBar *toolBar;
    QStatusBar *statusBar;
};

#endif // GENERALSETTINGSFORM_H
