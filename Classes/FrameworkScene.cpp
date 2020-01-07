// Copyright 2018-2020 TAP, Inc. All Rights Reserved.

#include "../pch.h"
#include "FrameworkScene.h"

#include "Utils/UtilPCH.h"
#include "Systems/SystemPCH.h"
#include "Layers/IntroLayer.h"

FrameworkScene::~FrameworkScene() {
    UtilSound::StopAll();
    UtilSound::End();
}

bool FrameworkScene::init() {
    if (false == Scene::init()) {
        return false;
    }

    if (false == SystemInputKeyboard::Initialize(*this)) {
        return false;
    }

    gsl::not_null<Layer*> introLayer = new IntroLayer();
    introLayer->autorelease();
    addChild(introLayer);

    if (false == introLayer->init()) {
        removeChild(introLayer);
        return false;
    }

    scheduleUpdate();
    return true;
}

void FrameworkScene::update(float delta) {
    SystemVelocity::Update(_world, delta);
    SystemMovement::Update(_world, delta);
}
