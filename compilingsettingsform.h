#ifndef COMPILINGSETTINGSFORM_H
#define COMPILINGSETTINGSFORM_H

#include <QWidget>
#include <QFileDialog>

namespace Ui {
class CompilingSettingsForm;
}

class CompilingSettingsForm : public QWidget
{
    Q_OBJECT

public:
    explicit CompilingSettingsForm(QWidget *parent = nullptr);
    ~CompilingSettingsForm();

signals:
    void changeCompilingParams(const QString);
    void changeCompiler(const QString);

private slots:
    void on_toolButton_clicked();
    void on_lineEditParams_editingFinished();

    void on_lineEditCompiler_editingFinished();

private:
    Ui::CompilingSettingsForm *ui;
};

#endif // COMPILINGSETTINGSFORM_H
