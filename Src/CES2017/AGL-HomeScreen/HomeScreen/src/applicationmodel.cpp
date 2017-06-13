/*
 * Copyright (C) 2016 The Qt Company Ltd.
 * Copyright (C) 2016 Mentor Graphics Development (Deutschland) GmbH
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "applicationmodel.h"
#include "appinfo.h"

#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusReply>

class ApplicationModel::Private
{
public:
    Private(ApplicationModel *parent);

private:
    ApplicationModel *q;
public:
    QDBusInterface proxy;
    QList<AppInfo> data;
};

ApplicationModel::Private::Private(ApplicationModel *parent)
    : q(parent)
    , proxy(QStringLiteral("org.agl.homescreenappframeworkbinder"), QStringLiteral("/AppFramework"), QStringLiteral("org.agl.appframework"), QDBusConnection::sessionBus())
{
    QDBusReply<QList<AppInfo>> reply = proxy.call("getAvailableApps");
    if (false)/*reply.isValid()) TODO: test for CES!  */ {
        data = reply.value();
    } else {
        data.append(AppInfo(QStringLiteral("HVAC"), QStringLiteral("HVAC"), QStringLiteral("hvac@0.1")));
        data.append(AppInfo(QStringLiteral("Navigation"), QStringLiteral("NAVIGATION"), QStringLiteral("navigation@0.1")));
        data.append(AppInfo(QStringLiteral("Phone"), QStringLiteral("PHONE"), QStringLiteral("phone@0.1")));
        data.append(AppInfo(QStringLiteral("Radio"), QStringLiteral("RADIO"), QStringLiteral("radio@0.1")));
        data.append(AppInfo(QStringLiteral("Multimedia"), QStringLiteral("MULTIMEDIA"), QStringLiteral("mediaplayer@0.1")));
        data.append(AppInfo(QStringLiteral("Connectivity"), QStringLiteral("CONNECTIVITY"), QStringLiteral("connectivity@0.1")));
        data.append(AppInfo(QStringLiteral("Dashboard"), QStringLiteral("DASHBOARD"), QStringLiteral("dashboard@0.1")));
        data.append(AppInfo(QStringLiteral("Settings"), QStringLiteral("SETTINGS"), QStringLiteral("settings@0.1")));
        data.append(AppInfo(QStringLiteral("POI"), QStringLiteral("POINT OF\nINTEREST"), QStringLiteral("poi@0.1")));
    }
}

ApplicationModel::ApplicationModel(QObject *parent)
    : QAbstractListModel(parent)
    , d(new Private(this))
{
}

ApplicationModel::~ApplicationModel()
{
    delete d;
}

int ApplicationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return d->data.count();
}

QVariant ApplicationModel::data(const QModelIndex &index, int role) const
{
    QVariant ret;
    if (!index.isValid())
        return ret;

    switch (role) {
    case Qt::DecorationRole:
        ret = d->data[index.row()].iconPath();
        break;
    case Qt::DisplayRole:
        ret = d->data[index.row()].name();
        break;
    case Qt::UserRole:
        ret = d->data[index.row()].id();
        break;
    default:
        break;
    }

    return ret;
}

QHash<int, QByteArray> ApplicationModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DecorationRole] = "icon";
    roles[Qt::DisplayRole] = "name";
    roles[Qt::UserRole] = "id";
    return roles;
}
