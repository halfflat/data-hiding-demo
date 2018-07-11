#pragma once

#include "env.h"

struct sim {
    explicit sim(env_handle h): h(h) {}
    void run();

private:
    int run_count = 0;
    env_handle h;
};

