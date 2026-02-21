/* SPDX - License - Identifier : MIT */
#include "GLFWWindow.h"

namespace ocf {

GLFWWindow::GLFWWindow()
{

}

GLFWWindow::~GLFWWindow()
{
    if (m_pMainWindow) {
        glfwDestroyWindow(m_pMainWindow);
    }
    glfwTerminate();
}

bool GLFWWindow::create(const Config& config, std::string_view title, int width, int height)
{
    if (!glfwInit()) {
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RED_BITS, config.redBits);
    glfwWindowHint(GLFW_GREEN_BITS, config.greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, config.blueBits);
    glfwWindowHint(GLFW_ALPHA_BITS, config.alphaBits);
    glfwWindowHint(GLFW_DEPTH_BITS, config.depthBits);

    m_pMainWindow = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    if (!m_pMainWindow) {
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(m_pMainWindow);

    // Load OpenGL functions using glad
    const int status = gladLoadGL();
    if (status != 1) {
        return false;
    }

    glfwSwapInterval(config.vsync ? 1 : 0);

    return true;
}

void GLFWWindow::swapBuffers()
{
    glfwSwapBuffers(m_pMainWindow);
}

void GLFWWindow::pollEvents()
{
    glfwPollEvents();
}

bool GLFWWindow::windowShouldClose() const
{
    return glfwWindowShouldClose(m_pMainWindow);
}

} // namespace ocf
