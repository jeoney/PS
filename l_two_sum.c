//https://leetcode.com/problems/two-sum/

#include <stdio.h>

#define MAXN 10010
int num_len;
int nums[MAXN];
int output[2];
int target;
int dbg=1;

int main()
{
	int i, j = 0;
	int ret1, ret2 = 0;
	scanf("%d", &target);
	scanf("%d", &num_len);
	for(i=0; i<num_len; i++)
		scanf("%d", &nums[i]);
	
	//O(N^2)
	for(j=0; j<num_len-1; j++)
	{
		for(i=1; i<num_len; i++)
		{
			if(i==j) continue;
			if(nums[i] + nums[j] == target)
			{
				printf("output: %d %d\n", j, i);
				return 0;
			}
		}
	}
	
	// O(NlogN) 
	// 입력 structure idx/value
	// sort
	// loop 돌면서 binary search로 찾기
	
	
	//Hash로 찾기 => 이건 C++로 해야할듯...
	
	return 0;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
int result[2];
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j = 0;

	for(j=0; j<numsSize-1; j++)
	{
		for(i=1; i<numsSize; i++)
		{
			if(i==j) continue;
			if(nums[i] + nums[j] == target)
			{
				//printf("output: %d %d\n", j, i);
                result[0] = j;
                result[1] = i;
                *returnSize = 2;
				return result;
			}
		}
	}
    
    return NULL;
}
*/
