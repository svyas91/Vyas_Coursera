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
 * @file <stats.c> 
 * @brief <Routines defined to extract information about the array>
 *
 * <File has the function definitions of hte functions declared in stats.h
 * find_miinimum, find_maximum, find_mean, find_median, print_array, print_statistics, sort_array>
 *
 * @author <Shrikant Vyas>
 * @date <04/03/2020>
 *
 */



#include <stdio.h>
#include "./../include/common/platform.h"
#include "./../include/common/stats.h"

/* Size of the Data Set */
#define SIZE (40)

unsigned int find_mean(unsigned char* ptr_to_array, unsigned int size_of_array) {
	unsigned int mean = 0;
	for (int i =0;i<size_of_array;i++) {
		mean = mean + *ptr_to_array;
		ptr_to_array++;
	}
	return mean/size_of_array;
}



unsigned int find_minimum(unsigned char *ptr_to_array, unsigned int size_of_array) {
	unsigned int minimum = *ptr_to_array;
	for (int i=1;i<size_of_array;i++) {
		if (*(ptr_to_array+1) < minimum) {
			minimum = *(ptr_to_array+1);
		}
		*ptr_to_array++;
	}
	return minimum;
}

unsigned int find_maximum(unsigned char *ptr_to_array, unsigned int size_of_array) {
	unsigned int maximum = *ptr_to_array;
	for (int i=1;i<size_of_array;i++) {
		if (*(ptr_to_array+1) > maximum) {
			maximum = *(ptr_to_array+1);
		}
		*ptr_to_array++;
	}
	return maximum;
}


void sort_array(unsigned char *ptr_to_array, unsigned int size_of_array) { 
	unsigned int largest;
	unsigned int largest_index;
	for (int i = 0; i < size_of_array; i++) {
		largest = *(ptr_to_array+i);
		largest_index = i;
		for (int j = i; j < size_of_array; j ++) {
			if (largest < *(ptr_to_array+j) ) {
				largest_index = j;
				largest = *(ptr_to_array+j);
			}
		}
			//int temp = *(ptr_to_array+largest_index);
			*(ptr_to_array+largest_index) = *(ptr_to_array+i);
			*(ptr_to_array+i) = largest;
	}
}


unsigned int find_median(unsigned char *ptr_to_array, unsigned int size_of_array) {
	unsigned int median;
	sort_array(ptr_to_array,size_of_array);
	if ((size_of_array%2) == 0) {
		median = (*(ptr_to_array + (size_of_array/2)) + *(ptr_to_array + (size_of_array/2) - 1))/2;
	}
	else {
		median = *(ptr_to_array + (size_of_array/2));
	}
	//PRINTF("%d\n",median);
	return median;
}


void print_array(unsigned char *ptr_to_array, unsigned int size_of_array) {
	for (int i = 0; i < size_of_array; i++) {
		PRINTF(" Value of the element at index %d is: %d  \n",i,*(ptr_to_array+i));
	}
}

void print_statistics(unsigned char *ptr_to_array,unsigned int size_of_array) {
	unsigned int mean,median,maximum,minimum;
	minimum = find_minimum(ptr_to_array,size_of_array);
	maximum = find_maximum(ptr_to_array,size_of_array);
	mean = find_mean(ptr_to_array,size_of_array);
	median = find_median(ptr_to_array,size_of_array);
	PRINTF("***** Minimum value of all the elements in the array is: %d *****\n",minimum);
	PRINTF("***** Maximum value of all the elements in the array is: %d *****\n",maximum);
	PRINTF("***** Mean value of the elements in the array is:        %d *****\n",mean);
	PRINTF("***** Median value of the array is: 			 %d *****\n",median);
}

		

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  //int num_elements = sizeof(test)/sizeof(unsigned char);
  int num_elements = SIZE;


  unsigned int my_mean = find_mean(test,num_elements);
  unsigned int maximum = find_maximum(test,num_elements);
  unsigned int minimum = find_minimum(test,num_elements);
  unsigned int median = find_median(test,num_elements);
  #ifdef VERBOSE
      print_array(test,num_elements);
      print_statistics(test,num_elements);
  #endif
  sort_array(test,num_elements);
  return;
}

/* Add other Implementation File Code Here */
