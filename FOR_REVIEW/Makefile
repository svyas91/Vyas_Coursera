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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
# This includes sources files and include files.
include sources.mk

# Define the target name.
TARGET = c1m2
	
# General Flags for both platform
FLAGS = -Wall       \
        -Werror     \
        -g          \
        -std=c99    \
        -O0         \
        $(INCLUDES) \

# Platform Overrides
PLATFORM ?= HOST

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
FPFLAGS = -mfloat-abi=hard -mfpu=fpv4-sp-d16

# C-Preprocessor Flags
CPPFLAGS = -D$(PLATFORM)

# Print array compile time switch 
PRINT_ARRAY = -D$(ARRAY)

ifeq ($(ARRAY),PRINT)
ifeq ($(PLATFORM),HOST)
CFLAGS = $(CPPFLAGS) $(FLAGS) $(PRINT_ARRAY)
endif
endif
# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
ifneq ($(ARRAY),PRINT)
	CC = gcc
	LD= ld
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = $(CPPFLAGS) $(FLAGS) 
endif
endif

ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = $(CPPFLAGS) $(FLAGS) -mcpu=$(CPU) -mthumb -march=$(ARCH) $(FPFLAGS) --specs=$(SPECS) 
endif

# Preprocessed output
PREPS = $(SOURCES:.c=.i)

%.i : %.c
	$(CC) -E $< $(CPPFLAGS) $(INCLUDES) -o $@

# Assembly output 
ASSES = $(SOURCES:.c=.asm)

%.asm : %.c
	$(CC) -S $< $(CFLAGS) -o $@

# Object output, also output dependency file -MD 
OBJS = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) -c $< -MD $(CFLAGS) -o $@

%.out : %.c
	$(CC) $< -o $@ $(CFLAGS) 

.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) -c $^ -MD $(CFLAGS)

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
# generate size report and dump assembly from machine code
ifeq ($(PLATFORM),HOST)
	size -Atd $@
	objdump -d $@
endif
ifeq ($(PLATFORM),MSP432)
	arm-none-eabi-size -Atd $@
	arm-none-eabi-objdump -d $@
endif

.PHONY: clean
clean:
	# rm -f -v $(OBJS) $(PREPS) $(ASSES) $(TARGET).out $(TARGET).map *.d
	rm -f -v *.out $(TARGET).map *.i *.asm *.o *.d 