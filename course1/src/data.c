#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
	unsigned int rem;
	size_t i = 0;
	if (base <= 10) {
		while (data !=0 ) {
			rem = data%base;
			data = data/base;
			*(ptr+i) = rem;
			i++;
			//PRINTF("REM IS %d\n",rem);
		}
	my_reverse(ptr,i);
	if (data < 0 ) {
		my_memmove(ptr,ptr+1,i);
		*(ptr) = '-';
		i++;
	}
	i++;
	*(ptr+i) = '\0';
	}
	return i;
	}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
	int32_t x = 0;
	unsigned int i;
	PRINTF("DIGITS IS %d\n",digits);
	for (i = 0; i < digits-1; i++) {
			x = (x*base) + (*(ptr+i));
	}
	return x;
}
