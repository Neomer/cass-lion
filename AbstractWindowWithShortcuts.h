//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_ABSTRACTWINDOWWITHSHORTCUTS_H
#define CASS_LION_ABSTRACTWINDOWWITHSHORTCUTS_H

#include "AbstractKeyEventedWindow.h"

/**
 * Абстрактный класс, обрабатывающий стандартные сочетания клавиш.
 * При обнаружении известного сочетания клавиш, вызывается соответствующий виртуальный метод, любой из которых может быть переопределен в наследниках.
 * Если же сочетание не опознано, то сочетание клавиш отправляется в метод onUnrecognizedShortcut(const KeyCombination &keyCombination).
 */
class AbstractWindowWithShortcuts : public AbstractKeyEventedWindow {
public:
    AbstractWindowWithShortcuts();

    virtual ~AbstractWindowWithShortcuts();

protected:
    void onKeyCombinationPressed(const KeyCombination &keyCombination) override final;

protected:
    virtual void onSearchRequest() const;
    virtual void onUnrecognizedShortcut(const KeyCombination &keyCombination) = 0;
};


#endif //CASS_LION_ABSTRACTWINDOWWITHSHORTCUTS_H
