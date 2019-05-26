#ifndef STYLESETTINGSFORM_H
#define STYLESETTINGSFORM_H

#include <QWidget>
#include <QFontDatabase>
#include <QColorDialog>

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
   void fontSize_change(int);
   void backColor_change(QColor);
   void fontColor_change(QColor);

private slots:
    void on_comboBoxFont_currentIndexChanged(const QString &arg1);
    void on_comboBoxFontSize_currentIndexChanged(const QString &arg1);
    void on_pushButtonFontColor_clicked();
    void on_pushButtonBackColor_clicked();

private:
    Ui::StyleSettingsForm *ui;

    void changeColorButton(QPushButton *button, QColor &color);
    QColor getByDialog(const QString text);
};

#endif // STYLESETTINGSFORM_H
