#pragma once

#include "env.h"

struct sim {
    explicit sim(env_data d): data(std::move(d)) {}

    void set_data(env_data d) {
        data = std::move(d);
    }

    void run();

private:
    int run_count = 0;
    env_data data;
};

