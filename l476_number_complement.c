//https://leetcode.com/problems/number-complement/
//The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
//For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
//Given an integer num, return its complement.
  
#include <stdio.h>

int dbg = 0;

int findComplement(int num)
{
	int i, k = 0;
	if(!num) return 1; //if num is 0 just return 1
	for(i=0; num && i<32; i++)
	{
		if(dbg) printf("i:%d, num:%d, %d\n", i, num, 1<<i);
		//check bit
		
		if ( num & (1<<i) ) //1이면 just remove num
		{
			//k |= 0;
			num -= (1<<i);
			if(dbg) printf("num:%d\n", k, num);
		}
		else
		{
			k |= 1<<i;
			if(dbg) printf("updated k:%d, num:%d\n", k, num);
		}
	}
	
	return k;
}

int main()
{
	int i, num;
	scanf("%d", &num);
	
	i = findComplement(num);
	
	printf("%d\n", i);
	
	return 0;
}
