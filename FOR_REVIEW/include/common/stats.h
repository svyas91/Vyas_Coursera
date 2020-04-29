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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Prints out statistics of data array 
 *
 * Prints out minimum, maximum, mean and median for the elements
 * in the data array input
 *
 * @param array - Data array to be analyzed.
 *
 * @return none.
 */
void print_statistics( unsigned char *array, int length);

/**
 * @brief Prints out elements of data array 
 *
 * Given an array of data and a length, prints the array to the screen
 *
 *
 * @param array - Data array to be printed.
 *
 * @return none.
 */

void print_array(unsigned char *array, int length);


/**
 * @brief Calculates median of array
 *
 * Given an array of data and a length, returns the median value
 *
 *
 * @param array - Data array for which median will be calculated
 *
 * @return median value
 */

unsigned char find_median(unsigned char *array, int length);


/**
 * @brief Calculates mean of array
 *
 * Given an array of data and a length, returns the mean value
 *
 * @param array - Data array for which mean will be calculated
 *
 * @return mean value
 */

unsigned char find_mean(unsigned char *array, int length);


/**
 * @brief finds maximum value in array
 *
 * Given an array of data and a length, returns the maximum value
 *
 * @param array - Data array to find maximum
 *
 * @return the maximum of array
 */

unsigned char find_maximum(unsigned char *array, int length);


/**
 * @brief finds minimum value in array
 *
 * Given an array of data and a length, returns the minimum value
 *
 * @param array - Data array to find minimum
 *
 * @return the minimum of array
 */

unsigned char find_minimum(unsigned char *array, int length);


/**
 * @brief finds minimum value in array
 *
 * Given an array of data and a length, returns the minimum value
 *
 * @param array - Data array to find minimum
 *
 * @return the minimum of array
 */

unsigned char find_minimum(unsigned char *array, int length);


/**
 * @brief Sorts array from largest to smallest
 *
 * Given an array of data and a length, sorts array from largest to smallest
 * Element 0 is largest value, last element in the array is the smallest value
 *
 * @param array - Data array to sort
 *
 * @return the sorted array
 */

unsigned char* sort_array(unsigned char *array, int length);


#endif /* __STATS_H__ */
