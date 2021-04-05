#include <stdio.h>

int N, ans;
int dbg=0;

void input()
{
	scanf("%d", &N);
}

void output()
{
	if(ans) printf("LUCKY\n");
	else printf("READY\n");
}

int div(int i)
{
	int ret = 1;
	for(; i>0; i--)
		ret *= 10;
	if(dbg) printf("div: %d\n", ret);
	return ret;
}

int get_seperate_num(int n, int div, int loop)
{
	int i, pow = div/10, ret=0;
	for(i=0; i<loop; i++)
	{
		ret += (n/pow);
		if(dbg) printf("ret:%d n:%d pow:%d\n", ret, n, pow);
		n %= pow;
		pow /= 10;
	}
	if(dbg) printf("n:%d seperate num sum: %d\n", n, ret);
	
	return ret;
}

void solve()
{
	int i, pow=10000000, div_num;
	
	for(i=4; i>0; i--)
	{
		if(dbg) printf("i:%d pow: %d\n", i, pow);
		if(N/pow > 0) break; //계산 시작 
		pow /= 100;
	}
	div_num = div(i);
	
	if( get_seperate_num(N/div_num, div_num, i) == get_seperate_num(N%div_num, div_num, i) )
		ans = 1;
}
 
int main()
{
	input();
	solve();
	output();
	return 0;
}
