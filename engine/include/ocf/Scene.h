// SPDX - License - Identifier : MIT
#pragma once

namespace ocf {

class Scene {
public:
    Scene();
    virtual ~Scene();

    void update(float deltaTime);

private:
};

} // namespace ocf