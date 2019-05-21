//
// Created by kir on 21.05.19.
//
#include <glib.h>
#include "AbstractWindowWithShortcuts.h"

AbstractWindowWithShortcuts::AbstractWindowWithShortcuts() : AbstractKeyEventedWindow() {

}

AbstractWindowWithShortcuts::~AbstractWindowWithShortcuts() {

}

void AbstractWindowWithShortcuts::onKeyCombinationPressed(const KeyCombination &keyCombination) {
    if (keyCombination.is(GDK_KEY_F3)) {
        onSearchRequest();
    } else {
        onUnrecognizedShortcut(keyCombination);
    }
}

void AbstractWindowWithShortcuts::onSearchRequest() const {

}
