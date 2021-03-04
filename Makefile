# Set compiler
CXX := g++

# example program utilizing all modules
TRGTDIR := bin
TARGET := runner

SRCEXT := cpp
OBJEXT := o
HEADEXT := h
DEPEXT := d

# global include
INCLDIR := include
INCLUDES := $(wildcard $(INCLDIR)/*)

SOURCES := $(wildcard */*.$(SRCEXT))
OBJECTS := $(SOURCES:.$(SRCEXT)=.$(OBJEXT))
DEPENDS := $(SOURCES:.$(SRCEXT)=.$(DEPEXT))

# setting general flags
CXXFLAGS := -std=c++17 -I$(INCLDIR)

# main source file
MAIN := main

all: $(OBJECTS) $(TRGTDIR)/$(TARGET)

clean: | $(TRGTDIR)
	@rm -r $(TRGTDIR)/$(TRGT) $(OBJECTS)

cleaner: | $(TRGTDIR)
	@rm -r $(TRGTDIR)/$(TRGT) $(OBJECTS) $(DEPENDS) $(MAIN).$(DEPEXT)

$(TRGTDIR):
	@mkdir -p $@

# generating dependency files for all sources
# sed changes '%.o: ...' to '%.o %.d: ...' in dependency file, escaping backslashes
%.$(DEPEXT): %.$(SRCEXT)
	@echo "Generating dependency file for $@ ..."
	@$(CXX) -MM $(CXXFLAGS) $< -MF $@
	sed -i "~" -e 's,$(*F).$(OBJEXT),$*.$(OBJEXT) $@,g' $@
	@rm -f $@~
	@echo "... done."

# include targets from generated dependency files
include $(DEPENDS)
include $(MAIN).$(DEPEXT)

# build main target
# check if target directory 'bin' already exist via prerequisite
$(TRGTDIR)/$(TARGET): $(MAIN).$(DEPEXT) | $(TRGTDIR)
	@echo "Building example programm 'bin/runner'..."
	@$(CXX) $(CXXFLAGS) $(OBJECTS) $(MAIN).$(SRCEXT) -o $(TRGTDIR)/$(TARGET)
	@echo "... done."

# pattern rule to build object from source file
%.$(OBJEXT): %.$(DEPEXT)
	@echo "Compiling $@ ..."
	@$(CXX) -c $(CXXFLAGS) $(@:.$(OBJEXT)=.$(SRCEXT)) -o $@
	@echo "... done."

.PHONY: all clean cleaner
