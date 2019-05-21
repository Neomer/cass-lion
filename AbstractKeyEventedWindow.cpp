//
// Created by kir on 21.05.19.
//
#include <glib.h>
#include <iostream>
#include "AbstractKeyEventedWindow.h"

AbstractKeyEventedWindow::AbstractKeyEventedWindow() {

}

AbstractKeyEventedWindow::~AbstractKeyEventedWindow() {

}

bool AbstractKeyEventedWindow::on_key_press_event(GdkEventKey *key_event) {
    if (!key_event->is_modifier) {
        KeyCombination keyCombination;
        keyCombination.setKey(key_event->keyval);

        auto mod = key_event->state & gtk_accelerator_get_default_mod_mask();
        if (mod & GDK_CONTROL_MASK) {
            keyCombination.setModifier(KeyCombination::CTRL);
        }
        if (mod & GDK_MOD1_MASK) {
            keyCombination.setModifier(KeyCombination::ALT);
        }
        if (mod & GDK_SHIFT_MASK) {
            keyCombination.setModifier(KeyCombination::SHIFT);
        }
        onKeyCombinationPressed(keyCombination);
    }
    return Widget::on_key_press_event(key_event);
}

bool AbstractKeyEventedWindow::on_key_release_event(GdkEventKey *key_event) {
    return Widget::on_key_release_event(key_event);
}
