CXX=g++

SOURCES=bmemcpy.cpp test.cpp
OBJECTS	= $(foreach x, $(basename $(SOURCES)), $(x).o)

all: $(OBJECTS)
	@echo [LD] $@
	@$(CXX) $(OBJECTS) -o test

%.o: %.cpp
	@echo [CC] $@
	@gcc -o $@ -c $<

clean:
	@rm -f $(OBJECTS)
	@rm -f test
	@rm -f *~



