#include "generalsettingsform.h"
#include "ui_generalsettingsform.h"

GeneralSettingsForm::GeneralSettingsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeneralSettingsForm)
{
    ui->setupUi(this);

    ui->comboBoxLanguage->addItem("English");
    ui->comboBoxLanguage->setEnabled(false);

    QObject::connect(this, SIGNAL(toolBarEnable_stateChange(bool)), parent, SLOT(on_toolBarEnable_stateChange(bool)));
    QObject::connect(this, SIGNAL(statusBarEnable_stateChange(bool)), parent, SLOT(on_statusBarEnable_stateChange(bool)));
}

GeneralSettingsForm::~GeneralSettingsForm()
{
    delete ui;
}

void GeneralSettingsForm::on_checkBoxToolBarHide_stateChanged(int arg1)
{
    // ToolBar hide
    bool act = arg1;
    emit toolBarEnable_stateChange(!act);
}

void GeneralSettingsForm::on_checkBoxStatusBarHide_stateChanged(int arg1)
{
    // StatusBar hide
    bool act = arg1;
    emit statusBarEnable_stateChange(!act);
}
