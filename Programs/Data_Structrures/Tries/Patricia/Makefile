CC=g++
LDFLAGS = 
CXXFLAGS=-std=c++17 -g -v

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
dep  = $(obj:.o=.d)

main: $(obj)
	$(CC) -o $@ $^ $(CXXFLAGS)

%.d: %.cpp
	@$(CC) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

clean: 
	rm -f $(obj) main

cleandep:
	rm -f $(dep)
