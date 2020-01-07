// Copyright 2018-2020 TAP, Inc. All Rights Reserved.

#include "../pch.h"
#include "HelloWorldLayer.h"

#include "../Components/ComponentPCH.h"
#include "../FrameworkScene.h"

bool HelloWorldLayer::init() {
    const auto visibleSize = Director::getInstance()->getVisibleSize();
    const auto origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", HelloWorldLayer::ClickCloseButton);

    if (closeItem == nullptr || closeItem->getContentSize().width <= 0 || closeItem->getContentSize().height <= 0) {
        return false;
    }
    else {
        const auto x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        const auto y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    gsl::not_null<Menu*> menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr) {
        return false;
    }
    else {
        label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
        addChild(label, 1);
    }

    auto sprite = Sprite::create("loading_title_a0.pvr.ccz");
    if(sprite == nullptr) {
        return false;
    }
    else {
        const auto scaleRatio = visibleSize.width / sprite->getContentSize().width;
        sprite->setScale(scaleRatio);
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        sprite->setGlobalZOrder(-1);
        addChild(sprite, 0);
    }

    auto character = Sprite3D::create("ch02_01.c3b");
    if (character == nullptr) {
        return false;
    }
    else {
        character->setScale(5.0f);
        character->setRotation3D({ 0.0f, 0.0f, 0.0f });
        character->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        const auto animation = Animation3D::create("ch02_01_idle01.c3b");
        const auto animate = Animate3D::create(animation);
        character->runAction(RepeatForever::create(animate));

        auto& world = gsl::not_null<FrameworkScene*>(static_cast<FrameworkScene*>(getScene()))->GetWorld();
        const auto entity = world.create();
        world.assign<ComponentInputBind>(entity);
        world.assign<ComponentPos>(entity, character->getPosition3D());
        world.assign<ComponentVelocity>(entity);
        world.assign<ComponentSprite3D>(entity, character);

        addChild(character, 1);
    }

    return true;
}

void HelloWorldLayer::ClickCloseButton(cocos2d::Ref* /*sender*/) {
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
