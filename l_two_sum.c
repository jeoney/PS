//https://leetcode.com/problems/two-sum/

#include <stdio.h>

#define MAXN 10010
int num_len;
int nums[MAXN];
int output[2];
int target;
int dbg=0;

typedef struct {
	int idx;
	int val;
}INPUT;
INPUT input[MAXN];

	// O(NlogN) 
	// 입력 structure idx/value
	// sort
	// loop 돌면서 binary search로 찾기
	
int compare (const void * a, const void * b)
{
	INPUT first = *(INPUT *)a;
	INPUT second = *(INPUT *)b;
	if ( first.val < second.val ) return -1;
	else return 1;
}

int bin_srch(int s, int e, int match_num)
{
	int result = -1;
	int m = 0;
	
	while(s<e)
	{
		m = (s+e)/2;
		if(input[m].val == match_num)
		{
			if(dbg) printf("found matched number val:%d, idx: %d\n", input[m].val, input[m].idx);
			return input[m].idx;
		}
		else if(input[m].val > match_num)
		{
			e = m;
		}
		else
		{
			s = m;
		}
	}

	return result;
}

void find_two_num(int target, int num_len, int *ret1, int *ret2)
{
	int i=0, result=0;
	//앞에서 부터 loop 돌면서 찾아야 할 match num 확보
	for(i=0; i<num_len-1; i++) //check before num_len
	{
		//전체 INPUT에서 match num있는지 이분탐색
		result = bin_srch(i, num_len, target-input[i].val);
		
		//찾으면 return 아니면 다음 index 검색 if result == -1, not found
		if(result != -1)
		{
			*ret1 = input[i].idx;
			*ret2 = result;
			return;
		}
	}

	return;
}

int main()
{
	int i, j = 0;
	int ret1, ret2 = 0;
	scanf("%d", &target);
	scanf("%d", &num_len);
	for(i=0; i<num_len; i++)
	{
		input[i].idx = i;
		scanf("%d", &input[i].val);
	}
	
	if(dbg)
	{
		for(i=0; i<num_len; i++)
			printf("idx:%d, val:%d\n", input[i].idx, input[i].val);
	}

	//정렬
	qsort (input, num_len, sizeof(INPUT), compare);

	if(dbg)
	{
		for(i=0; i<num_len; i++)
			printf("idx:%d, val:%d\n", input[i].idx, input[i].val);
	}

	find_two_num(target, num_len, &ret1, &ret2);
	
	printf("%d %d\n", ret1, ret2);

	return 0;
}

/*
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
	
	
	//Hash로 찾기  
	
	return 0;
}
*/

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
