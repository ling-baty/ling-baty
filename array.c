/********************************
This file is for array operation
*********************************/

#include <stdio.h>

int a[6] = {1, 9, 2, 8, 7, 5};

void ascend_array(int a1[], int size)
{
	int i, j = size, temp;
	
	for (i = 0; i < (size-1); i ++)
	{
		for (j = (i + 1); j < size; j ++)
		{
			if (a1[i] > a1[j])
			{
				temp = a1[i];
				a1[i] = a1[j];
				a1[j] = temp;
			}
		}
	}
	return;
}

// use pointer to sort from little to big
void sort_arr_ptr(int arr[], int length)
{
	int *p1 = arr, *p2 = &arr[1], temp;
	
	while (p1 < &arr[length - 1 ])
	{
		p2 = p1 + 1;	
		while (p2 < &arr[length])
		{
			if (*p1 > *p2)
			{
				temp = *p1;
				*p1 = *p2;
				*p2 = temp;		
			}
			p2 ++;
		}	
		p1 ++;
		
	}
	return;
}

// remove duplicate elements of sorted array, return new lenth
int remove_dupicate(int arr1[], int len)
{
	int *p11 = arr1, *p12 = &arr1[1];
	int len_ret = len;
	
	while (p11 < &arr1[len_ret -1])
	{
		if ( *p11 == *p12)
		{
			while (p12 < &arr1[len_ret - 1])
			{
				*p12 = * (p12 + 1);
				p12 ++;
			}
			len_ret --;
			p12 = p11 + 1;
		}
		else
		{
			p11 ++;
			p12 = p11 + 1;
	//		p12 ++;
		}
			
	}	
	return len_ret;
}

// insert array by index 
void insert_arr(int arr2[], int ins_pos, int value, int len2)
{
	int temp, i;
	
	for (i = len2; i > (ins_pos - 1); i --)
	{
		arr2[i] = arr2[i-1];
			
	}
	arr2[ins_pos] = value;
	
	return;	
} 

// insert array by pointer
void ins_arr_ptr(int * arr3, int ins_pos1, int val1, int len3)
{
	int * ptr = &arr3[len3 - 1], temp;
	
	while (ptr > &arr3[ins_pos1 - 1])
	{
		*ptr = *(ptr - 1);
		ptr --; 	
	}	
	arr3[ins_pos1] = val1;	
	
	
	return;
}

int main(void)
{
	int len1;
	
	ascend_array(a, 6);
	static int b[7] = { 5, 1, 2, 4, 3};
	sort_arr_ptr(b, 5);
	len1 = remove_dupicate(b, 5);
	insert_arr(b, 2, 3, 5);
	ins_arr_ptr(b, 3, 4, 6);
	return 1; 
}