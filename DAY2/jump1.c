#include <stdio.h>
#include <stdbool.h>
bool canJump(int *nums, int size)
{
    int maxReach = 0;
    for (int i = 0; i < size; i++)
    {
        if (i > maxReach)
        {
            return false;
        }
        if (i + nums[i] > maxReach)
        {
            maxReach = i + nums[i];
        }
        if (maxReach >= size)
        {
            return true;
        }
    }
    return true;
}
int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    if (canJump(nums, n))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}