// Copyright 2018-2020 TAP, Inc. All Rights Reserved.

#include "../../pch.h"
#include "MainLayer.h"

#include "../Utils/UtilPCH.h"

bool MainLayer::init() {
    const auto size = Director::getInstance()->getVisibleSize();
    const auto origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("lobby_background_a0.pvr.ccz");
    if (nullptr == background) {
        return false;
    }
    const auto scaleRatio = size.width / background->getContentSize().width;
    background->setScale(scaleRatio);
    background->setPosition({ size.width * 0.5f + origin.x, size.height * 0.5f + origin.y });
    addChild(background);

    UtilSound::PlayBGM("sounds/intro.mp3");

    return true;
}
