/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);


/**
 * @brief Moves data from source to destimation
 *
 * Given a source pointer & destination pointer, moves data from the source to the destination based on the # of bytes given
 *
 * @param src Pointer to source 
 * @param dst Pointer to destination
 * @param length Number of bytes to move
 *
 * @return pointer to the destination.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets the value pointed by the src pointer
 *
 * Given a source pointer, number of bytes and value, sets the number of bytes starting from the src pointer to be 'value'
 *
 * @param src Pointer to source 
 * @param length Number of bytes
 * @param value Value to be set
 *
 * @return pointer to the source
 */
uint8_t * my_memset(uint8_t * src, size_t length,uint8_t value );

/**
 * @brief Sets the value to zero pointed by the src pointer
 *
 * Given a source pointer and number of bytes, sets the number of bytes starting from the src pointer to be 0
 *
 * @param src Pointer to source 
 * @param length Number of bytes
 *
 * @return pointer to the source
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of the bytes
 *
 * Given a source pointer and number of bytes, reverses the order of the bytes
 *
 * @param src Pointer to source 
 * @param length Number of bytes
 *
 * @return pointer to the source
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates dynamic memory
 *
 * Given number of bytes, dynamically reserve memory for the same number of bytes
 *
 * @param Number of bytes
 *
 * @return pointer to the reserved memory
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Free memory
 *
 * Given pointer to a src pointing to a memory, free the dynamically allocated memory
 *
 * @param pointer to the src
 *
 * @return void - nothing is returned
 */
void free_words(uint32_t * src);


#endif /* __MEMORY_H__ */


