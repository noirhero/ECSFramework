#pragma once

class FrameworkScene : public Scene {
public:
    bool                    init() override;
    void                    update(float delta) override;

    entt::DefaultRegistry&  GetWorld() { return _world; }

private:
    entt::DefaultRegistry   _world;
};
