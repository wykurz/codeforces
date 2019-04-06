CC     = clang++
CFLAGS = -std=c++11 -Wall -g -Wno-unused-function -Wno-unused-variable -Wno-sign-compare
LFLAGS = -Wl,--no-as-needed -lprofiler -Wl,--as-needed
SRCS   = $(wildcard *.cpp)
BINS   = $(patsubst %.cpp, %, $(SRCS))
INPUT  = input.txt

test : $(BINS)
	CPUPROFILE=cpu.profile ./$< < $(INPUT)
	pprof --text ./$< cpu.profile | c++filt

# compile with -v to get the libstd include dirs
% : %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)

clobber :
	rm -f $(BINS)
	rm -f *.bak
	rm cpu.profile

clean : clobber

upload :
	cp *.cpp ~/share/

contest : upload test clobber

.PHONY : test clobber clean upload contest
