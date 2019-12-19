// Copyright 2018-2019 TAP, Inc. All Rights Reserved.

#include "../../pch.h"
#include "IntroLayer.h"

#include "MainLayer.h"
#include "../Utils/UtilPCH.h"

bool IntroLayer::init() {
    const auto size = Director::getInstance()->getVisibleSize();
    const auto origin = Director::getInstance()->getVisibleOrigin();

    auto introImage = Sprite::create("loading_title_a0.pvr.ccz");
    if (introImage == nullptr) {
        return false;
    }
    const auto scaleRatio = size.width / introImage->getContentSize().width;
    introImage->setOpacity(0);
    introImage->setScale(scaleRatio);
    introImage->setPosition(Vec2(size.width * 0.5f + origin.x, size.height * 0.5f + origin.y));
    addChild(introImage);

    constexpr auto delay = 0.1f;
    const auto completeFn = CallFuncN::create(CC_CALLBACK_0(IntroLayer::CompleteIntro, this));
    introImage->runAction(Sequence::create(FadeIn::create(delay), DelayTime::create(delay), FadeOut::create(delay), completeFn, nullptr));

    return true;
}

void IntroLayer::CompleteIntro() {
    UtilLayer::ChangeAndThenDelete(new MainLayer, this);
}
