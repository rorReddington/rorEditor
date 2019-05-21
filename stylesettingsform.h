#ifndef STYLESETTINGSFORM_H
#define STYLESETTINGSFORM_H

#include <QWidget>
#include <QFontDatabase>

namespace Ui {
class StyleSettingsForm;
}

class StyleSettingsForm : public QWidget
{
    Q_OBJECT

public:
    explicit StyleSettingsForm(QWidget *parent = nullptr);
    ~StyleSettingsForm();

signals:
   void font_change(const QString&);
   void fontSize_change(const QString&);

private slots:
    void on_comboBoxFont_currentIndexChanged(const QString &arg1);

    void on_comboBoxFontSize_currentIndexChanged(const QString &arg1);

private:
    Ui::StyleSettingsForm *ui;
};

#endif // STYLESETTINGSFORM_H
