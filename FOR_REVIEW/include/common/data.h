/******************************************************************************
 * Copyright (C) 2020 Ioannis Fokianos
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it.
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Contains the function declarations that are needed to perform 
 *        statisitc operations in the stats.c file
 *
 * @author Ioannis Fokianos
 * @date 08/03/2020
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Integer to ASCII
 *
 * This function takes as an input data and converts them in the ASCII equivalent 
 * 
 * @param int32_t data
 * @param uint8_t * ptr, pointer that will hold the ASCII string
 * @param uint32_t base, the base of the value given , from 2 through 16
 *
 * @return length of the string
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief ASCII to integer
 * 
 * @param uint8_t * ptr
 * @param uint8_t digits
 * @param uint32_t base
 * 
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif // __DATA_H__