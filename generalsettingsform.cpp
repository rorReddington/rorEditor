#include "generalsettingsform.h"
#include "ui_generalsettingsform.h"

GeneralSettingsForm::GeneralSettingsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeneralSettingsForm)
{
    ui->setupUi(this);

    ui->comboBoxLanguage->addItem("English");
    ui->comboBoxLanguage->setEnabled(false);

    QObject::connect(this, SIGNAL(statusBarEnable_stateChange(int)), parent, SLOT(on_statusBarEnable_stateChange(int)));
    QObject::connect(this, SIGNAL(toolBarEnable_stateChange(int)), parent, SLOT(on_toolBarEnable_stateChange(int)));
}

GeneralSettingsForm::~GeneralSettingsForm()
{
    delete ui;
}

void GeneralSettingsForm::on_checkBoxStatusBarHide_stateChanged(int arg1)
{
    // StatusBar hide
    emit statusBarEnable_stateChange(arg1);
}

void GeneralSettingsForm::on_checkBoxToolBarHide_stateChanged(int arg1)
{
    // ToolBar hide
    emit toolBarEnable_stateChange(arg1);
}
