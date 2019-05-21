//
// Created by kir on 21.05.19.
//
#include <glib.h>
#include "KeyCombination.h"

KeyCombination::KeyCombination() : _key{ 0 } {

}

KeyCombination::KeyCombination(int key, KeyCombination::Modifier modifier) {
    _key = (static_cast<guint64>(modifier) << 56) | (key & 0x0fffffff);
}


KeyCombination::~KeyCombination() {

}

int KeyCombination::getKey() const {
    return _key & 0x0fffffff;
}

void KeyCombination::setKey(int key) {
    _key |= key & 0x0fffffff;
}

void KeyCombination::setModifier(KeyCombination::Modifier modifier) {
    _key |= (static_cast<guint64>(modifier) << 56);
}

bool KeyCombination::is(const KeyCombination &other) const {
    return _key == other._key;
}

bool KeyCombination::is(int key, KeyCombination::Modifier modifier) const {
    return _key == ((static_cast<guint64>(modifier) << 56) | (key & 0x0fffffff));
}

bool KeyCombination::is(int key) const {
    return is(key, NONE);
}


