#define BASE_16 (16)
#define BASE_10 (10)
#define BASE_2 (2)
#define BASE_8 (8)

#include "platform.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Takes an integer data and converts it to an ASCII string 
 *
 * Given an int32_t data and base, converts the data to an ASCII
 * string depending  on the base and outputs the string to a 
 * ptr
 *
 * @param data Data that needs to be converted
 * @param ptr Converted string needs to be put in this pointer
 * @param base Base to conver the integer to |  Supports 2 to 16
 *
 * @return Number of digits in the ASCII string | Will include
 * NULL Characters in the end
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);



/**
 * @brief Takes an ASCII string and base to convert to Integer data
 * Given a pointer to an ASCII string, base and number of digits, generates
 * the resulting Integer value
 *
 * @param digits DataLength of the ASCII string
 * @param ptr Pointer to the ASCII string that needs to be converted
 * @param base Base to convert the integer to |  Supports 2 to 16
 *
 * @return The integer representative of the ASCII string
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
