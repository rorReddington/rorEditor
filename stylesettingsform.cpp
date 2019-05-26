#include "stylesettingsform.h"
#include "ui_stylesettingsform.h"

StyleSettingsForm::StyleSettingsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StyleSettingsForm)
{
    ui->setupUi(this);

    ui->pushButtonBackColor->setStyleSheet("border: none; background-color: white");
    ui->pushButtonFontColor->setStyleSheet("border: none; background-color: black");

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

    QObject::connect(this, SIGNAL(font_change(const QString&)), parent, SLOT(on_plainTextEdit_fontChange(const QString&)));
    QObject::connect(this, SIGNAL(fontSize_change(int)), parent, SLOT(on_plainTextEdit_fontSizeChange(int)));

    QObject::connect(this, SIGNAL(backColor_change(QColor)), parent, SLOT(on_plainTextEdit_fontColorChange(QColor)));
    QObject::connect(this, SIGNAL(fontColor_change(QColor)), parent, SLOT(on_plainTextEdit_backgroundColorChange(QColor)));
}

StyleSettingsForm::~StyleSettingsForm()
{
    delete ui;
}

void StyleSettingsForm::changeColorButton(QPushButton *button, QColor &color)
{
    QString qss = QString("border: none;background-color: %1").arg(color.name());
    button->setStyleSheet(qss);
}

QColor StyleSettingsForm::getByDialog(const QString text)
{
    QColor color = QColorDialog::getColor(Qt::white, this, text);

    if(color.isValid())
        return color;
    return nullptr;
}

void StyleSettingsForm::on_comboBoxFont_currentIndexChanged(const QString &arg1)
{
    emit font_change(arg1);
}

void StyleSettingsForm::on_comboBoxFontSize_currentIndexChanged(const QString &arg1)
{
    int size = arg1.toInt();
    emit fontSize_change(size);
}

void StyleSettingsForm::on_pushButtonFontColor_clicked()
{
    QColor color = getByDialog("Select font color");

    if (color != nullptr)
    {
        changeColorButton(ui->pushButtonFontColor, color);
        emit fontColor_change(color);
    }
}

void StyleSettingsForm::on_pushButtonBackColor_clicked()
{
    QColor color = getByDialog("Select font color");

    if (color != nullptr)
    {
        changeColorButton(ui->pushButtonBackColor, color);
        emit backColor_change(color);
    }
}
