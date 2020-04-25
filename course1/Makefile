#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile supporting the following 2 platforms
# 	PLATFORM=HOST
# 	PLATFORM=MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
# 	<FILE>.o - Builds <FILE>.o object file
# 	<FILE>.i - Builds <FILE>.i preprcoessed output file
# 	<FILE>.asm - Generates assembly output of <FILE>.asm
# 	build - Builds and links all source files
# 	compile-all - Genrates the object files for all the source files
# 	clean - removes all generated files
#
# Platform Overrides:
#	CPU
#	ARCH
#	SPECS
# NOTE: If PLATFORM not specified on the command line, Default is HOST
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM=HOST
COURSE=COURSE1
PRINT=VERBOSE

# Architectures Specific Flags
#LINKER_FILE = 
CPU = cortex-m4 
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines
LINKER_FILE=msp432p401r.lds
TARGET=course1
GENERAL_FLAGS = -g \
		-Wall \
		-O0 \
		-D$(PLATFORM) \
		-D$(COURSE) \
		-D$(PRINT) \
		-std=c99 \
		-Werror 
		#-DVERBOSE \
		#-DCOURSE1 \

ifeq ($(PLATFORM),HOST)
	#Architecture Specific Flags
	CC=gcc
	OBJ_DUMP = objdump
	SIZE_UTILITY = size
	#LDFLAGS=-Wl,-LD -n -T ./../$(LINKER_FILE)
	LDFLAGS=-Wl,-Map=$(TARGET).map -LD 
	CFLAGS = $(GENERAL_FLAGS) \
		 $(INCLUDES)
else
	CC=arm-none-eabi-gcc
	OBJ_DUMP = arm-none-eabi-objdump
	SIZE_UTILITY = arm-none-eabi-size
	LDFLAGS=-Wl,-Map=$(TARGET).map -LD -T ./$(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) \
		 -m$(ARCH) \
		 -march=armv7e-m \
		 -mfloat-abi=hard \
		 -mfpu=fpv4-sp-d16 \
		 --specs=$(SPECS) \
		 $(INCLUDES) \
		 $(GENERAL_FLAGS)
endif


OBJECTS = $(SOURCES:.c=.o)
PREPROCESSOR_FILES = $(SOURCES:.c=.i)
ASSEMBLY_FILES = $(SOURCES:.c=.asm)

# Adding Rule to generate teh .d files
#main.dep: main.c
	#cc -MM $< 

# Rule to generate the .i files
%.i: %.c
	$(CC) -E $< $(CFLAGS) -o $@

#Rule to generate the .asm files from the object files
%.asm: %.o
	$(OBJ_DUMP) -S $< > $@

#Rule to generate the .asm files from the executable
%.asm: %.out
	$(OBJ_DUMP) -S $< > $@

# Compile-all option
.PHONY: compile-all
#compile-all: $(CC) -c $(CFLAGS) -o $(OBJECTS)
compile-all: $(OBJECTS)

# Clean option
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(TARGET).map $(PREPROCESSOR_FILES) $(ASSEMBLY_FILES) $(TARGET).out $(TARGET).asm

# Build option
.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE_UTILITY) -Btx $^ $@



