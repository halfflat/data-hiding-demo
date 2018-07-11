#pragma once

#include <memory>

struct env;
using env_handle = std::shared_ptr<env>;

env_handle make_env(const char*);
