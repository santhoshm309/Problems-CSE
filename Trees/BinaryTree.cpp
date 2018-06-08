	// Binary Trees
	
	//#include<bits/stdc++.h>
	#include<iostream>
	#include<algorithm>
	#include<string>
	#include<map>
	#include<vector>
	#include<malloc.h>
	#include<queue>
	using namespace std;
	
	struct node {
		int data;
		struct node * left;
		struct node * right;
	};
	
	void inorder(struct node *root) {
		// in order traversal
		if(!root) {
			return;
		}
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
	
	
	struct node * createNewNode(int data) {
		// Function to create a new Node;
		struct node *newNode  = (struct node *)malloc(sizeof(struct node *));
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	
	void insert(int data, struct node ** root) {
		// Function to insert an element into the Binary Tree using level order traversal;
		queue<struct node*> q;
		struct node* newNode = createNewNode(data);
		if(*root == NULL) {
			*root = newNode;
			return;
		}
		q.push(*root);
		
		while(!q.empty()){
			
			struct node *temp = q.front();
			q.pop();	
			if(!temp->left){
				temp->left = newNode;
				return;
			}else{
				q.push(temp->left);
			}
			
			if(!temp->right){
				temp->right = newNode;
				return;
			}else {
				q.push(temp->right);
			}
			
		}
		
		
	}
	
	int maxElement(struct node *root){
		// Returns the maximum element in a BT
		int left, rootMax, right = INT_MIN;
		if(root) {
			left = maxElement(root->left);
			right = maxElement(root->right);
			rootMax = max(root->data,max(left,right));
			return rootMax;
		}
		
	}
	
	
	int sizeOfTree(struct node *root) {
		// Gives the count of nodes in a BT
		if (!root){
			return 0;
		}
		return sizeOfTree(root->left) + 1 + sizeOfTree(root->right);
	}
	
	
	bool findElement(int data, struct node *root){
		
		queue<struct node *>q;
		
		q.push(root);
		while(!q.empty()){
			
			struct node *temp = q.front();
			q.pop();
			if(temp->data==data){
				return true;
			}
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
		return false;
	}
	
	
	int heightOfTree(struct node *root) {
		int lheight, rheight;
		if(!root){
			return 0;
		}
		
		lheight = heightOfTree(root->left);
		rheight = heightOfTree(root->right);
		
		return lheight > rheight ? lheight + 1 : rheight + 1;
	}
	
	
	int deepestNode(struct node *root) {
		
		queue<struct node *> q;
		q.push(root);
		struct node *temp;
		while(!q.empty()){
			temp = q.front();
			q.pop();
			if(temp->left) {
				q.push(temp->left);	
			}
			if(temp->right) {
				q.push(temp->right);	
			}
			
		}
		
		return temp->data;
	}
	
	int sum(struct node *root){
		if(!root) {
			return 0;
		}
		return  root->data +sum(root->left)+ sum(root->right);
	}
	
	// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
	 void horizontalDistance(struct node *root, int d, map<int, vector<int> >& m) {
		
		
		if(!root){
			return;
		}
		
		if(m.find(d)!=m.end()){
			//cout<<d<<" IF ";
				vector<int> q = m[d];
				
				q.push_back(root->data);
			//	cout<<root->data<<" ";
				m[d] = q;
		}else {
			vector<int> v;
			
			v.push_back(root->data);
				//cout<<d<<" ELSE ";
			//cout<<root->data<<" ";
			m.insert(pair<int,vector<int> >(d,v));	
		}
		
		if(root->left){
			horizontalDistance(root->left,d-1,m);
		}
		
		if(root->right){
			horizontalDistance(root->right,d+1,m);
		}
		
		
		return;
	}
	
	void constructInorder(struct node *root, vector<int>& inord){
		
		if(root == NULL){
			return;
		}
		constructInorder(root->left,inord);
		inord.push_back(root->data);
			constructInorder(root->right,inord);
	}
	
	bool isPalindrome(vector<int> s){
		for(int i=0,j=s.size()-1; i!=j; i++,j--){
			if(s[i]!=s[j]) {
				return false;
			}
		}
		return true;
	}
	
	
	bool isSymetric(struct node *root) {
		vector<int> s;
		constructInorder(root, s);
		return isPalindrome(s);
	}
	
	diameterUtil(struct node *root, int &ans){
		
		if(!root){
			return 0;
		}
		int left = diameterUtil(root->left,ans);
		int right = diameterUtil(root->right, ans);
		ans = max(ans, left+right+1);
		return max(left, right)+1;
	}
	
	
	int diameter(struct node *root){
		if(!root){
			return 0;
		}
		int diameter = INT_MIN;
		diameterUtil(root,diameter);
			return diameter;
	}
	
	void serialize(struct node *root, vector<int>& A){
		queue<struct node *> q;
		if(!root){
			A.push_back(-1);
			return;
		}
		A.push_back(root->data);
		serialize(root->left,A);
		serialize(root->right,A);
	}
	
	 struct node * deSerialize(vector<int> &A, int *i){
		 
		 if(*i<A.size() && A[*i]!=-1)
    {
        struct node* root=createNewNode(A[*i]);
        *i=*i+1;
        root->left=deSerialize(A,i);
        root->right=deSerialize(A,i);
        return root;
    }
    if(*i<A.size())
        *i=*i+1;
    return NULL;
	}
	
	
	int main() {
		struct node * root = NULL;
		for(int i=1; i<6;i++){
			insert(i,&root);
		}
	
	//	insert(10,&root);
	//	insert(20,&root);
	//	insert(30,&root);
	//	insert(40,&root);
	//	insert(60,&root);
		inorder(root);
		cout<<"\nMax element is "<<maxElement(root);
		int n = 3;
		cout<<endl<<findElement(n,root);
		cout<<endl<<"Size of the tree is "<<sizeOfTree(root);
		
		/* Height of a binary tree
			https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
		*/
		cout<<endl<<"Height of the tree is "<<heightOfTree(root);
		
		
		cout<<endl<<"Deepest node of the tree is "<<deepestNode(root);
		cout<<endl<<"Sum is "<<sum(root);
		map<int,vector<int> > m;
		map <int, vector<int> > :: iterator itr;
		cout<<endl;
		vector<int> v;
		
		// Program to print bottom view of a tree
		// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
		
		horizontalDistance(root,0,m);
		for(itr=m.begin(); itr!=m.end(); itr++){
			v = itr->second;
			cout<<v[v.size()-1]<<" ";
		}
		cout<<endl;
		
		/* Program to print a tree vertically 
			https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
		 */  
		for(itr=m.begin(); itr!=m.end(); itr++){
			v = itr->second;
			sort(v.begin(), v.end());	
			for(int i=0; i<v.size();i++){
				cout<<v[i]<<" ";
			}
			cout<<"$";
		}
		
		/* Is the binary tree symetric
			https://practice.geeksforgeeks.org/problems/symmetric-tree/1
		*/
		
		cout<<endl;
		cout<<isSymetric(root);
		
		/*
				Diameter of a tree
				https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1 
		*/
		cout<<endl;
		cout<<"Diameter of the tree is "<<diameter(root);
		
		/* Serialize and Deserialize a tree
			https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
		*/
		 
		
		cout<<endl<<"Serializing";
		vector<int> A;
		serialize(root,A);
		cout<<endl<<"Deserializing";
		cout<<endl;	
		struct node *tempRoot = NULL;
		int i=0;
		tempRoot = deSerialize(A,&i);
		cout<<endl<<"Inorder Tra"<<endl;
		inorder(tempRoot);
	}
