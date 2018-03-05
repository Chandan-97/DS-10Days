#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

void traverse_list(struct Node *head);
void generate_error(string str, int line);
bool memory_error(struct Node *newNode);
bool insert_at_head(struct Node **head_ref, int data);
bool insert_at_tail(struct Node **head_ref, int data);


int main(){

	struct Node *head = NULL;

	for(int i=0; i<5; i++){
		int x;
		cin>>x;
		if(!insert_at_tail(&head, x)){
			generate_error("Cannot add into the list", __LINE__);
		}
		traverse_list(head);
	}

	return 0;
}

bool insert_at_tail(struct Node **head_ref, int data){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

	if(memory_error(newNode))
		return false;

	newNode->data = data;
	newNode->next = NULL;

	if(!*head_ref){
		*head_ref = newNode;
		return true;
	}

	struct Node *current = *head_ref;

	while(current->next)
		current = current->next;
	current->next = newNode;
	return true;
}

bool insert_at_head(struct Node **head_ref, int data){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

	if(memory_error(newNode))
		return false;

	newNode->data 	= data;
	newNode->next 	= *head_ref;
	*head_ref 		= newNode;
	return true;
}

bool memory_error(struct Node *newNode){
	if(!newNode){
		cout<<"Memory Error"<<endl;
		return true;
	}
	return false;
}

void traverse_list(struct Node *head){
	struct Node *current = head;
	cout<<"List : ";
	while(current){
		cout<<current->data<<", ";
		current = current->next;
	}
	cout<<endl;
}

void generate_error(string str, int line){
	cout<<"[Error]:"<<line<<" : "<<str<<endl;
}
