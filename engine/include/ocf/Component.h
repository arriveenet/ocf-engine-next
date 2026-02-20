/* SPDX - License - Identifier : MIT */ 
#pragma once

namespace ocf {

class Node;

class Component {
public:
    Component();
    virtual ~Component();

    virtual void update(float deltaTime);

protected:
    Node* m_owner = nullptr;
};

} // namespace ocf
