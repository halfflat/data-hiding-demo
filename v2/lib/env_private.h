#pragma once

#include <string>

#include "env.h"

struct env {
    explicit env(const char* key);
    ~env();

    void emit(int i);

private:
    std::string key;
};

inline env& get_env(env_handle h) {
    return *h.get();
}
