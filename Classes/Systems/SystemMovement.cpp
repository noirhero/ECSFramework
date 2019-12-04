// Copyright 2018-2019 TAP, Inc. All Rights Reserved.

#include "../../pch.h"
#include "SystemMovement.h"

#include "../Components/ComponentPCH.h"

namespace SystemMovement {
    void Update(entt::DefaultRegistry& world, float delta) {
        world.view<ComponentPos, ComponentVelocity>().each([&world, delta](auto entity, auto& pos, auto& velocity) {
            pos.value += velocity.value * delta;

            if(world.has<ComponentSprite3D>(entity)) {
                auto& compSpr3D = world.get<ComponentSprite3D>(entity);
                compSpr3D.ptr->setPosition3D(pos.value);
            }
        });
    }

}
