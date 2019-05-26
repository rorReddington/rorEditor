#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QFileDialog>

#include <settingswindow.h>
#include <compiler.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionClose_triggered();

    void on_actionExit_triggered();

    void on_actionPrefereces_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionDelete_triggered();

    void on_actionSelect_all_triggered();

    void on_plainTextEdit_undoAvailable(bool b);

    void on_plainTextEdit_redoAvailable(bool b);

    void on_plainTextEdit_copyAvailable(bool b);

    void on_toolBarEnable_stateChange(bool b);

    void on_statusBarEnable_stateChange(bool b);

    void on_plainTextEdit_fontChange(const QString &arg);

    void on_plainTextEdit_fontSizeChange(int arg);

    void on_plainTextEdit_fontColorChange(QColor color);

    void on_plainTextEdit_backgroundColorChange(QColor color);

    void on_changeCompilingParams(const QString);

    void on_changeCompiler(const QString);

    void on_actionBuild_triggered();

    void on_actionBuild_with_parameters_triggered();

    void on_plainTextEdit_textChanged();

    void on_plainTextEdit_selectionChanged();

private:
    Ui::MainWindow *ui;
    SettingsWindow *settingsWindow;

    Settings *settings;
    Compiler *compiler;
    QString _fileName;

    void updateStatusBar();
};

#endif // MAINWINDOW_H
