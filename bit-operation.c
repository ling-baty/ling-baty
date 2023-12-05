/***************************************
This file is for bit operation.
****************************************/

#include <stdio.h>

#define BITS 32
#define BIT3 (0x1 << 3)

// bit reverse
unsigned int bit_reverse(unsigned int i1)
{
	unsigned int temp = 0, bits = BITS;
	
	while (bits != 0)
	{
		bits --;
		temp |= (i1 & 1) << bits;
		i1 = i1 >> 1;
	}
	return temp;
}

// endian change
unsigned int endian_change(unsigned int ui1)
{
	unsigned int temp1 = 0;
	
	temp1 = ((ui1 & 0xff)<< 24) | ((ui1 & 0xff00) << 8) | ((ui1 & 0xff0000) >>8) | ((ui1 & 0xff000000) >>24);
	return temp1; 
}

int count_bits(unsigned int ui2)
{
	int ret1 = 0, bits1 = BITS;
	
	while (bits1 != 0)
	{
		bits1 --;
		if ((ui2 & 1) == 1)
			ret1 ++;
		ui2 = ui2 >> 1;
	}	

	return ret1;	
}

unsigned int set_bit3(unsigned int ui3)
{
	unsigned int ret3 = 0;
	
	ret3 = ui3 | BIT3;
	return ret3;
}

unsigned int clear_bit3(unsigned int ui4)
{
	unsigned int ret4 = 0;
	
	ret4 = ui4 & (~ BIT3);
	return ret4; 
}

int main(void)
{
	int i1 = 0x33, ret;
	
	ret = bit_reverse(i1);
	ret = endian_change(i1);
	ret = count_bits(0x35);
	ret = clear_bit3(0x39);
	ret = set_bit3(0x30);
	return 0;
}