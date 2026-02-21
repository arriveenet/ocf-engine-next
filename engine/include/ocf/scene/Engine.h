/* SPDX - License - Identifier : MIT */
#pragma once
#include <chrono>

namespace ocf {

class Engine {
public:
    Engine();
    virtual ~Engine();

    void update();
    void draw();

    void mainLoop();

private:
    void calculateDeltaTime();

private:
    float m_deltaTime;
    std::chrono::steady_clock::time_point m_lastUpdate;
};

} // namespace ocf
