/* SPDX - License - Identifier : MIT */
/*
 *
 * Copyright (c) 2025 Tsuyoshi KATAYAMA
 *
 */
#include "ocf/scene/Engine.h"

namespace ocf {

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::update()
{
    calculateDeltaTime();
}

void Engine::draw()
{

}

void Engine::mainLoop()
{
    update();
    draw();
}

Scene* Engine::createScene()
{
    m_currentScene = std::make_unique<Scene>();
    return m_currentScene.get();
}

void Engine::calculateDeltaTime()
{
    auto now = std::chrono::steady_clock::now();
    m_deltaTime =
        std::chrono::duration_cast<std::chrono::microseconds>(now - m_lastUpdate).count() /
        1000000.0f;
    m_lastUpdate = now;
}

} // namespace ocf
