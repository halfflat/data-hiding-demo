#pragma once

typedef void* env_handle;

env_handle make_env(const char*);
void destroy_env(env_handle&);

