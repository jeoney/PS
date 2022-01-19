//주사위를 던진 횟수 N과 출력형식 M을 입력 받아서 M의 값에 따라 각각 아래와 같이 출력하는 프로그램을 작성하시오.
//순열은 순서가 중요. 순서가 다르면 다른 순열. 
//조합은 순서가 중요하지 않음. 순서가 달라도 같은 조합
//M = 1 : 주사위를 N번 던져서 나올 수 있는 모든 경우 //중복 순열
//M = 2 : 주사위를 N번 던져서 중복이 되는 경우를 제외하고 나올 수 있는 모든 경우 //순열
//M = 3 : 주사위를 N번 던져서 모두 다른 수가 나올 수 있는 모든 경우 //조합

#include <stdio.h>
#define MAXN 5

int M, N;
int arr[MAXN];
int visit[10];

void permutation_w_dup(int depth)
{
  int i=0, j=0;

  if(depth==N) //made permutation
  {
    for(j=0; j<N; j++)
    {
      printf("%d ", arr[j]);
    }
    printf("\n");
    return;
  }

  for(i=1; i<=6; i++)
  {
    arr[depth] = i; //add value to print
    depth++;
    permutation_w_dup(depth);
    depth--;
  }

  return;
}

void permutation(int start, int depth)
{
  int i=0, j=0;

  //made condition (exit condition for recursive)
  if(depth==N)
  {
    for(j=0; j<N; j++)
    {
      printf("%d ", arr[j]);
    }
    printf("\n");
    return;
  }

  for(i=start; i<=6; i++)
  {
    arr[depth] = i;
    depth++;
    permutation(i, depth);
    depth--;
  }
}

void combination(int depth)
{
  int i=0, j=0;

  //made condition (exit condition for recursive)
  if(depth==N)
  {
    for(j=0; j<N; j++)
    {
      printf("%d ", arr[j]);
    }
    printf("\n");
    return;
  }

  for(i=1; i<=6; i++)
  {
    //check already picked. we cannot pick same number
    if(visit[i]) continue;

    arr[depth] = i;
    visit[i] = 1;
    depth++;
    combination(depth);
    depth--;
    visit[i] = 0;
  }
}

int main()
{
  scanf("%d %d", &N, &M);

  switch(M)
  {
    case 1:
      permutation_w_dup(0);
    break;

    case 2:
      permutation(1, 0);
    break;


    case 3:
      combination(0);
    break;

    default:
      printf("not supported modes\n");
    break;
  }

  return 0;
}

