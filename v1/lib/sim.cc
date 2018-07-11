#include <iostream>

#include "env_private.h"
#include "sim.h"

void sim::run() {
    std::cout << "sim::run():\n";

    env& e = get_env(h);
    e.emit(++run_count);
}
