#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint);

    settings = new Settings();

    QStringList params = {"General", "Style", "Compiling"};
    ui->listWidget->addItems(params);
    ui->listWidget->item(0)->setSelected(true);

    generalSettings = new GeneralSettingsForm(this);
    styleSettings = new StyleSettingsForm(this);
    compilingSettings = new CompilingSettingsForm(this);
    ui->stackedWidget->insertWidget(1, generalSettings);
    ui->stackedWidget->insertWidget(2, styleSettings);
    ui->stackedWidget->insertWidget(3, compilingSettings);

    QObject::connect(this, SIGNAL(statusBar_enable(bool)), parent, SLOT(on_statusBar_hidde(bool)));
    QObject::connect(this, SIGNAL(toolBar_enable(bool)), parent, SLOT(on_toolBar_hidde(bool)));

    QObject::connect(this, SIGNAL(plainTextEdit_fontChange(const QString&)), parent, SLOT(on_plainTextEdit_fontChange(const QString&)));
    QObject::connect(this, SIGNAL(plainTextEdit_fontSizeChange(int)), parent, SLOT(on_plainTextEdit_fontSizeChange(int)));
}

SettingsWindow::~SettingsWindow()
{
    delete generalSettings;
    delete ui;
}

void SettingsWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (current == nullptr)
        return;

    if (current->text() == QString("General"))
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if (current->text() == QString("Style"))
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if (current->text() == QString("Compiling"))
    {
        ui->stackedWidget->setCurrentIndex(3);
    }

}

void SettingsWindow::on_toolBarEnable_stateChange(int a)
{
    settings->toolBar->setEnable(!a);
    emit toolBar_enable(settings->toolBar->getEnable());
}

void SettingsWindow::on_statusBarEnable_stateChange(int a)
{
    settings->statusBar->setEnable(!a);
    emit statusBar_enable(settings->statusBar->getEnable());
}

void SettingsWindow::on_font_change(const QString &arg)
{
    settings->style->setFont(arg);
    emit plainTextEdit_fontChange(settings->style->getFont());
}

void SettingsWindow::on_fontSize_change(const QString &arg)
{
    int size = arg.toInt();
    settings->style->setFontSize(size);
    emit plainTextEdit_fontSizeChange(settings->style->getFontSize());
}
