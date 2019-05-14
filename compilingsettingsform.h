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

private slots:
    void on_toolButton_clicked();

private:
    Ui::CompilingSettingsForm *ui;
};

#endif // COMPILINGSETTINGSFORM_H
