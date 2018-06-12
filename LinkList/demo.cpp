#include<iostream>
#include<malloc.h>
using namespace std;

struct node {
	int data;
	struct node *next;
};


void push_back(int data, struct node **head) {
		struct node *newNode;
		newNode = (struct node*) malloc(sizeof(struct node));
		newNode->data = data;
		newNode->next = NULL;
		
		if (*head == NULL) {
			*head = newNode;
			return ;
		}
		
		struct node *temp = *head;
		while(temp->next!=NULL) {
			temp = temp->next;
		}
		temp->next  = newNode;
		return;
		
	}
	

void segregateEOWithOrder(struct node **head){
		
			struct node *current = *head, *prev = NULL, *end=*head;
		
		while(end->next!=NULL){
			end  = end->next;
		}
		
		while(current!=end){
			
			
			
			if(current->data %2 == 1){
				struct node *temp = current->next;
				push_back(current->data,head);
				free(current);
				current = temp;
				if(prev!=NULL){
					prev->next = current;
				}else {
					*head = current;
				}
			}
			else {
				prev = current;
				current = current->next; }
		}
		if(end->data %2 == 1 && prev->data == 0){
			struct node *temp = end->next;
			push_back(end->data, head);
			free(end);
			*head = temp;
		}
		
		
	}
	
	void printList(struct node **head) {
		struct node *temp = *head;
		
		while(temp!=NULL) {
			std::cout<<temp->data<<" ";
			temp= temp->next;
		}	
		
		return;
	} 
	
int main() {
    
    int tc, n, i;
    
    cin>>tc;
    while(tc--){
        struct node *head = NULL;    
        cin>>n;
        for(int j=0; j<n;j++){
            cin>>i;
            push_back(i,&head);
        }
        
        segregateEOWithOrder(&head);
        printList(&head);
        cout<<endl;
        
    }
    
    return 0;
}

