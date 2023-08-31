#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include <QDialog>
#include "globalsettings.h"

namespace Ui {
class SettingsForm;
}

class SettingsForm : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsForm(QWidget *parent = 0);
    ~SettingsForm();

private slots:
    void on_saveButton_clicked();

private:
    Ui::SettingsForm *ui;
};

#endif // SETTINGSFORM_H
