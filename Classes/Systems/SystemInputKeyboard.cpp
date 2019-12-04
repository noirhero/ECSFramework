// Copyright 2018-2019 TAP, Inc. All Rights Reserved.

#include "../../pch.h"
#include "SystemInputKeyboard.h"

#include "../Components/ComponentPCH.h"

using namespace cocos2d;

namespace SystemInputKeyboard {
    std::unique_ptr<EventListenerKeyboard>  _inputListener;
    Vec3                                    _inputVelocity;

    void OnKeyPressed(EventKeyboard::KeyCode code, Event* /*event*/) {
        switch(code) {
        case EventKeyboard::KeyCode::KEY_W: _inputVelocity += Vec3::UNIT_Z; break;
        case EventKeyboard::KeyCode::KEY_S: _inputVelocity -= Vec3::UNIT_Z; break;
        default:;
        }
    }

    void OnKeyReleased(EventKeyboard::KeyCode code, Event* /*event*/) {
        switch(code) {
        case EventKeyboard::KeyCode::KEY_W: _inputVelocity -= Vec3::UNIT_Z; break;
        case EventKeyboard::KeyCode::KEY_S: _inputVelocity += Vec3::UNIT_Z; break;
        default:;
        }
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

    void Update(entt::DefaultRegistry& world, float /*delta*/) {
        world.view<ComponentVelocity>().each([](auto entity, auto& velocity) -> void {
            velocity.value += _inputVelocity;
        });
    }

}
