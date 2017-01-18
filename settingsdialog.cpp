/*
 * -----------------------------------
 * QtSysMonitor
 * -----------------------------------
 *
 * This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * ---------------------------------------------------------------------------
 * Started By: Navjot Singh <weavebytes@gmail.com> in November 2016
 *
 * Organization:Weavebytes Infotech Pvt Ltd
 * ---------------------------------------------------------------------------
 */

#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QDebug>
#include <QSpinBox>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    setModal(true);
    setFixedSize(width(), height());

    ui->processSpinBox->setValue(settings.value("timer/process").toInt());
    ui->socketSpinBox->setValue(settings.value("timer/socket").toInt());
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_btnSaveSettings_clicked()
{
    QSpinBox *box = ui->processSpinBox;
    settings.setValue("timer/process",box->value());
    box = ui->socketSpinBox;
    settings.setValue("timer/socket",box->value());
    emit settingsChanged();
    hide();
}

void SettingsDialog::on_btnCancelSettings_clicked()
{
     hide();
}
