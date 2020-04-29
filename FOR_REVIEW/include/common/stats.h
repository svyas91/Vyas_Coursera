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
#ifndef __STATS_H__
#define __STATS_H__

// Compile time switch for printing the original array
#if defined (PRINT)
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#endif

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Mean value of an array
 *
 * This function takes as an input a pointer to the first element of 
 * an unsigned char array and the size of the array and returns the mean value.
 *
 * @param unsigned char * array array pointer
 * @param int N array size
 *
 * @return unsigned char mean value
 */
unsigned char find_mean(unsigned char *array,int N);

/**
 * @brief Maximum value of an array
 *
 * This function takes as an input a pointer to the first element of 
 * an unsigned char array and the size of the array and returns the maximum value.
 *
 * @param unsigned char * array array pointer
 * @param int N array size
 *
 * @return unsigned char max value
 */
unsigned char find_maximum(unsigned char *array, int N);

/**
 * @brief Minimum value of an array
 *
 * This function takes as an input a pointer to the first element of 
 * an unsigned char array and the size of the array and returns the minimum value.
 *
 * @param unsigned char * array array pointer
 * @param int N array size
 *
 * @return unsigned char min value
 */
unsigned char find_minimum(unsigned char *array, int N);

/**
 * @brief Median value of an array
 *
 * This function takes as an input a pointer to the first element of 
 * an unsigned char array and the size of the array and sorts the array and then returns the median value.
 *
 * @param unsigned char * array array pointer
 * @param int N array size
 *
 * @return unsigned char median value
 */
unsigned char find_median(unsigned char *array, int N);

/**
 * @brief Descending sort
 *
 * This function takes as an input a pointer to the first element of 
 * an unsigned char array and the size of the array and sorts the array in a descending manner.
 *
 * @param unsigned char * array array pointer
 * @param int N array size
 *
 * @return void
 */
void sort_array(unsigned char *array, int N);

/**
 * @brief Print array
 *
 * This function takes as an input a pointer to the first element of 
 * an unsigned char array and the size of the array and prints each element of the array with its respective index.
 *
 * @param unsigned char * array array pointer
 * @param int N array size
 *
 * @return void
 */
void print_array(unsigned char *array,int N);

/**
 * @brief Print array statistics
 *
 * This function takes as an input a pointer to the first element of 
 * an unsigned char array and the size of the array and prints the min, max, mean and median values.
 *
 * @param unsigned char * array array pointer
 * @param int N array size
 *
 * @return void
 */
void print_statistics(unsigned char *array,int N);



#endif /* __STATS_H__ */
