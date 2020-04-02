/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <malloc.h>
int *twoSum(int *nums, int numsSize, int target)
{
    int *result = (int *)malloc(sizeof(int) * 2);
    int i, j;
    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}
