#ifndef STYLESETTINGSFORM_H
#define STYLESETTINGSFORM_H

#include <QWidget>

namespace Ui {
class StyleSettingsForm;
}

class StyleSettingsForm : public QWidget
{
    Q_OBJECT

public:
    explicit StyleSettingsForm(QWidget *parent = nullptr);
    ~StyleSettingsForm();

private:
    Ui::StyleSettingsForm *ui;
};

#endif // STYLESETTINGSFORM_H
