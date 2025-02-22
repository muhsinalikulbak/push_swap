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
    int nums[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};  // 0 1 2 3
    bool check = true;
    int size = sizeof(nums) / sizeof(nums[0]);
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        check = true;
        for (int j = 1; j < size; j++)
        {
            if (nums[j-1] > nums[j])
            {
                check = false;
                num_swap(&nums[j-1], &nums[j]);
            }
        }
        if (check) // if bloğuna hiç girilmemişse demekki dizi artık sıralanmıştır.
            break;
    }
    printf("\n");
    while (k < size)
    {
        printf("%d ",nums[k]);
        k++;
    }
    
}
