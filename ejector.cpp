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

#include "ejector.h"

Ejector::Ejector(QWidget *parent) : QWidget(parent)
{
    isEjected = false;

    trayIcon = new QSystemTrayIcon(this);
    eject_close = new  QAction(tr("&Eject"),this);
    quit = new QAction(tr("&Quit"),this);

    trayIconMenu = new QMenu(this);
    trayIconMain = QIcon(QPixmap(":/icon"));
    ejectIcon = QIcon(QPixmap(":/eject"));
    quitIcon = QIcon(QPixmap(":/quit"));
    closeIcon = QIcon(QPixmap(":/close"));

    cmdEject = QString("eject -t /dev/sr0");
    cmdClose = QString("eject /dev/sr0");


    eject_close->setCheckable(false);
    quit->setCheckable(false);

    eject_close->setIcon(ejectIcon);
    quit->setIcon(quitIcon);
    trayIcon->setIcon(trayIconMain);
    trayIconMenu->addAction(eject_close);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quit);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->show();

    connect(eject_close, SIGNAL(triggered()), this, SLOT(manageTray()));
    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
}

Ejector::~Ejector()
{
    delete trayIcon;
    delete trayIconMenu;
    delete eject_close;
    delete quit;
}

void Ejector::manageTray()
{
    if(isEjected)
    {
        QProcess::startDetached(cmdEject);
        isEjected = false;
        eject_close->setText("&Eject");
        eject_close->setIcon(ejectIcon);
    }
    else
    {
        QProcess::startDetached(cmdClose);
        isEjected = true;
        eject_close->setText("&Close");
        eject_close->setIcon(closeIcon);
    }
}
