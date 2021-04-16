//https://www.acmicpc.net/problem/18405
//경쟁적 전염

#include <stdio.h>
#include <stdlib.h>

#define MAXN 210

int N, K; //N map크기, K바이러스 최대 수
int S, X, Y; //S는 확인할 초, X행, Y열 => 저는Y열 X행으로 받아서 처리 예정 
int map[MAXN][MAXN];
int dbg=0;

//상하좌우 
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

typedef struct {
	int type, x, y, t;
}VIRUS;

int compare (const void * a, const void * b)
{
	VIRUS A=*(VIRUS*)a, B=*(VIRUS*)b; 
	if ( A.type <  B.type ) return -1;
	else return 1;
}

void print_map()
{
	int i, j;
	if(dbg==0) return;
	printf("print map:\n");
	for(j=0; j<=N+1; j++)
	{
		for(i=0; i<=N+1; i++) {
			printf("%d ", map[j][i]);
		}
		printf("\n");
	}
	printf("------------\n");
}

int rq, wq;
VIRUS que[MAXN*MAXN]; //중복 확산은 안 됨

void print_que()
{
	int i;
	if(dbg==0) return;

	printf("print que:\n");
	for(i=rq; i<wq; i++)
	{
		printf("(%d:%d,%d) ", que[i].type, que[i].x, que[i].y);
	}
	printf("\n");
}

VIRUS top() { return que[rq]; }
void pop()  { rq++; }
int empty() { return rq==wq; }
int push(int type, int x, int y)
{
	//확산 안 되는 조건 check후 return 
	//범위 check
	if(x<=0 || y<=0 || x>N || y>N ) return;
	
	if(dbg) printf("push! type:%d, x:%d, y:%d\n", type, x, y);

	que[wq].type = type;
	que[wq].x = x;
	que[wq].y = y;
	wq++;
	
	map[y][x] = type;
	print_map();
	
	print_que();
	
	return 0;
}

void input()
{
	int i, j;
	scanf("%d %d", &N, &K);
	for(j=1; j<=N; j++)
	{
		for(i=1; i<=N; i++) {
			scanf("%d", &map[j][i]);
			if(map[j][i])
				push(map[j][i], i, j);
		}
	}
	scanf("%d %d %d", &S, &Y, &X); //X, Y순서 문제와 다름 
	
	//check
	if(dbg)	print_que();
	
	qsort(que, wq, sizeof(VIRUS), compare);
	
	if(dbg)	print_que();
}

void BFS()
{
	int i, k;
	VIRUS cur;
	//이미 확산 필요한 item은 push되고 정렬 되어 있음.
	
	//S초 까지만 확산 
	for(k=0; k<S; k++)
	{
		int temp_wq = wq;
		
		//BFS시작 당시 들어가 있는 wq까지 진행하고 초 증가
		while( rq != temp_wq )
		{
			cur = top();
			pop();
	
			for(i=0; i<4; i++)
			{
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				
				if(map[ny][nx]) continue; //바이러스 이미 있으면 skip
	
				push(cur.type, nx, ny);
			}
		}
	}

	printf("%d\n", map[Y][X]);
	return;
}


int main()
{
	input();
	BFS();

	return 0;
}

/*
3 3
1 0 2
0 0 0
3 0 0
2 3 2

3 3
3 0 1
0 0 0
3 0 0
2 3 2

3 3
3 0 1
0 0 0
2 0 0
2 3 2

3 3
3 0 1
0 0 0
2 0 0
1 3 3

3 3
3 0 1
0 0 0
2 0 0
2 3 3

5 3
3 0 0 0 0 
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 5 5

5 3
2 0 0 0 3 
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 0 0 0 0
3 5 5

5 3
3 0 0 0 0 
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
7 5 5

*/
