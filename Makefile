############################################
#
# This makefile will automatically build
# the Subjective Logic code.
#
# Recall the library is header-only, and
# thus all this builds is test code.
#
############################################


############################################
# Variables.

# Toolchain Variables.
CC = g++
COPT = -03
INCLUDE_DIR_FLAG = -I$(H_FLDR)
CPPFLAGS = $(COPT) -Wall -pedantic
LNFLAGS =	-lxerces-c -lboost_system -lboost_filesystem -lgtest \
				$(INCLUDE_DIR_FLAG)

H_FLDR = headers
H_FLDR_SURV = $(H_FLDR)/survObjs
H_FLDR_REL = $(H_FLDR)/relObjs
TEMP_FLDR = temp
TEST_FLDR = tests

# files involved with the project... 
# note: if we ever seperate prototypes from implementation, this will no longer work.
H_SOURCES = $(shell ls $(H_FLDR) | grep .*\.cpp)
H_SOURCES_SURV = $(shell ls $(H_FLDR_SURV) | grep .*\.cpp)
H_SOURCES_REL = $(shell ls $(H_FLDR_REL) | grep .*\.cpp)
H_TESTS = $(shell ls $(TEST_FLDR) | grep .*\.hpp)
H_OBJS = $(H_SOURCES:.cpp=.o)
H_OBJS_SURV = $(H_SOURCES_SURV:.cpp=.o)
H_OBJS_REL = $(H_SOURCES_REL:.cpp=.o)
TEST_MAIN = $(TEST_FLDR)/main
TEST_BLANK = $(TEST_FLDR)/blank

all: headers tests 

headers: $(H_OBJS) $(H_OBJS_SURV) $(H_OBJS_REL)

# for precompiling headers.
$(H_OBJS): %.o: $(H_FLDR)/%.cpp
	$(CC) -c -o $(TEMP_FLDR)/$(H_FLDR)/$@ $(H_FLDR)/$(@:.o=.cpp) \
	$(INCLUDE_DIR_FLAG)

$(H_OBJS_SURV): %.o: $(H_FLDR_SURV)/%.cpp
	$(CC) -c -o $(TEMP_FLDR)/$(H_FLDR_SURV)/$@ $(H_FLDR_SURV)/$(@:.o=.cpp) \
	$(INCLUDE_DIR_FLAG)

$(H_OBJS_REL): %.o: $(H_FLDR_REL)/%.cpp
	$(CC) -c -o $(TEMP_FLDR)/$(H_FLDR_REL)/$@ $(H_FLDR_REL)/$(@:.o=.cpp) \
	$(INCLUDE_DIR_FLAG)

# stage1.o: stage1.cpp
#	$(CC) -c -o $@ $^

tests: test_blank runTests 

ALL_OBJ_FILES = $(H_OBJS:%=$(TEMP_FLDR)/$(H_FLDR)/%) \
					$(H_OBJS_SURV:%=$(TEMP_FLDR)/$(H_FLDR_SURV)/%) \
					$(H_OBJS_REL:%=$(TEMP_FLDR)/$(H_FLDR_REL)/%)

test_main: 
	$(CC) $(CPPFLAGS) $(ALL_OBJ_FILES) -o $(TEST_MAIN) $(TEST_MAIN).cpp \
	$(LNFLAGS)

test_blank: 
	$(CC) $(CPPFLAGS) $(ALL_OBJ_FILES) -o $(TEST_BLANK) $(TEST_BLANK).cpp \
	$(LNFLAGS)

runTests:
	./$(TEST_MAIN)

main: main.cpp
	$(CC) $(CPPFLAGS) $(ALL_OBJ_FILES) $^ -o $@ $(LNFLAGS)
