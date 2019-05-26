#include "compilingsettingsform.h"
#include "ui_compilingsettingsform.h"

CompilingSettingsForm::CompilingSettingsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CompilingSettingsForm)
{
    ui->setupUi(this);

    QObject::connect(this, SIGNAL(changeCompilingParams(const QString)), parent, SLOT(on_changeCompilingParams(const QString)));
    QObject::connect(this, SIGNAL(changeCompiler(const QString)), parent, SLOT(on_changeCompiler(const QString)));
}

CompilingSettingsForm::~CompilingSettingsForm()
{
    delete ui;
}

void CompilingSettingsForm::on_toolButton_clicked()
{
    // select compiler
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select file"));

    if (fileName.isEmpty()) return;

    ui->lineEditCompiler->setText(fileName);
    emit changeCompiler(fileName);
}

void CompilingSettingsForm::on_lineEditParams_editingFinished()
{
    auto str = ui->lineEditParams->text();

    if (str.isEmpty()) return;

    emit changeCompilingParams(str);
}

void CompilingSettingsForm::on_lineEditCompiler_editingFinished()
{
    auto str = ui->lineEditCompiler->text();

    if (str.isEmpty()) return;

    emit changeCompiler(str);
}
