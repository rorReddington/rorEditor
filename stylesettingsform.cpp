#include "stylesettingsform.h"
#include "ui_stylesettingsform.h"

StyleSettingsForm::StyleSettingsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StyleSettingsForm)
{
    ui->setupUi(this);
}

StyleSettingsForm::~StyleSettingsForm()
{
    delete ui;
}
