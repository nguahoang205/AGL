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

import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.0
import Home 1.0

Item {
    id: root

    Image {
        anchors.fill: parent
        anchors.topMargin: -218
        anchors.bottomMargin: -215
        source: './images/AGL_HMI_Background_Car-01.png'
    }

    property int pid: -1

    GridView {
        anchors.centerIn: parent
        width: cellHeight * 3
        height: cellHeight * 3
        cellWidth: 320
        cellHeight: 320
        interactive: false

        model: ApplicationModel {}
        delegate: MouseArea {
            width: 320
            height: 320
            Image {
                anchors.fill: parent
                source: './images/HMI_AppLauncher_%1_%2-01.png'.arg(model.icon).arg(pressed ? 'Active' : 'Inactive')
            }
            onClicked: {
                console.log("app is ", model.id)
                pid = launcher.launch(model.id)
                if (1 < pid) {
                    layoutHandler.makeMeVisible(pid)

                    applicationArea.visible = true
                    appLauncherAreaLauncher.visible = false
                    layoutHandler.showAppLayer(pid)
                }
                else {
                    console.warn("app cannot be launched!")
                }
            }
        }
    }
}
