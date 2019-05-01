CC  = g++ 
CXX = g++ -O0 #-fno-elide-constructors 

# Comment out one of the following 2 lines to enable/disable BASIC4TRACE.
INCLUDES = -DBASIC4TRACE
#INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g
LDLIBS  =

executables = jeopardy_email
objects = jeopardy_email

.PHONY: default
default: $(executables)

$(executables): jeopardy_email.o


.PHONY: clean
clean:
	rm -f ~.* *~ a.out core jeopardy_email.o $(objects) $(executables)

.PHONY: all
all: clean default
