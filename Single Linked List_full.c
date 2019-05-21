#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  	int data;
  	struct node *next; 	// pointer to next data the link
} node;

node* BuildLL(int n);
void traverseLL(node *head);
int lenLL(node *head);
void insertfront(node **head);
void insertafter(node **head);
void append(node **head);
void delfront(node **head);
void delend(node **head);
void delpos(node **head);

int main() {
	node *header;
	int n;
	printf("ENTER no of elements in the linked list: ");
	scanf("%d", &n);
	header = malloc(sizeof(node));
	header = BuildLL(n);
	// traverseLL(header);
	insertfront(&header);
	printf("\nNew LinkedList:\n");
	traverseLL(header);
	insertafter(&header);
	printf("\nNew LinkedList: \n");
	traverseLL(header);
	append(&header);
	printf("\nNew LinkedList:\n");
	traverseLL(header);
	delfront(&header);
	printf("\nNew LinkedList:\n");
	traverseLL(header);
	delend(&header);
	printf("\nNew LinkedList:\n");
	traverseLL(header);
	delpos(&header);
	printf("\nNew LinkedList:\n");
	traverseLL(header);
}

// Builds a linked list of size n
node* BuildLL(int n) {
	node *header;
	node *newnode, *temp;
	int data,i;
	
	if (n>0) {
		newnode = (node *) malloc(sizeof(node));
		if (newnode == NULL)
			printf("Unable to allocate memory");
		else {
			scanf("%d ",&data);
		
			newnode->data = data; 	// Links data field of newnode with data
			newnode->next = NULL;	// Links the address field with NULL
			header = newnode;		// Header points to the first node
			temp = newnode;			// First node is the current node
		
			for (i=2; i<=n; i++) {
				// A New node is created by allocating memory in the heap
				newnode = (node *)malloc(sizeof(node));
				if (newnode == NULL) {
					printf("Unable to allocate memory.");
					break;
				}
				else {
					scanf("%d", &data);
					newnode->data = data;
					newnode->next = NULL;
					temp->next = newnode; 	// Links the previous temp node to newly created newnode
					temp = temp->next;				
				}
			}
		}	
	}
	else 
		header = NULL;
		
	// At this point, the linked list referenced by the pointer "header"
	return header;
}

// Traverses through the LL and prints the data of each node.
void traverseLL (node *head){
	if (head == NULL)
		printf("Linked List is empty!");
	else {
		while(head != NULL) {
			printf("%d ",head->data);
			head = head->next;
		}
		printf ("\n");
	}
	return ;
}

// Counts the no.of nodes in LinkedList
int lenLL(node *head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

// Inserts a node at front of the LinkedList
void insertfront(node **head) {
	node *newNode;
	int new_data;
  	printf("\nEnter the value you want to add to beginning of the linked list: ");
  	scanf("%d", &new_data); 
    newNode = (struct node*)malloc(sizeof(struct node));
 
    if(newNode == NULL) {
    	printf("Unable to allocate memory.");
    }
    else{
    	newNode->data = new_data; 	//Links the data part
        newNode->next = *head; 	//Links the address part
 
        *head = newNode; 	//Makes newNode as first node
 
        printf("Data Inserted Successfully!");
    }
return ;
}

// Inserts a node at random position
void insertafter(node **head) { 
    // Check if the given prev_node is NULL
    int i, position;
    printf("\nAfter what position you want to add node: ");
    scanf("%d", &position);
    if (position > lenLL(*head) || position < 0){
    	printf("Failed to insert becauase entered position is Invalid!");
		return;
	}
    else {
		node *middle = *head;
  		int new_data;
  		printf("Enter the value you want to add in the linked list: ");
  		scanf("%d", &new_data);
    	// Allocate new node
    	struct node* newnode =(struct node*) malloc(sizeof(struct node)); 
    	if (newnode == NULL) {
    		printf("\nUnable to allocate memory.");
		}
		else {
			for(i=1; i<position-1; i++){
				middle = middle->next;	
			}
			newnode->data  = new_data; // put in the data
    		newnode->next = middle->next; 	// // Make next of new node as next of prev_node 
    		middle->next = newnode; // move the next of prev_node as new_node
			
    	}
    	printf("Data Inserted Successfully!");
    }
    return;
} 

// Inserts a node at the end of LinkedList
void append(node **head) {
	node *newnode,*last; 
	last = *head;
	int new_data;
  	printf("\nEnter the value you want to add at the end of the linked list: ");
  	scanf("%d", &new_data);
    newnode = (struct node*)malloc(sizeof(struct node));
 
    if(newnode == NULL) {
    	printf("Unable to allocate memory.");
    }
    else{    	
    	newnode->data = new_data; 	//Links the data part
        newnode->next = NULL; 	//Links the address part
 
        if (*head == NULL){
			*head = newnode; 	//Makes newNode as the only node
 			return;
 		}
 		while (last->next != NULL)
 			last = last->next;
 		
 		last->next = newnode;
        printf("Data Inserted Successfully!");
    }
return ;
}

// Deletes a node from the front of the linked list.
void delfront(node **head) {
	node *todelete;
	todelete = *head;
	*head = todelete->next;
	free(todelete);
	printf("\nDeleted a node from the front Successfully!");
}

// Deletes a node fron the end of the Linked List.
void delend(node **head) {
	node *todelete,*prevlast;
	todelete = *head;
	while (todelete->next != NULL){
		prevlast = todelete;
		todelete = todelete->next;
	}
	prevlast->next = NULL;
	free(todelete);
	//free(prevlast)
	printf("\nDeleted a node from the end Successfully!");
}

// Deletes a node at user defined position.
void delpos(node **head) {
	node *todelete,*temp;
	todelete = *head;
	temp = *head;
	int position,i=1;
	printf("\nAt what position do you want to delete a node: ");
	scanf("%d", &position);
	if (position > lenLL(*head) || position < 0){
		printf("Failed to delete a node because entered position is Invalid!");
		return;
	}
	while (i<position){
		temp = todelete;
		todelete = todelete->next;
		if(todelete == NULL)
			break;
		i++;
	}
	if (position == 1){
		*head = todelete->next;
	}
	else if (position == lenLL(*head)) {
		temp->next = NULL;	
	}
	else
		temp->next = todelete->next;
	
	free(todelete);
	printf("Deleted a node from the %d position Successfully!", position);
}
