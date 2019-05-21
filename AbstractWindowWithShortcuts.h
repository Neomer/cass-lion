//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_ABSTRACTWINDOWWITHSHORTCUTS_H
#define CASS_LION_ABSTRACTWINDOWWITHSHORTCUTS_H

#include "AbstractKeyEventedWindow.h"

class AbstractWindowWithShortcuts : public AbstractKeyEventedWindow {
public:
    AbstractWindowWithShortcuts();

    virtual ~AbstractWindowWithShortcuts();

protected:
    void onKeyCombinationPressed(const KeyCombination &keyCombination) override final;

protected:
    virtual void onSearchRequest() const;
};


#endif //CASS_LION_ABSTRACTWINDOWWITHSHORTCUTS_H
