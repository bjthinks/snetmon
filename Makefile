CXX = g++ -std=c++11
CXXFLAGS = -Wall

OFILES = \
	config.o \
	device.o \
	snetmon.o \
	util.o

PROG = snetmon

%.o: %.cc
	$(CXX) $(CXXFLAGS) -MMD -MP -MF $(<:%.cc=.%.d) -c $<

$(PROG): $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES) -o $@

clean:
	rm -f $(OFILES) $(PROG)

cleanall: clean
	rm -f $(PROG) .*.d *~
