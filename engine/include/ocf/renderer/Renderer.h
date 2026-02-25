// SPDX - License - Identifier : MIT
#pragma once

namespace ocf {

class Scene;

class Renderer {
public:
    Renderer();
    ~Renderer();

    void draw(Scene* scene);
};

} // namespace ocf
