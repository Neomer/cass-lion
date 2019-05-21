//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_KEYCOMBINATION_H
#define CASS_LION_KEYCOMBINATION_H

#include <glibconfig.h>

class KeyCombination {

public:
    enum Modifier
    {
        NONE = 0,
        ALT = 1,
        CTRL = 2,
        SHIFT = 4
    };

    KeyCombination();
    KeyCombination(int key, Modifier modifier);

    virtual ~KeyCombination();

    int getKey() const;

    bool is(const KeyCombination &other) const;
    bool is(int key, Modifier modifier) const;
    bool is(int key) const;

    void setKey(int key);
    void setModifier(Modifier modifier);

private:
    guint64 _key;
};


#endif //CASS_LION_KEYCOMBINATION_H
