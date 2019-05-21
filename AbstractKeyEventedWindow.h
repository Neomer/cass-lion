//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_ABSTRACTKEYEVENTEDWINDOW_H
#define CASS_LION_ABSTRACTKEYEVENTEDWINDOW_H

#include "KeyCombination.h"
#include <gtkmm/window.h>

class AbstractKeyEventedWindow : public Gtk::Window {

public:
    AbstractKeyEventedWindow();
    virtual ~AbstractKeyEventedWindow() override;

protected:
    bool on_key_press_event(GdkEventKey *key_event) override final;
    bool on_key_release_event(GdkEventKey *key_event) override final;

protected:
    virtual void onKeyCombinationPressed(const KeyCombination &keyCombination) = 0;

private:
    KeyCombination::Modifier _modifier;
};


#endif //CASS_LION_ABSTRACTKEYEVENTEDWINDOW_H
