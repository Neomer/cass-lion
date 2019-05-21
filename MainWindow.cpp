//
// Created by kir on 21.05.19.
//
#include <glib.h>
#include <iostream>
#include "MainWindow.h"

MainWindow::MainWindow() :
    AbstractWindowWithShortcuts(),
    _mainLayout{}, _contentLayout{},
    _menuBar{}, _statusBar{}
{
    _mainLayout.pack_start(_contentLayout);
    _mainLayout.pack_start(_statusBar);
    add(_mainLayout);
    show_all();
    maximize();
}

MainWindow::~MainWindow()
{

}

void MainWindow::onSearchRequest() const {

}

