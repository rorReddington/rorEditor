#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint);

    QStringList params = {"General", "Style", "Compiling"};
    ui->listWidget->addItems(params);
    ui->listWidget->item(0)->setSelected(true);

    generalSettings = new GeneralSettingsForm(parent);
    styleSettings = new StyleSettingsForm(parent);
    compilingSettings = new CompilingSettingsForm(parent);
    ui->stackedWidget->insertWidget(1, generalSettings);
    ui->stackedWidget->insertWidget(2, styleSettings);
    ui->stackedWidget->insertWidget(3, compilingSettings);
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
