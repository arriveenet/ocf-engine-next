/* SPDX - License - Identifier : MIT */
/*
 * src/Engine.cpp
 *
 * Copyright (c) 2025 Tsuyoshi KATAYAMA
 *
 */
#include "ocf/Engine.h"

namespace ocf {

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::run()
{
}

void Engine::update()
{
    calculateDeltaTime();
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
