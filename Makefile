# Set compiler
CXX := g++

# example program utilizing all modules
TRGTDIR := bin
TARGET := cpp-utils

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
# setting linker flags
LDFLAGS := -lboost_filesystem
# main source file
MAIN := main

# get kernel name to be able to run sed correctly on Darwin (MacOS) or Linux kernels
KERNEL := $(shell uname -s)
ifeq ($(KERNEL), Darwin) 
	SED := sed -i "~"
else
	SED := sed -i
endif

all: $(OBJECTS) $(TRGTDIR)/$(TARGET)

# build all with debug flags
debug: CXXFLAGS += -g
# show linker invocation when building debug target
debug: LDFLAGS += -v
debug: all

clean: | $(TRGTDIR)
	@rm -r $(TRGTDIR)/$(TRGT) $(OBJECTS)

cleaner: | $(TRGTDIR)
	@rm -r $(TRGTDIR)/$(TRGT) $(OBJECTS) $(DEPENDS) $(MAIN).$(DEPEXT)

$(TRGTDIR):
	@mkdir -p $@

# generating dependency files for all sources
# sed changes '%.o: ...' to '%.o %.d: ...' in dependency file
%.$(DEPEXT): %.$(SRCEXT)
	@echo "Generating dependency file '$@' ..."
	@$(CXX) -MM $(CXXFLAGS) $< -MF $@
	@$(SED) 's,$(*F).$(OBJEXT),$*.$(OBJEXT) $@,' $@
	@rm -f $@~
	@echo "... done."

# include targets from generated dependency files
include $(DEPENDS)
include $(MAIN).$(DEPEXT)

# build main target
# check if target directory 'bin' already exist via prerequisite
$(TRGTDIR)/$(TARGET): $(MAIN).$(DEPEXT) | $(TRGTDIR)
	@echo "Compiling '$(MAIN).$(SRCEXT)' and linking example program '$@'..."
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) $(MAIN).$(SRCEXT) -o $(TRGTDIR)/$(TARGET)
	@echo "... done."

# pattern rule to build object from source file
%.$(OBJEXT): %.$(DEPEXT)
	@echo "Compiling '$@' ..."
	@$(CXX) -c $(CXXFLAGS) $(@:.$(OBJEXT)=.$(SRCEXT)) -o $@
	@echo "... done."

.PHONY: all debug clean cleaner

