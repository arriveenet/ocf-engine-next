// SPDX-License-Identifier: MIT
#pragma once
#include "ocf/platform/platform.h"
#include <functional>
#include <memory>
#include <string>

namespace ocf {

class Window;

struct Config {
    std::string title;
    int redBits = 8;
    int greenBits = 8;
    int blueBits = 8;
    int alphaBits = 8;
    int depthBits = 24;
    bool vsync = true;
};

class OCF_API Application {
public:
    using SetupCallback = std::function<void()>;
    using CleanupCallback = std::function<void()>;

    static Application& getInstance();

    ~Application();

    void run(const Config& config, SetupCallback setupCallback, CleanupCallback cleanupCallback,
             int width = 800, int height = 600);

    Application(const Application& rhs) = delete;
    Application& operator=(const Application& rhs) = delete;
    Application(Application&& rhs) = delete;
    Application& operator=(Application&& rhs) = delete;
private:
    Application();

private:
    std::unique_ptr<Window> m_window;
};

} // namespace ocf
