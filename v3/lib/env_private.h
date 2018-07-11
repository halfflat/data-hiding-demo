#pragma once

#include <memory>

#include "env.h"

struct env {
    virtual void emit(int i) = 0;
    virtual ~env() {}
};

std::unique_ptr<env> get_env(const env_data& data);
