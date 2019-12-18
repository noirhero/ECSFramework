// Copyright 2018-2019 TAP, Inc. All Rights Reserved.

#pragma once

class IntroLayer : public Layer {
public:
    bool init() override;

private:
    void CompleteIntro();
};
