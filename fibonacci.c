/**
 * f(0) = 1,f(1) = 1 
 * f(n) = f(n - 1) + f(n -2) ;(n > 1)
 * fibonacci_top_to_low 自顶向下
 **/

#include <stdbool.h>
#include <stdio.h>
#include <memory.h>

long long cache[50];
bool initial;

//初始化缓存
void initial_cache(){
  initial =  true;
  memset(cache + 2, 0, 48 * sizeof(long long));
  cache[0] = 1;
  cache[1] = 1;
}

long long sub(int n)
{
  if(cache[n] != 0){
    printf("fibonacci_top_to_low(%d) = %lld\n",n,cache[n]);
    return cache[n];
  }
  //计算完sub(n - 1)则cache[n - 2]一定已经计算完毕
  cache[n] = sub(n - 1) + cache[n - 2];
  printf("fibonacci_top_to_low(%d) = %lld\n",n,cache[n]);
  return cache[n];
}
/**
 * 自顶向下
 * 会利用到递归，影响效率
 **/
long long fibonacci_top_to_low(int n)
{
  return sub(n);
}

//long long fibonacci_low_to_top(int n)
//{
//  for(int i = 0; i < n; i++)
//  {
//
//  }
//}

int main()
{
  initial_cache();
  int inputs[10] = {3, 10, 12, 15, 18, 20, 50, 34, 31, 20};
  for(int i = 0; i < 10; i++){
    fibonacci_top_to_low(inputs[i]);
    getchar();
  }

  return 0;
}

