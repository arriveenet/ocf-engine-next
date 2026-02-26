/* SPDX - License - Identifier : MIT */
/*
 *
 * Copyright (c) 2025 Tsuyoshi KATAYAMA
 *
 */
#include "ocf/scene/Engine.h"
#include "ocf/scene/Scene.h"
#include "ocf/renderer/Renderer.h"
#include "renderer/backend/opengl/OpenGLDriver.h"

namespace ocf {

using namespace backend;

Engine::Engine()
    : m_deltaTime(0.0f)
    , m_lastUpdate(std::chrono::steady_clock::now())
{
    m_renderer = new Renderer();
}

Engine::~Engine()
{
    delete m_renderer;
}

bool Engine::init()
{
    return true;
}

Engine* Engine::create()
{
    Engine* engine = new Engine();
    if (engine && engine->init()) {
        return engine;
    }

    return engine;
}

void Engine::destroy(Engine* engine)
{
    delete engine;
}

void Engine::update()
{
    calculateDeltaTime();
}

void Engine::draw()
{
    m_renderer->draw(m_currentScene.get());
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
