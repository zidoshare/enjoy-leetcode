/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (53.67%)
 * Likes:    755
 * Dislikes: 0
 * Total Accepted:    122K
 * Total Submissions: 227.2K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 * 示例:
 *
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 *
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
#include <stdlib.h>
void backtracking(char map[8][4], int *map_lens, char **result, int *result_index, int *queue, int queue_len, char *unit, int unit_len)
{
    if (unit_len == queue_len)
    {
        unit[unit_len] = '\0';
        result[(*result_index)++] = unit;
        return;
    }
    int i = 0;
    for (i = 0; i < map_lens[queue[unit_len]]; i++)
    {
        char *tmp = (char *)malloc(sizeof(char) * unit_len + 2);
        int j = 0;
        for (j = 0; j < unit_len; j++)
        {
            tmp[j] = unit[j];
        }
        tmp[unit_len] = map[queue[unit_len]][i];
        backtracking(map, map_lens, result, result_index, queue, queue_len, tmp, unit_len + 1);
    }
    return;
}
char **letterCombinations(char *digits, int *returnSize)
{
    char map[8][4] = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}};
    int map_lens[8] = {3, 3, 3, 3, 3, 4, 3, 4};
    int len = 0;
    while (*(digits + (len)) != '\0')
    {
        len++;
    }
    if (len == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    int *queue = (int *)malloc(len * sizeof(int));
    int index = 0;
    while (*(digits + index) != '\0')
    {
        queue[index] = *(digits + index) - '2';
        index++;
    }
    *returnSize = 1;
    for (index = 0; index < len; index++)
    {
        *returnSize = map_lens[queue[index]] * (*returnSize);
    }
    char **result = (char **)malloc(sizeof(char *) * (*returnSize));
    int *result_index = (int *)malloc(sizeof(int));
    *result_index = 0;
    backtracking(map, map_lens, result, result_index, queue, len, "", 0);
    return result;
}
// @lc code=end
