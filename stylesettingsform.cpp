#include "stylesettingsform.h"
#include "ui_stylesettingsform.h"

StyleSettingsForm::StyleSettingsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StyleSettingsForm)
{
    ui->setupUi(this);

    //bool ok;
    //auto font = QFontDialog::getFont(&ok, this);

    auto fonts = QFontDatabase().families();
    QList<QString> sizes;
    sizes << "8" << "9" << "10" << "11" << "12" << "13" << "14" << "16" << "18" << "20" << "22" << "24" << "26" << "28";

    /*foreach (auto font, fonts)
    {
        qDebug() << font;
    }*/

    ui->comboBoxFont->addItems(fonts);
    ui->comboBoxFontSize->addItems(sizes);

    QObject::connect(this, SIGNAL(font_change(const QString&)), parent, SLOT(on_font_change(const QString&)));
    QObject::connect(this, SIGNAL(fontSize_change(const QString&)), parent, SLOT(on_fontSize_change(const QString&)));
}

StyleSettingsForm::~StyleSettingsForm()
{
    delete ui;
}

void StyleSettingsForm::on_comboBoxFont_currentIndexChanged(const QString &arg1)
{
    emit font_change(arg1);
}

void StyleSettingsForm::on_comboBoxFontSize_currentIndexChanged(const QString &arg1)
{
    emit fontSize_change(arg1);
}
