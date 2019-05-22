//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_MAINWINDOW_H
#define CASS_LION_MAINWINDOW_H

#include <gtkmm/statusbar.h>
#include <gtkmm/box.h>
#include <gtkmm/menubar.h>

#include "AbstractWindowWithShortcuts.h"

class MainWindow : public AbstractWindowWithShortcuts
{
public:
    MainWindow();
    virtual ~MainWindow() override;

protected:
    void onSearchRequest() const override;
    void onUnrecognizedShortcut(const KeyCombination &keyCombination) override;

private:
    Gtk::Box _mainLayout, _contentLayout;
    Gtk::MenuBar _menuBar;
    Gtk::Statusbar _statusBar;
};


#endif //CASS_LION_MAINWINDOW_H
