// linklist.cpp function definitions for the header

#include<iostream>
#include<malloc.h>
#include<map.h>
#include<stack>
struct node {
	int data;
	struct node *next;
};





	void printList(struct node **head) {
		struct node *temp = *head;
		
		while(temp!=NULL) {
			std::cout<<temp->data<<"--->";
			temp= temp->next;
		}	
		
		return;
	} 
		
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
	
	void rotateList(int k, struct node **head){
		
		struct node *temp, *current = *head;
		struct node *end = *head;
		while(end->next!=NULL){
			end = end->next;
		}
		while(k>1){
			current = current->next;
			--k;
		}
		if(!current){
			return;
		}
		end->next = *head;
		*head = current->next;
		current->next = NULL;
		
	}


	void reverseList(struct node **head){
		struct node *cur, *prev, *next;
		prev = NULL;
		cur = *head;
		next = NULL;
		
		while(cur !=NULL)
		{	
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur=next;
			
		}
		
		*head = prev;
		return;
	}	
		
		
	void reverseListInGroups(struct node **head, int k) {
		
		struct node *start, *prev, *cur, *end, *next;
		cur = *head;
		next = NULL;
		prev = NULL;
		start = *head;
		end = *head;
		int i = k;
		
	}
	
	void swap(int &a, int &b){
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	
	
	void pairWiseSwap(struct node *head){
			
		// This function swaps data and does not alter links.

	
		struct node* temp = head;
		
		while(temp && temp->next){
			swap(temp->data, temp->next->data);
			temp = temp->next->next;
		}
		
		
	}
	
	void swapElements(struct node **head, int x, int y) {
		
		if(x==y) return;
		
		struct node* prev_x=NULL, *curr_x=*head;
		struct node* prev_y=NULL, *curr_y=*head;
		
		while(curr_x && curr_x->data != x){
			prev_x = curr_x;
			curr_x = curr_x->next;
		}
		
		if(!curr_x) return;
		
		while(curr_y && curr_y->data != y){
			prev_y = curr_y;
			curr_y = curr_y->next;
		}
		
		if(!curr_y) return;
		
		if(prev_x!= NULL){
			prev_x->next = curr_y;
					
		}else {
			*head = curr_y;
		}
		
		if(prev_y!= NULL){
			prev_y->next = curr_x;
		}else {
			*head = curr_x;
		}
		
		struct node * temp = curr_y->next;
		curr_y->next = curr_x->next;
		curr_x->next= temp;
	}
		
	void segragateEvenAndOdd(struct node* head){
		// This function segregates even and odd , but does not keep the order of the elements.
		struct node *current = head;
		struct node *odd;
		while(current!=NULL){
			
			if(current->data %2 == 1) {
				
				odd = current;
				while(odd!=NULL && odd->data % 2!= 0) {
					odd=odd->next;
				}
				
				if(odd == NULL) return;
				else {
					
					swap(current->data, odd->data);
					odd = current;
				}
				current = current->next;
			}
			else {
				current = current->next;
			}
			
		}
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
		
		if(end->data %2 == 1){
			struct node *temp = end->next;
			push_back(end->data, head);
			free(end);
			*head = temp;
		}
		
		
	}
	
	
	
	void intersection(struct node * head1, struct node *head2){
		
		// Intersection of 2 sorted lists
		struct node *inter_head = NULL;
		while(head1 && head2){
			if(head1->data == head2->data){
				push_back(head1->data, &inter_head);
				head1 = head1->next;	
				head2 = head2->next;
			}else if(head1->data < head2->data){
				head1 = head1->next;
			}else {
				head2 = head2->next;
			}
		}
		cout<<endl;
		printList(&inter_head);
		
	}
	
	bool findLoop(struct node *head) {
		
		map<struct node *, bool> visited;
		while(head!=NULL){
			if(visited.find(head) != visited.end()){
				return true;
			}
			else {
				visited[head] = true;
			}
			head = head->next;
		
			
		}
		return false;
		
	}
	
	
	void removeDuplicates(struct node *head){
		
		map<int,bool> visited;
		struct node *prev = NULL, *current = head;
		
		while(current!=NULL){
			if(visited.find(current->data) == visited.end()){
				visited[current->data] = true;
				prev = current;
				current = current->next;
			
			}else {
				
				struct node *temp = current->next;
				prev->next = temp;
				free(current);
				current = temp;
			}
		}
		cout<<endl;
		printList(&head);
		
	}
	
	void alternateEvenAndOdd(struct node *head) {
		
			stack<struct node *> odd;
			stack<struct node *> even;
			
			struct node *current =  head;
			int i=1;
			while(current!=NULL){
				
				
				if(i%2==0 && current->data %2 != 0){
					odd.push(current);
				}
				else if(i%2 ==1 && current->data %2 ==0){
					even.push(current);
				}
				
				current  = current->next;
				i++;
			}
			
		while(!odd.empty() && !even.empty()){
			swap(odd.top()->data, even.top()->data);
			odd.pop();
			even.pop();
		}
		cout<<endl;
		printList(&head);
		
	}
	

	void deleteAlternateNodes(struct node *head){
		
		struct node *current = head->next;
		struct node *prev  = head;
		while(prev!=NULL && current!=NULL){
			
			struct node *temp = current->next;
			prev->next = temp;
			free(current);
			prev = temp;
			if(prev!=NULL)
				current = prev->next;
		}
		cout<<endl;
		printList(&head);
		
	}
	
int main() {
	
	struct node *head = NULL;
	//push_back(5, &head);
	//push_back(6, &head);
	//push_back(7, &head);
	for(int i=1; i< 6; i++)
	{	
		push_back(i,&head);
	}
	printList(&head);
	cout<<endl;
	cout<<"Rotating List by 3 units"<<endl;
	
	/* Rotate a link list counter clockwise by 3 units 
		
	*/ 
	
//	rotateList(2, &head);
	cout<<endl;
	//printList(&head);
	
	/* Reverse a linklist 
	
	*/
	cout<<endl;
	//reverseList(&head);
	//printList(&head);
	
	/* Pairwise swap in a list */
	cout<<endl;
	//pairWiseSwap(head);
	//printList(&head);
	
	
	cout<<endl;
	swapElements(&head, 1,4);
	printList(&head);
	
	cout<<endl;
	struct node *head1 = NULL, *head2 = NULL;
	for(int i=1; i<7; i+=2){
		push_back(i,&head1);
	}
	for(int i=2; i<8; i+=2){
		push_back(i,&head2);
	}

	struct node *inter = NULL;
	intersection(head2, head1);
	printList(&inter);
	
	cout<<endl;
	//cout<<"Segregating odd and even\n ";
	//segragateEvenAndOdd(head1);
	//printList(&head1);
	
	
	
	// ------------------------------ Wrong code --------------------- fails for corner case
	cout<<"Segregating odd and even\n ";
	segregateEOWithOrder(&head1);
	printList(&head1);
	
	//	head1->next = head1;
	
	// Finding loop in a link list ..............................................
	
	cout<<endl;
	cout<<findLoop(head1);
	
	struct node *dup_head = NULL;
	for(int i=1; i<7; i++){
		push_back(i,&dup_head);
		push_back(i,&dup_head);
	}
	// Removing duplicates in a link list
	removeDuplicates(dup_head);
	
	// Alternate odd and even in a link list
	alternateEvenAndOdd(head);
	
	// Delete alternate nodes in a linklist
	
	
	struct node *head3 = NULL;
	for(int i=1; i<7; i++){
		push_back(i,&head3);
		push_back(i,&head3);
	}
	deleteAlternateNodes(head3);
	return 0;
}
