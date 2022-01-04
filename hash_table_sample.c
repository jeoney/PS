//https://velog.io/@jewelrykim/C%EB%A1%9C-%ED%95%B4%EC%8B%9C%ED%85%8C%EC%9D%B4%EB%B8%94-%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0

#include <stdio.h>
#include <stdlib.h>

struct bucket* hashTable = NULL;
int BUCKET_SIZE = 10; //동일 key를 갖는 item이 나올 경우 linked list로 연결할 아이템 최대 개수 (버킷)

//node structure
struct node{
	int key; //hash 함수에 사용될 key (찾을 값) 
	int value; // key가 갖고 있는 데이터 
	struct node* next; //다음 노드를 가르키는 포인터 
};

struct bucket{
	struct node* head; //버켓 가장 앞에 있는 노드 포인터 
	int count; //버켓에 들어가 있는 노드 개수 
};

//createNode -> 새로운 노드를 만들어주는 함수
//hashFunction -> 키를 해쉬 인덱스로 변환해주는 해쉬 함수
//add -> 키를 해쉬 테이블에 추가하는 함수
//remove_key -> 키를 해쉬 테이블에서 삭제하는 함수
//search -> 키의 데이터값을 찾아주는 함수
//display -> 해쉬테이블 자체를 출력해서 보여주는 함수

//node를 생성하고, 값을 대입하고, next는 NULL로 설정(맨 끝에 넣음) 
struct node* createNode(int key, int value) 
{
	struct node* newNode;
	
	//memory allocation
	newNode = (struct node *)malloc( sizeof(struct node) );
	
	//add values
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;
	
	return newNode;
}

int hashFunction(int key)
{
	return key%BUCKET_SIZE;
}

void add(int key, int value)
{
	//어느 bucket에 추가할 지 index 계산
	int hashIndex = hashFunction(key);
	
	//새로 노드 생성
	struct node* newNode = createNode(key, value) ;
	
	//계산한 index 버킷에 아무 노드도 없을 경우
	if(hashTable[hashIndex].count == 0)
	{
		hashTable[hashIndex].count = 1;
		hashTable[hashIndex].head = newNode;
	}
	else //이미 노드가 있는 경우, 
	{
		newNode->next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count++;
	}
}

int main()
{
	return 0;
}
