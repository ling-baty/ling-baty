/***************************************
This file is for Binary Search
****************************************/

#include <stdio.h>

int binary_search(int key, int a[], int n)
{
	int low = 0, high = n - 1, mid;
	int count = 0, count1 = 0;
	
	while (low < high)
	{
		mid = (low + high) / 2;
		count ++;
		if (key < a[mid])
		{
			high = mid - 1;
		}
		else if (key > a[mid])
		{
			low =  mid + 1;
		}
		else if (key == a[mid])
		{
			count1 ++;
			printf("Search success! a[%d] = %d, search time = %d. \n", mid, key, count1);
			break;
		}
		
	}
	if (count1 == 0)
		printf("search failure.\n");		
	return 0;
}

int main(void)
{	int i, key1, a1[10] = {11, 13, 15, 22, 33, 39, 50, 67, 88, 99}, n1 = 10;
/*	
	printf("Please input a array:\n");
	for (i = 0; i < n1; i ++)
	{
		scanf("%d", &a1[i]);
	} */
	printf("Please input key to search:\n");
	scanf("%d", &key1);
	binary_search(key1, a1, n1);
	return 0;
}