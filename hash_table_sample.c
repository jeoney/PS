//https://velog.io/@jewelrykim/C%EB%A1%9C-%ED%95%B4%EC%8B%9C%ED%85%8C%EC%9D%B4%EB%B8%94-%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0
#include <stdio.h>
#include <stdlib.h>

struct bucket* hashTable = NULL;
int BUCKET_SIZE = 10; //동일 key를 갖는 item이 나올 경우 linked list로 연결할 아이템 최대 개수 (버킷)

int dbg = 1;

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
	struct node* newNode = createNode(key, value);	
	
	if(dbg) printf("try to add hashTable[%d],count:%d :%d,%d\n", hashIndex, hashTable[hashIndex].count, key, value);
	//계산한 index 버킷에 아무 노드도 없을 경우
	if(hashTable[hashIndex].count == 0)
	{
		hashTable[hashIndex].count = 1;
		hashTable[hashIndex].head = newNode;
		if(dbg) printf("add success as head:%d,%d\n", key, value);
	}
	else //이미 노드가 있는 경우, 
	{
		newNode->next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count++;
		if(dbg) printf("add success :%d,%d\n", key, value);
	}
}

void remove_key(int key)
{
	int hashIndex = hashFunction(key);
	
	//삭제 여부 flag
	int flag = 0;
	
	//키 찾을 iterator
	struct node* node;
	struct node* before; //직전노드: 삭제후 연결을 위해 

	//from head
	node = hashTable[hashIndex].head;

	if(dbg) printf("try to remove the key:%d\n", key);

	//while(node != NULL && flag == 0) //|| flag == 1 도 추가하면 좋지 않을까 
	while(node != NULL) //|| flag == 1 도 추가하면 좋지 않을까 
	{
		if(dbg) printf("check to remove the key:%d, node->key:%d\n", key, node->key);

		if(node->next == NULL)
		{
			if(dbg) printf("node->key:%d, key:%d, next:NULL\n", node->key, key);
		}
		else
		{
			if(dbg) printf("node->key:%d, key:%d, next:exist\n", node->key, key);
		}

		if(node->key == key) 
		{
			//if node is head
			if(node == hashTable[hashIndex].head)
			{
				hashTable[hashIndex].head = node->next; //the next node of the current node would be head from now on
			}
			else
			{
				before->next = node->next; //the prev node's next would be the next node of current node
			}

			//other actions doing
			hashTable[hashIndex].count--;
			free(node);
			flag = 1;
		}

		//
		before = node;
		node = node->next;
	}

	if(flag)
		printf("[%d] 키가 삭제 되었습니다. \n", key);
	else
		printf("[%d] 키를 못 찾았습니다. \n", key);
}

void search(int key)
{
	int hashIndex = hashFunction(key);
	struct node* node = hashTable[hashIndex].head;
	int flag = 0;
	
	while(node != NULL)
	{
		if(node->key == key)
		{
			flag = 1;
			break;
		}
		node = node->next;
	}

	if(flag == 1)
	{
		printf("키는 %d, 값은 %d 입니다.\n", node->key, node->value);
		//return node->value;
	}
	else
	{
		printf("%d 키가 존재하지 않습니다.", key);
		//return -1;
	}

}

void display()
{
	int i;
	struct node* iterator;
	printf("print start:: \n");
	
	for(i=0; i<BUCKET_SIZE; i++)
	{
		iterator = hashTable[i].head;
		printf("Bucket[%d]: ", i);
		
		while(iterator != NULL)
		{
			printf("(key:%d/value:%d) -> ", iterator->key, iterator->value);
			iterator = iterator->next;
		}
		printf("NULL\n");
	}
	printf("-------------------------------\n");
}

int main()
{
	int i=0;
	hashTable = (struct bucket *)malloc(BUCKET_SIZE * sizeof(struct bucket));
	memset(hashTable, 0, BUCKET_SIZE * sizeof(struct bucket));

    // 15 까지 값 추가
    for (i=0; i < 16; i++)
	{
        add(i, 10*i);
    }

    // 몇개 더 추가
    add(21, 210);
    add(31, 310);
    add(41, 410);

    display();
    
    remove_key(31);
    display();
    remove_key(11);
    remove_key(51);
    
    display();
    
    //search(11)
    

	return 0;
}



