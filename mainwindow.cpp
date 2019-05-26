#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);

    ui->plainTextEdit->setTabStopDistance(40);

    settings = new Settings();
    compiler = new Compiler(settings->compiler->getPath());

    settingsWindow = new SettingsWindow(this);
}

MainWindow::~MainWindow()
{
    delete settingsWindow;
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    // create new file
    _fileName = "new";
    ui->plainTextEdit->clear();
}

void MainWindow::on_actionOpen_triggered()
{
    // open file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open a file"));

    if (fileName.isEmpty()) return;

    QFile file(fileName);

    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        QString text = in.readAll();
        ui->plainTextEdit->setPlainText(text);

        _fileName = fileName;
        file.close();
    }
}

void MainWindow::on_actionClose_triggered()
{
    // close file
    on_actionNew_triggered();
}

void MainWindow::on_actionSave_triggered()
{
    // save file
    QFile file(_fileName);

    if(file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&file);
        out << ui->plainTextEdit->toPlainText();

        file.flush();
        file.close();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    // save file as...
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save as..."), _fileName,
                                                    tr("All types (*.*);;"
                                                       "Normal text file (*.txt;*.lol);;"
                                                       "C source file (*.c;*.h);;"
                                                       "C++ source file (*.cpp;*.hpp)"));

    if (fileName.isEmpty()) return;

    _fileName = fileName;
    on_actionSave_triggered();
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
    settingsWindow->show();
}

void MainWindow::on_actionBuild_triggered()
{
    // compiling
    compiler->compiling(_fileName);
}

void MainWindow::on_actionBuild_with_parameters_triggered()
{
    // compiling with params
    compiler->compiling(_fileName, settings->compiler->getParams());
}

void MainWindow::on_plainTextEdit_undoAvailable(bool b)
{
    ui->actionUndo->setEnabled(b);
}

void MainWindow::on_plainTextEdit_redoAvailable(bool b)
{
    ui->actionRedo->setEnabled(b);
}

void MainWindow::on_plainTextEdit_copyAvailable(bool b)
{
    ui->actionCopy->setEnabled(b);
}

void MainWindow::on_toolBarEnable_stateChange(bool b)
{
    settings->toolBar->setEnable(b);
    b ? ui->mainToolBar->show() : ui->mainToolBar->hide();
}

void MainWindow::on_statusBarEnable_stateChange(bool b)
{
    settings->statusBar->setEnable(b);
    b ? ui->statusBar->show() : ui->statusBar->hide();
}

void MainWindow::on_plainTextEdit_fontChange(const QString &arg)
{
    settings->style->setFont(arg);
    QFont font(arg, 12);
    ui->plainTextEdit->setFont(font);
}

void MainWindow::on_plainTextEdit_fontSizeChange(int arg)
{
    settings->style->setFontSize(arg);
    auto font = ui->plainTextEdit->font();
    font.setPointSize(arg);
    ui->plainTextEdit->setFont(font);
}

void MainWindow::on_plainTextEdit_fontColorChange(QColor color)
{
    settings->style->setFontColor(color);
    QString qss = QString("QPlainTextEdit{color: %1; background-color: %2;l}").arg(color.name(), settings->style->getBackgroundColor().name());
    ui->plainTextEdit->setStyleSheet(qss);
}

void MainWindow::on_plainTextEdit_backgroundColorChange(QColor color)
{
    settings->style->setBackgroundColor(color);
    QString qss = QString("QPlainTextEdit{background-color: %1; color: %2;}").arg(color.name(), settings->style->getFontColor().name());
    ui->plainTextEdit->setStyleSheet(qss);
}

void MainWindow::on_changeCompiler(const QString str)
{
    settings->compiler->setPath(str);
    compiler->changePath(str);
}

void MainWindow::on_changeCompilingParams(const QString str)
{
    settings->compiler->setParams(str);
}
