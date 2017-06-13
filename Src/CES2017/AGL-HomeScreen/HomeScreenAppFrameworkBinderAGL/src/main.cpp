/*
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

#include <QCoreApplication>
#include <QCommandLineParser>
#include "homescreenappframeworkbinderagl.h"

void noOutput(QtMsgType, const QMessageLogContext &, const QString &)
{
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationDomain("LinuxFoundation");
    QCoreApplication::setOrganizationName("AutomotiveGradeLinux");
    QCoreApplication::setApplicationName("HomeScreenAppFrameworkBinderAGL");
    QCoreApplication::setApplicationVersion("0.7.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("AGL Application Framwork Proxy - see wwww... for more details");
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption quietOption(QStringList() << "q" << "quiet",
        QCoreApplication::translate("main", "Be quiet. No outputs."));
    parser.addOption(quietOption);
    parser.process(a);

    if (parser.isSet(quietOption))
    {
        qInstallMessageHandler(noOutput);
    }

    qDBusRegisterMetaType<AppInfo>();
    qDBusRegisterMetaType<QList<AppInfo> >();

    HomeScreenAppFrameworkBinderAgl *tdp = new HomeScreenAppFrameworkBinderAgl();

    return a.exec();
}
