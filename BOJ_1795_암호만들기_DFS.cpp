#include<iostream>
#include<vector>
#include <algorithm>    // std::sort

using namespace std;

#define MAXN 17

int L, C; //L 암호 length, C 전체 글자 수 
vector<char> v;
vector<char> pick;
int visit[MAXN];

int dbg=0;

void print_visit()
{
	if(dbg==0) return;
	printf("visit:\n");
	for(int i=0; i<C; i++)
	{
		printf("%d ", visit[i]);
	}
	printf("\n");
}

void DFS(int start, int depth, int vowel_cnt)
{
	if(depth>=L)
	{
		//조합 완성
		//모음/자음 수 check 
		if(vowel_cnt < 1 || depth-vowel_cnt < 2)
		{
			if(dbg) printf(":: not meet the req. start:%d depth:%d vowel_cnt:%d\n", start, depth, vowel_cnt);
			return;
		}
		
		for(int i=0; i<pick.size(); i++)
		{
			printf("%c", pick[i]);
		}
		printf("\n");
		return;
	}

	if(start+L-depth > C) //start 위치 + 비번 length가 전체 글자 입력된 수보다 많으면 return
		return;

	for(int i=start; i<C; i++)
	{
		int is_vowel=0;

		if(visit[i]) continue;  //기 방문
		visit[i] = 1;
		pick.push_back(v[i]);
		
		//모음수 확인  
		if( v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u' )
			is_vowel = 1;

		print_visit();
		DFS(i+1, depth+1, vowel_cnt+is_vowel);
		visit[i] = 0;
		pick.pop_back();
	}
}

int main()
{
	scanf("%d %d", &L, &C);
	for(int i=0; i<C; i++)
	{
		char c;
		scanf(" %c", &c);
		v.push_back(c);
	}
	
	//오름차순 정렬 
	sort(v.begin(), v.end());

	DFS(0, 0, 0);

	return 0;
}
