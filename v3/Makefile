.PHONY: all clean
.SECONDARY:

all: demo libsim.a

CXXFLAGS=-std=c++17
CPPFLAGS+=-Iinclude

VPATH:=src:lib

libsim.a: libsim.a(env.o) libsim.a(sim.o) env_private.h include/sim.h include/env.h

demo.o: demo.cc include/sim.h include/env.h

demo: demo.o libsim.a
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f libsim.a env.o sim.o demo.o demo
