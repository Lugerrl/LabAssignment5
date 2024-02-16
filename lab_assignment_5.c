#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;	
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
    int len = length(head);
    char* str = (char*)malloc((len + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
	}
    int i = 0;
    while (head != NULL) {
        str[i++] = head->letter;
        head = head->next;
    }
    str[i] = '\0';
    return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->letter = c;
    newNode->next = NULL;

    if (*pHead == NULL) {
        *pHead = newNode;
    } else {
        node* temp = *pHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    while (*pHead != NULL) {
        node* temp = *pHead;
        *pHead = (*pHead)->next;
        free(temp);
    }
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}