#include <iostream>
#include <gtkmm/application.h>
#include "MainWindow.h"
#include "ApplicationContext.h"

int main(int argc, char **argv) {
    auto app = Gtk::Application::create(argc, argv);

    const char *cfgFilename = "config/context.xml";
    ApplicationContext::getInstance().load(cfgFilename);

    MainWindow mainWindow;

    auto result = app->run(mainWindow);

    ApplicationContext::getInstance().unload(cfgFilename);

    return result;
}