#include "env.h"
#include "sim.h"

int main() {
    sim s(foo_data());

    s.run();
    s.run();

    s.set_data(bar_data());

    s.run();
    s.run();
}
