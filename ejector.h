/*****************************************************************************
ejector-tray, A simple tray app to eject and insert default CD/DVD tray
Copyright (C) 2012 MD: Minhazul Haque;
mdminhazulhaque@gmail.com.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#ifndef EJECTOR_H
#define EJECTOR_H

#include <QWidget>
#include <QProcess>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QIcon>
 #include <QApplication>

class Ejector : public QWidget
{
    Q_OBJECT
    
public:
    explicit Ejector(QWidget *parent = 0);
    ~Ejector();

public slots:
    void manageTray();

private:
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *eject_close;
    QAction *quit;
    QIcon trayIconMain;
    QIcon ejectIcon;
    QIcon quitIcon;
    QIcon closeIcon;
    QString cmdEject;
    QString cmdClose;
    bool isEjected;
};

#endif // EJECTOR_H
