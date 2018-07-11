#include <iostream>

#include "env_private.h"
#include "sim.h"

void sim::run() {
    std::cout << "sim::run():\n";

    auto e = get_env(data);
    e->emit(++run_count);
}
