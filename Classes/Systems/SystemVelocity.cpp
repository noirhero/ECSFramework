// Copyright 2018-2020 TAP, Inc. All Rights Reserved.

#include "../../pch.h"
#include "SystemVelocity.h"

#include "../Components/ComponentPCH.h"
#include "SystemInputKeyboard.h"

namespace SystemVelocity {
    void Update(entt::DefaultRegistry& world, float /*delta*/) {
        world.view<ComponentVelocity>().each([](auto /*entity*/, auto& velocity) {
            auto currentVelocity = Vec3::ZERO;
            if (SystemInputKeyboard::IsPress(EventKeyboard::KeyCode::KEY_W))
                currentVelocity += Vec3::UNIT_Z;
            if (SystemInputKeyboard::IsPress(EventKeyboard::KeyCode::KEY_S))
                currentVelocity -= Vec3::UNIT_Z;

            velocity.value = currentVelocity;
        });
    }
}
