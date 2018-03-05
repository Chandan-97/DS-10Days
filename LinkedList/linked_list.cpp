#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

bool insert_at_head(struct Node **head_ref, int data){
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

	if(!newNode){
		cout<<"Memory Error"<<endl;
		return false;

	}
	newNode->data 	= data;
	newNode->next 	= *head_ref;
	*head_ref 		= newNode;
	return true;
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

void generate_error(string str){
	cout<<"[Error] : "<<str<<endl;
}

int main(){

	struct Node *head = NULL;

	for(int i=0; i<5; i++){
		int x;
		cin>>x;
		if(!insert_at_head(&head, x)){
			generate_error("Cannot add into the list");
		}
		traverse_list(head);
	}




	return 0;
}