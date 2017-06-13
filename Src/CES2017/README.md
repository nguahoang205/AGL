Open source QML UI

To run on target:
$ cd /usr/AGL/CES2017
$ /usr/bin/qt5/qmlscene -I imports Main.qml

For development it can be nice to use Scaled.qml instead so it fits your screen.



© 2015 Jaguar Land Rover. All Rights Reserved.
Licensed under Creative Commons Attribution 4.0 International
https://creativecommons.org/licenses/by/4.0/legalcode

(Optional) switch shell for weston to ivi-shell and start demo apps if you want to start demo apps with ivi-shell.
$ cd /usr/AGL/CES2017
$ ./switch_to_ivi-shell
(Option a) $ ./start_ALS2016_ivi-shell.sh
(Option b) $ ./start_ALS2016_with_navi_ivi-shell.sh

Option a: start QML UI only.
Option b: start QML + CarNavigation:/home/navi. For the time being, CarNavigation expects to be Wayland native application, which will be showed on top of QML by using LayerManagerControl.

