#include "generalsettingsform.h"
#include "ui_generalsettingsform.h"

GeneralSettingsForm::GeneralSettingsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeneralSettingsForm)
{
    ui->setupUi(this);

    ui->comboBoxLanguage->addItem("English");
    ui->comboBoxLanguage->setEnabled(false);
}

GeneralSettingsForm::~GeneralSettingsForm()
{
    delete ui;
}

void GeneralSettingsForm::setPointers(QToolBar *tool, QStatusBar *status)
{
    toolBar = tool;
    statusBar = status;
}

void GeneralSettingsForm::on_checkBoxStatusBarHide_stateChanged(int arg1)
{
    // StatusBar hide
    arg1 ? statusBar->hide() : statusBar->show();
}

void GeneralSettingsForm::on_checkBoxToolBarHide_stateChanged(int arg1)
{
    // ToolBar hide
    arg1 ? toolBar->hide() : toolBar->show();
}
