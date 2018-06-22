/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.68%)
 * Total Accepted:    468.1K
 * Total Submissions: 1.9M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
#include <string.h>
#include <stdio.h>
int lengthOfLongestSubstring(char* s) {
    int set[256] = {0},len = 0,i = 1,tmp = 0,chr = (int)*s,start = 0;
    while(chr != 0){
        if(set[chr] != 0)
            start = set[chr];
        tmp = i - start;
        len = tmp > len ? tmp : len;
        set[chr] = i;
        chr = (int)(*(s + (i++)));
    }
    return len;
}

int main(){
    char* str = "abba";
    printf("%d\n",lengthOfLongestSubstring(str));
}
