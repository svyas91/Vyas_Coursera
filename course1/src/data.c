#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
	unsigned int rem;
	size_t i = 0;
	while (data !=0 ) {
		rem = data%base;
		if (rem < 10) {
			*(ptr+i) = rem;
		}
		else {
			*(ptr+i) = '7' + rem;
		}
		data = data/base;
		i++;
	}
	my_reverse(ptr,i);
	if (data < 0 ) {
		my_memmove(ptr,ptr+1,i);
		*(ptr) = '-';
		i++;
	}
	i++;
	*(ptr+i) = '\0';
	return i;
	}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
	int32_t x = 0;
	unsigned int i;
	for (i = 0; i < digits-1; i++) {
		if (*(ptr+i) >= 'A') {
			*(ptr+i) = *(ptr+i) - '7';
		}	
		x = (x*base) + (*(ptr+i));
	}
	return x;
}
