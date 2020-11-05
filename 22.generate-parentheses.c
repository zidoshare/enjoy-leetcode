/*
 * @lc app=leetcode.cn id=22 lang=c
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.44%)
 * Total Accepted:    193.3K
 * Total Submissions: 252.8K
 * Testcase Example:  '3'
 *
 * <p>数字 <em>n</em>&nbsp;代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 <strong>有效的
 * </strong>括号组合。</p>
 *
 * <p>&nbsp;</p>
 *
 * <p><strong>示例：</strong></p>
 *
 * <pre><strong>输入：</strong>n = 3
 * <strong>输出：</strong>[
 * ⁠      &quot;((()))&quot;,
 * ⁠      &quot;(()())&quot;,
 * ⁠      &quot;(())()&quot;,
 * ⁠      &quot;()(())&quot;,
 * ⁠      &quot;()()()&quot;
 * ⁠    ]
 * </pre>
 *
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void generate(char** result,int* returnSize, int left,int right,int n)
{
    if(left == right && left  == n){
        (*returnSize)++;
        result[*returnSize] = (char*)calloc(2 * n + 1,sizeof(char));
        strcpy(result[*returnSize], result[(*returnSize) - 1]);
        return;
    }
    if(left < n){
        result[*returnSize][left + right] = '(';
        generate(result, returnSize, left + 1, right, n);
    }
    if(right < left){
        result[*returnSize][left + right] = ')';
        generate(result, returnSize, left, right + 1, n);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize)
{
    char** result = (char**)malloc(sizeof(char*) * 1431);
    *returnSize = 0;
    result[0] = (char*)calloc(2 * n + 1, sizeof(char));
    generate (result,returnSize, 0, 0, n);
    return result;
}
