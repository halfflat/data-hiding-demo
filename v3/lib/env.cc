#include <any>
#include <iostream>
#include <memory>
#include <stdexcept>

#include "env.h"
#include "env_private.h"

// env_foo and env_foo_data

struct env_foo_data {
    // info for foo implementation
    // ...

    friend std::ostream& operator<<(std::ostream& o, const env_foo_data&) {
        return o << "<foo data>";
    }
};

struct env_foo: env {
    explicit env_foo(const env_foo_data& data): data(data) {
        std::cout << "env_foo::env_foo() data: " << data << '\n';
    }

    void emit(int i) override {
        std::cout << "env_foo::emit(): data: " << data << ": " << i << '\n';
    }

    ~env_foo() override {
        std::cout << "env_foo::~env_foo() data: " << data << '\n';
    }

private:
    const env_foo_data& data;
};

env_data foo_data() {
    return env_foo_data{};
}

// env_bar and env_bar_data

struct env_bar_data {
    // info for bar implementation
    // ...

    friend std::ostream& operator<<(std::ostream& o, const env_bar_data&) {
        return o << "<bar data>";
    }
};

struct env_bar: env {
    explicit env_bar(const env_bar_data& data): data(data) {
        std::cout << "env_bar::env_bar() data: " << data << '\n';
    }

    void emit(int i) override {
        std::cout << "env_bar::emit(): data: " << data << ": " << i << '\n';
    }

    ~env_bar() override {
        std::cout << "env_bar::~env_bar() data: " << data << '\n';
    }

private:
    const env_bar_data& data;
};

env_data bar_data() {
    return env_bar_data{};
}

// Mapper from env_data to appropriate implementation class.

std::unique_ptr<env> get_env(const env_data& data) {
    if (auto p = std::any_cast<env_foo_data>(&data)) {
        return std::make_unique<env_foo>(*p);
    }
    else if (auto p = std::any_cast<env_bar_data>(&data)) {
        return std::make_unique<env_bar>(*p);
    }

    throw std::runtime_error("unrecognized env_data");
}
