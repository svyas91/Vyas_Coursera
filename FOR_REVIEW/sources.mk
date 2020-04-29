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

#******************************************************************************
# @file sources.mk
# @brief define the paths of source files and inclue files.
#
# @author MD Huang
# @date 2020-03-16
# 
#*****************************************************************************
# Platform Overrides
PLATFORM ?= HOST

# Add your Source files to this variable
#SOURCES = main.c\
#          memory.c\
#          startup_msp432p401r_gcc.c\
#          interrupts_msp432p401r_gcc.c\
#          system_msp432p401r.c

ifeq ($(PLATFORM),HOST)
	SOURCES = main.c\
              memory.c\
			  stats.c
endif
ifeq ($(PLATFORM), MSP432)
	SOURCES = main.c\
              memory.c\
              startup_msp432p401r_gcc.c\
              interrupts_msp432p401r_gcc.c\
              system_msp432p401r.c
endif

# Add your include paths to this variable
ifeq ($(PLATFORM),HOST)
	INCLUDES = -I../include/common
	        
endif
ifeq ($(PLATFORM), MSP432)
	INCLUDES = -I../include/CMSIS  \
	           -I../include/common \
	           -I../include/msp432
endif
 