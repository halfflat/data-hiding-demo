#include "env.h"
#include "sim.h"

int main() {
    env_handle h = make_env("fish");
    sim s(h);

    s.run();
    s.run();

    destroy_env(h);
}
