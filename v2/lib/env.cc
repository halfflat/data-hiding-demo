#include <iostream>

#include "env.h"
#include "env_private.h"

env_handle make_env(const char* key) {
    return env_handle(new env(key));
}

env::env(const char* key): key(key) {
    std::cout << "env::env() key=" << key << '\n';
}

env::~env() {
    std::cout << "env::~env() key=" << key << '\n';
}

void env::emit(int i) {
    std::cout << "env::emit() key=" << key << ": " << i << '\n';
}

