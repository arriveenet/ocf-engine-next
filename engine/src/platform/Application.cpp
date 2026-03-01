/* SPDX - License - Identifier : MIT */
#include "ocf/platform/Application.h"
#include "ocf/scene/Engine.h"
#include "platform/GLFWWindow.h"

namespace ocf {

Application& Application::getInstance()
{
    static Application instance;
    return instance;
}

Application::Application()
{
    // Constructor implementation
}

Application::~Application()
{
    // Destructor implementation
}

void Application::run(const Config& config, SetupCallback setupCallback,
                      CleanupCallback cleanupCallback, int width, int height)
{
    m_window = std::make_unique<GLFWWindow>();
    if (!m_window->create(config, config.title, width, height)) {
        // Handle window creation failure
        return;
    }

    m_engine = Engine::create();

    Scene* scene = m_engine->createScene();
    
    if (setupCallback) {
        setupCallback(scene);
    }

    while (!m_window->windowShouldClose()) {
        // Main application loop
        m_engine->mainLoop();
        m_window->pollEvents();
        m_window->swapBuffers();
    }

    if (cleanupCallback) {
        cleanupCallback(scene);
    }

    Engine::destroy(m_engine);
}

} // namespace ocf
