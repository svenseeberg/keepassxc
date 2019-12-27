/*
 *  Copyright (C) 2018 KeePassXC Team <team@keepassxc.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEEPASSXC_OPENPGPEDITWIDGET_H
#define KEEPASSXC_OPENPGPEDITWIDGET_H

#include "KeyComponentWidget.h"
#include <QPointer>

namespace Ui
{
    class OpenPGPEditWidget;
}

class OpenPGPKey;

class OpenPGPEditWidget : public KeyComponentWidget
{
    Q_OBJECT

public:
    explicit OpenPGPEditWidget(QWidget* parent = nullptr);
    Q_DISABLE_COPY(OpenPGPEditWidget);
    ~OpenPGPEditWidget() override;

    bool addToCompositeKey(QSharedPointer<CompositeKey> key) override;
    bool validate(QString& errorMessage) const override;

protected:
    QWidget* componentEditWidget() override;
    void initComponentEditWidget(QWidget* widget) override;

private slots:
    void listAvailableKeys();

private:
    const QScopedPointer<Ui::OpenPGPEditWidget> m_compUi;
    QPointer<QWidget> m_compEditWidget;
    bool m_isDetected = false;
};

#endif // KEEPASSXC_OPENPGPEDITWIDGET_H