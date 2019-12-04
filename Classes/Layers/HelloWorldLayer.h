#pragma once

class HelloWorldLayer : public Layer {
public:
    bool init() override;

    static void ClickCloseButton(Ref* sender);
};
