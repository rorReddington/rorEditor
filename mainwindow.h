#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QFileDialog>

#include <settingswindow.h>

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

private:
    Ui::MainWindow *ui;
    SettingsWindow *settings;

    QString _fileName;
};

#endif // MAINWINDOW_H
