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
 * @file stats.c
 * @brief Implements functions to : 
 *        Print an array       
 *        Calculate Mean
 *        Calculate Median
 *        Calculate Maximum value in the array
 *        Calculate Minimum value in the array
 *        Sort the array from largest to smallest and print sorted array
 *
 * @author Karthik Shankar
 * @date(MM/DD/YYYY) :  04/26/2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


/* Add other Implementation File Code Here */
void print_statistics(unsigned char *array, int length){
     unsigned char median;
     unsigned char mean;
     unsigned char max;
     unsigned char min;
     //unsigned char *sorted_ar;

     print_array(array, length);
     printf("Printing Statistics : \n");
     max    = find_maximum(array, length);
     printf("Maximum = %i\n", max);

     min    = find_minimum(array, length);
     printf("Minimum = %i\n", min);

     median = find_median(array, length);
     printf("Median  = %i\n", median);

     mean   = find_mean(array, length);
     printf("Mean    = %i\n", mean);

     //printf("Sorted Array :\n");
     //sorted_ar = sort_array(array, length);
     //print_array(sorted_ar, length);

}

void print_array(unsigned char *array, int length){
    #ifdef VERBOSE
    //user SIZE to limit the iterations
    printf( "Printing array:\n [");
    for( int i = 0; i < SIZE; i++ ){
        printf("%i ", array[i]);
    }
    printf( "]\n");
    #endif
}

unsigned char find_median (unsigned char *array, int length) {
    unsigned char *sorted_ar;
    sorted_ar = sort_array(array , length);
    //If SIZE is even then the median would be the average 
    //of the the two middle elements
    //For eg. SIZE = 40, so elements 19 and 20 would be the middle elements
    if(length%2 == 0){
       return ( (sorted_ar[(length/2)-1] + sorted_ar[length/2])/2 );   
    }
    else {
        //If length is odd then the middle element would be the median
        return ( sorted_ar[(length/2)-1] );
    }
}

unsigned char find_mean (unsigned char *array, int length){

    unsigned int sum;
    unsigned char mean;
    sum = 0;
    for(int i = 0; i< length; i++){
        sum = sum + array[i];
    }
    mean = sum/length;
    return mean;
}

unsigned char find_maximum(unsigned char  *array, int length){
    unsigned char max;
    max  = 0;
    for(int i =0; i< length ; i++){
        if(max < array[i]){
            max = array[i];
        }
    }
    return max;
}

unsigned char find_minimum(unsigned char *array, int length){
    unsigned char min;
    min = array[0];
    for(int i = 0; i< length; i++){
        if(min > array[i]){
            min = array[i];    
        }
    }
    return min;
}

unsigned char* sort_array(unsigned char *array, int length){

    unsigned char *number;
    number = array;
    int n = length;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(number[j] < number[i]) {
                 unsigned char temp = number[i];
                 number[i] = number[j];
                 number[j] = temp;
            }
        }
    }
    return number;
}

