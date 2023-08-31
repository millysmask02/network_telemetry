#include "settingsform.h"
#include "ui_settingsform.h"

SettingsForm::SettingsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsForm)
{
    ui->setupUi(this);

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(accept()));
    ConnectionSettings& data = GlobalSettings::instance().connection;
    ui->protocolBox->addItem(protocolToString(Protocol::Udp), QVariant::fromValue(Protocol::Udp));
    ui->protocolBox->addItem(protocolToString(Protocol::Tcp), QVariant::fromValue(Protocol::Tcp));
    ui->protocolBox->addItem(protocolToString(Protocol::Psovp), QVariant::fromValue(Protocol::Psovp));
    ui->clientLine->setText(data.clientName);
    ui->serverLine->setText(data.serverName);
    int idx = -1;
    for (int i = 0; i < ui->protocolBox->count(); i++) {
        if (data.protocol == ui->protocolBox->itemData(i).value<Protocol>()) {
            idx = i;
        }
    }
    ui->protocolBox->setCurrentIndex(idx);

    MessageSettings& message = GlobalSettings::instance().messageSettings;
    ui->messageSizeEdit->setText(QString::number(message.size));
    ui->messageIntervalEdit->setText(QString::number(message.interval));
    ui->messageCountEdit->setText(QString::number(message.count));
}

SettingsForm::~SettingsForm()
{
    delete ui;
}

void SettingsForm::on_saveButton_clicked()
{
    ConnectionSettings& data = GlobalSettings::instance().connection;
    data.protocol = protocolFromString(ui->protocolBox->currentText());
    data.serverName = ui->serverLine->text();
    data.clientName = ui->clientLine->text();

    MessageSettings& message = GlobalSettings::instance().messageSettings;
    message.size = ui->messageSizeEdit->text().toInt();
    message.interval = ui->messageIntervalEdit->text().toInt();
    message.count = ui->messageCountEdit->text().toInt();

    GlobalSettings::instance().save();
}
