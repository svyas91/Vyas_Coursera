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
 * @file <stats.h> 
 * @brief <Function declarations which are needed to extract information about an array >
 *
 * <This file provides a description about each function needed to extract information about an array
 * It provides the input arguments needed along with the return type if any>
 *
 * @author Shrikant Vyas
 * @date 03/30/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief This function returns the mean value of an array
 *
 *  By providing the pointer to an array along with the number of 
 *  elements present in the array, this function returns the mean value
 *
 * @param unsigned char *ptr_to_array <This input basically points to the address of the 0th element of the array>
 * @param unsigned int size_of_array <This input indicates the size of the array (number of elements present in the array>
 *
 * @return <Returns an integer which is basically the mean value of the elements of the array passed>
 */
unsigned int find_mean(unsigned char *ptr_to_array, unsigned int size_of_array);



/**
 * @brief This function returns the min value of an array
 *
 *  By providing the pointer to an array along with the number of 
 *  elements present in the array, this function returns the min value
 *
 * @param unsigned char *ptr_to_array <This input basically points to the address of the 0th element of the array>
 * @param unsigned int size_of_array <This input indicates the size of the array (number of elements present in the array>
 *
 * @return <Returns an integer which is basically the min value of the elements of the array passed>
 */
unsigned int find_maximum(unsigned char *ptr_to_array, unsigned int size_of_array);


/**
 * @brief This function returns the max value of an array
 *
 *  By providing the pointer to an array along with the number of 
 *  elements present in the array, this function returns the max value
 *
 * @param unsigned char *ptr_to_array <This input basically points to the address of the 0th element of the array>
 * @param unsigned int size_of_array <This input indicates the size of the array (number of elements present in the array>
 *
 * @return <Returns an integer which is basically the max` value of the elements of the array passed>
 */
unsigned int find_maximum(unsigned char *ptr_to_array, unsigned int size_of_array);



/**
 * @brief This function returns the median of an array
 *
 *  By providing the pointer to an array along with the number of 
 *  elements present in the array, this function returns the median value
 *  after sorting teh array
 *
 * @param unsigned char *ptr_to_array <This input basically points to the address of the 0th element of the array>
 * @param unsigned int size_of_array <This input indicates the size of the array (number of elements present in the array>
 *
 * @return <Returns an integer which is basically the median value of the elements of the array passed>
 */
unsigned int find_median(unsigned char *ptr_to_array, unsigned int size_of_array);



/**
 * @brief This function prints the array
 *
 *  By providing the pointer to an array along with the number of 
 *  elements present in the array, this function prints the value of each element in the array 
 *  along with the index location 
 *
 * @param unsigned char *ptr_to_array <This input basically points to the address of the 0th element of the array>
 * @param unsigned int size_of_array <This input indicates the size of the array (number of elements present in the array>
 *
 */
unsigned int print_array(unsigned char *ptr_to_array, unsigned int size_of_array);



/**
 * @brief This function prints different statistics of an array
 *
 *  By providing the pointer to an array along with the number of 
 *  elements present in the array, this function prints the minimum value of all the elements in the array,
 *  the maximum value of all the elements in the array, the mean value of all the elements and the 
 *  meidan of the elements. value of each element in the array 
 *  along with the index location 
 *
 * @param unsigned char *ptr_to_array <This input basically points to the address of the 0th element of the array>
 * @param unsigned int size_of_array <This input indicates the size of the array (number of elements present in the array>
 *
 */
unsigned int print_statistics(unsigned char *ptr_to_array, unsigned int size_of_array);



/**
 * @brief This function returns the sorted version of the array passed to it 
 *
 *  By providing the pointer to an array along with the number of 
 *  elements present in the array, this function sorts the provided array 
 *
 * @param unsigned char *ptr_to_array <This input basically points to the address of the 0th element of the array>
 * @param unsigned int size_of_array <This input indicates the size of the array (number of elements present in the array>
 *
 */
void sort_array(unsigned char *ptr_to_array, unsigned int size_of_array);


#endif /* __STATS_H__ */
