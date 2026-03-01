/* SPDX - License - Identifier : MIT */
#include "ocf/platform/Application.h"
#include "ocf/scene/Scene.h"
#include "ocf/scene/Node.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#ifdef _WIN32
#include <crtdbg.h>
#endif

using namespace ocf;

void setup(Scene* scene)
{
    Node* node = scene->getRoot()->createChild();
    
}

void cleanup(Scene*)
{
    // Cleanup code goes here
}

int main()
{
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    Config config;
    config.title = "cpp-test";

    Application::getInstance().run(config, setup, cleanup);

    return 0;
}