/*
 * @lc app=leetcode.cn id=18 lang=c
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (38.04%)
 * Likes:    519
 * Dislikes: 0
 * Total Accepted:    93.3K
 * Total Submissions: 245.2K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int comp(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}
int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes)
{
  if (numsSize < 4)
  {
    return NULL;
  }
  int index = 0;
  int **result = (int **)malloc(numsSize * 4 * sizeof(int *));
  *returnColumnSizes = (int *)malloc(numsSize * sizeof(int *));
  int low;
  int high;
  qsort(nums, numsSize, sizeof(nums[0]), comp);

  for (int i = 0; i < numsSize; i++)
  {
    if (nums[i] > 0)
    {
      break;
    }

    if (i > 0 && nums[i] == nums[i - 1])
    {
      continue;
    }

    low = i + 1;
    high = numsSize - 1;

    while (low < high)
    {
    }
  }
}

// @lc code=end
