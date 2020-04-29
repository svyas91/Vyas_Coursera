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
 * @file data.c
 * @brief Abstraction of basic data manipulation functions 
 *
 * This implementation file provides an abstraction of basic data manioulation 
 * functions. Integer to ASCII and ASCII to integer
 * 
 * @author Karthik Shankar
 * @date April 26 2020
 *
 */
#include "math.h"
#include "stdlib.h"
#include "stdint.h"
#include "data.h"
#include "memory.h"



/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){

    int i = 0;
 
    if (data == 0)
    { 
        ptr[i++] = '0';
        ptr[i] = '\0';
        return 1;
    }

    int neg = 0;
    if (data<0){
      neg = 1;
      data = -data;
    }

   // Process individual digits
    while (data != 0)
    {
        int rem = data % base;
        ptr[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        data = data/base;
    }
 
    // If number is negative, append '-'
    if (neg==1)
        ptr[i++] = '-';
 
    ptr[i] = '\0'; // Append string terminator
 
    // Reverse the string
    return i;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){


    int neg = 0;
    int i=1;   
    int num = 0; // Initialize result

    if (ptr[digits-1] =='-') neg=1; 

    i = (neg==1) ? (digits-2) : (digits-1); 
    // Iterate through all characters of input string and
    // update result
    if(base==10){
        for(;i>=0;i--)
        {
            num = num*10 + (int)(ptr[i]-'0');
        }
    }

    if(base==16){
        for(;i>=0;i--)
        {
            num += (int)pow(2,(4*(i))) * (int)(ptr[i]-'0');
        } 
    }

    return (neg==1)? num*-neg : num;
}

