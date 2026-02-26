// SPDX - License - Identifier : MIT
#pragma once

namespace ocf {

class Node;

class Scene {
public:
    Scene();
    virtual ~Scene();

    void update(float deltaTime);

protected:
    Node* m_root;
};

} // namespace ocf