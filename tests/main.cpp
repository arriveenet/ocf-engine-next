/* SPDX - License - Identifier : MIT */
#include "ocf/platform/Application.h"

using namespace ocf;

void setup()
{
    // Setup code goes here
}

void cleanup()
{
    // Cleanup code goes here
}

int main()
{
    Config config;
    config.title = "cpp-test";

    Application::getInstance().run(config, setup, cleanup);

    return 0;
}