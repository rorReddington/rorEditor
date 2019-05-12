#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    // create new file
}

void MainWindow::on_actionOpen_triggered()
{
    // open file
}

void MainWindow::on_actionClose_triggered()
{
    // close file
}

void MainWindow::on_actionSave_triggered()
{
    // save file
}

void MainWindow::on_actionSave_as_triggered()
{
    // save file as...
}

void MainWindow::on_actionUndo_triggered()
{
    // undo action
    ui->plainTextEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    // redo action
    ui->plainTextEdit->redo();
}

void MainWindow::on_actionExit_triggered()
{
    // exit program
    this->close();
}

void MainWindow::on_actionCopy_triggered()
{
    // copy action
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    // cut action
    ui->plainTextEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    // paste action
    ui->plainTextEdit->paste();
}

void MainWindow::on_actionDelete_triggered()
{
    // delete action
}

void MainWindow::on_actionSelect_all_triggered()
{
    // select all action
    ui->plainTextEdit->selectAll();
}

void MainWindow::on_actionPrefereces_triggered()
{
    // preferences
}
