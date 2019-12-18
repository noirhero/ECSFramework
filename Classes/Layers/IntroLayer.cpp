// Copyright 2018-2019 TAP, Inc. All Rights Reserved.

#include "../../pch.h"
#include "IntroLayer.h"

#include "../Utils/UtilPCH.h"

bool IntroLayer::init() {
    const auto visibleSize = Director::getInstance()->getVisibleSize();
    const auto origin = Director::getInstance()->getVisibleOrigin();

    auto sprite = Sprite::create("loading_title_a0.pvr.ccz");
    if (sprite == nullptr) {
        return false;
    }
    else {
        const auto scaleRatio = visibleSize.width / sprite->getContentSize().width;
        sprite->setOpacity(0);
        sprite->setScale(scaleRatio);
        sprite->setPosition(Vec2(visibleSize.width * 0.5f + origin.x, visibleSize.height * 0.5f + origin.y));
        addChild(sprite, 0);

        constexpr auto delay = 1.0f;
        const auto completeFn = CallFuncN::create(CC_CALLBACK_0(IntroLayer::CompleteIntro, this));
        sprite->runAction(Sequence::create(FadeIn::create(delay), DelayTime::create(delay), FadeOut::create(delay), completeFn, nullptr));
    }

    return true;
}

void IntroLayer::CompleteIntro() {
    CCLOG("Sequence complete!!!!!");

    UtilLayer::ChangeAndThenDelete(new IntroLayer, this);
}
