## Environment or policy classes and implementation data hiding

There are two classes involved in this demo:

1.  `env` — some sort of environment or context class that is used by our `sim`
    class, but has a lifetime beyond it.

2.  `sim` — a class that provides user-visible functionality but which also
    requires an `env` in order to use its `emit` method.

We want to keep the implementation and state of `env` private, but we can
create one with a top level `make_env(...)` function.

It's possible that `env` may have multiple implementations, one of which is
selected by the `make_env(...)` call.


### Version 1: with a `void*` handle

The `make_env(...)` function returns a handle of type `void*`, and the
corresponding environment is destroyed explicitly with a `destroy_env(handle)`
call.

### Version 2: with a `shared_ptr` handle

The `shared_ptr` automatically manages environment lifetime.

### Version 3: with env data separate from logic

`env_handle` is replaced with an `env_data` class that is an alias for
`std::any`. The `get_env` helper method in the library is used to instantiate
the appropriate `env` class for the `env_data` content as required.

In this implementation, `sim` holds on to the `env_data`, rather than holding
on to the `env`-derived implementation object. This simplifies management, and
allows the `env_data` to be changed easily between invocations of `sim`
methods, but at the cost of a small overhead every time the implementation is
required.

