//
// Created by kir on 23.05.19.
//

#ifndef CASS_LION_DATABASECONNECTIONSTATUSWIDGET_H
#define CASS_LION_DATABASECONNECTIONSTATUSWIDGET_H

#include <gtkmm/label.h>

class DatabaseConnectionStatusWidget : public Gtk::Label
{
public:
    DatabaseConnectionStatusWidget();

    virtual ~DatabaseConnectionStatusWidget();
};


#endif //CASS_LION_DATABASECONNECTIONSTATUSWIDGET_H
