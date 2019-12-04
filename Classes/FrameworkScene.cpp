// Copyright 2018-2019 TAP, Inc. All Rights Reserved.

#include "../pch.h"
#include "FrameworkScene.h"

#include "Systems/SystemPCH.h"
#include "Layers/HelloWorldLayer.h"

bool FrameworkScene::init() {
    if (false == Scene::init()) {
        return false;
    }

    if(false == SystemInputKeyboard::Initialize(*this)) {
        return false;
    }

    gsl::not_null<Layer*> introLayer = new HelloWorldLayer();
    addChild(introLayer);

    if(false == introLayer->init()) {
        removeChild(introLayer);
        delete introLayer;
        return false;
    }

    scheduleUpdate();
    return true;
}

void FrameworkScene::update(float delta) {
    SystemInputKeyboard::Update(_world, delta);
    SystemMovement::Update(_world, delta);
}
