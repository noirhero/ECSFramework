// Copyright 2018-2020 TAP, Inc. All Rights Reserved.

#include "../../pch.h"
#include "SystemInputKeyboard.h"

namespace SystemInputKeyboard {
    std::unique_ptr<EventListenerKeyboard>  _inputListener;
    std::set<EventKeyboard::KeyCode>        _pressCodes;

    void OnKeyPressed(EventKeyboard::KeyCode code, Event* /*event*/) {
        _pressCodes.insert(code);
    }

    void OnKeyReleased(EventKeyboard::KeyCode code, Event* /*event*/) {
        _pressCodes.erase(code);
    }

    bool IsPress(EventKeyboard::KeyCode code) {
        return (_pressCodes.end() == _pressCodes.find(code)) ? false : true;
    }

    bool Initialize(Scene& scene) {
        _inputListener = std::make_unique<EventListenerKeyboard>();
        if (false == _inputListener->init()) {
            return false;
        }

        _inputListener->onKeyPressed = OnKeyPressed;
        _inputListener->onKeyReleased = OnKeyReleased;
        scene.getEventDispatcher()->addEventListenerWithSceneGraphPriority(_inputListener.get(), &scene);

        return true;
    }
}
