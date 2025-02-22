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
    int nums[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};  // Selection Sort (Seçmeli Sıralama)
    int size = sizeof(nums) / sizeof(nums[0]);
    int low_idx = 0;
    for (int i = 0; i < size; i++)
    {
        low_idx = i;
        for (int j = i+1; j < size; j++)
        {
            if (nums[j] < nums[low_idx])
                low_idx = j;
        }
        num_swap(&nums[i], &nums[low_idx]);
    }

    int k = 0;
    printf("\n");
    while (k < size)
    {
        printf("%d ",nums[k]);
        k++;
    }
    
}
