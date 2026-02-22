/* SPDX - License - Identifier : MIT */
#pragma once
#include "ocf/scene/Component.h"

namespace ocf {
class Sprite : public Component {
public:
    Sprite();
    ~Sprite() override;

    void update(float deltaTime) override;
};

} // namespace ocf
