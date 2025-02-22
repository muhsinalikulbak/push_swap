#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void num_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int nums[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};  // Insertion Sort (Seçmeli Sıralama)
	int size = sizeof(nums) / sizeof(nums[0]);
	
	int key;
	int j;
	for (int i = 1 ; i < size; i++)
	{
		key = nums[i]; // key = 8 /  i = 2
		j = i - 1;      // j = 0
		while (j >= 0 && nums[j] > key)
		{
			nums[j+1] = nums[j];
			j--;
		}
		nums[j + 1] = key;
	}
	// 8, 9, 10, 7, 6, 5, 4, 3, 2, 1
	int k = 0;
	printf("\n");
	while (k < size)
	{
		printf("%d ",nums[k]);
		k++;
	}
	
}
