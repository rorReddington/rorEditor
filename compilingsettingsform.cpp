#include "compilingsettingsform.h"
#include "ui_compilingsettingsform.h"

CompilingSettingsForm::CompilingSettingsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CompilingSettingsForm)
{
    ui->setupUi(this);
}

CompilingSettingsForm::~CompilingSettingsForm()
{
    delete ui;
}

void CompilingSettingsForm::on_toolButton_clicked()
{
    // select compiler
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select a file"));

    if (fileName.isEmpty()) return;

    ui->lineEditCompiler->setText(fileName);
}
