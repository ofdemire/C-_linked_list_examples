#include <iostream>
#include "linked_list_example.h"
#include <cmath>

#ifndef MARMOSET_TESTING
int main();
#endif

//node functions

Node::Node( unsigned int id, std::string frag, Node* pointer ){
	identifier = id;
	fragment =frag;
	p_next=nullptr;
}



Node *Node::get_next(){
	return p_next;
}

std::string Node::get_fragment(){
	return fragment;
}

//Message functions

Message::Message(){
	head = nullptr;

}

Message::~Message(){
	Node *traverse{head};

	while(traverse!=nullptr){
		traverse=head;
		
		head = traverse->p_next;
		delete traverse;
		traverse=nullptr;
	}	

}

void Message::reverse(){
	Node* traverse{head};
	Node* traverse_last{head};
	int temp{0};

	int capacity{0};

	while(traverse!=nullptr){
		++capacity;
		traverse=traverse->p_next;
	}

	traverse=head;

	for(int i{0}; i < capacity/2; ++i){
		for(int k{0}; k < i ;++k)
			traverse= traverse->p_next;

		for(int k{0}; k < capacity-1-i; ++k){
			traverse_last=traverse_last->p_next;
		}

		temp = traverse->identifier;
		traverse->identifier=traverse_last->identifier;
		traverse_last->identifier=temp;

		traverse=head;
		traverse_last=head;


	}



}

void Message::insert( unsigned int id, std::string fragment){
	Node *new_node{new Node{id, fragment}};

	Node *traverse{head};

	if(head!=nullptr){
		while(traverse->p_next!=nullptr && id > traverse->p_next->identifier){
			traverse = traverse->p_next;
		}
		if(traverse->identifier <  new_node->identifier){
			new_node->p_next=traverse->p_next;
			traverse->p_next=new_node;
		}
		else{
			new_node->p_next=traverse;
			head=new_node;

		}
	}
	else{
		head=new_node;

	}



}

void Message::print_message(){
	Node *traverse{head};
	int length{0};
	bool is_EOT_received{0};

	while(traverse!=nullptr){
		length = traverse->identifier+1;

		if(traverse-> fragment == "EOT"){
			is_EOT_received=1;
			length=traverse->identifier;
			break;
		}
		traverse= traverse->p_next;
	}


	traverse=head;
	

	for(int i{0}; i< length;++i){
		if(i == traverse->identifier){
			std::cout << traverse->fragment;
			if(traverse->p_next != nullptr)
				traverse=traverse->p_next;
		}
		else
			std::cout << "...";
 
		if(i != length-1)
			std::cout << " ";
		else if(i == length-1 && is_EOT_received){
			std::cout << " ";
		}
		else if(!is_EOT_received)
			std::cout << " " << "???";

		

	}

	std::cout << std::endl;
}

bool Message::pop_back(){
	if(head==nullptr)
		return 0;
	else{
		Node* previous{nullptr};
		Node* traverse{head};

		while(traverse->p_next!=nullptr){
			previous=traverse;
			traverse=traverse->p_next;
		}

		if(previous==nullptr){
			delete traverse;
			traverse=nullptr;
		}
		else{
			previous->p_next=traverse->p_next;
			delete traverse;
			traverse=nullptr;
		}
	}
}

void Message::print2(){
	Node* traverse{head};

	while(traverse!=nullptr){
		std::cout << traverse->identifier << std::endl;
		traverse=traverse->p_next;
	}
}

unsigned int Message::operator[](int position){

	Node* traverse{head};

	for(int i{0}; i <position;++i)
			traverse=traverse->p_next;

	return traverse->identifier;	
}


void Message::merge_array(unsigned int arr[], int capacity){
	Node* traverse{head};
	Node* previous{nullptr};

	for(int i{0}; i <capacity; ++i){

		insert(arr[i], " asd");
		Node* new_node{new Node{arr[i], "asd", nullptr}};

		if(head!=nullptr)
			head=new_node;
		else{
			while(traverse!=nullptr && arr[i] > traverse->identifier){
				previous=traverse;
				traverse= traverse->p_next;
			}
			if(previous==nullptr){
				head=new_node;
				new_node->p_next=traverse;
			}

			else{
				previous->p_next=new_node;
				new_node->p_next = traverse;
			}
		}
		traverse=head;
		previous=nullptr;
	}
}


int Message::search(int datum){
	int position{1};
	Node* traverse{head};


	if(head==nullptr)
		return 0;
	else{
		while(traverse!=nullptr && datum!=traverse->identifier)
		{
			traverse=traverse->p_next;
			++position;
		}
		if(traverse==nullptr)
			return 0;
		else{
			return position;
		}
	}
}

#ifndef MARMOSET_TESTING

int main(){

	int k{0};
	std::string temp;
	Message header{};
	while(std::cin >> k && k>-2){
		if(k==-1){
			header.print_message();
		}
		else{
			std::cin >> temp;
			header.insert(k,temp);
		}
	}


	unsigned int all[2]{1,34};

	header.merge_array(all,2);

	header.print2();

	std::cout << std::endl;

	std::cout << std::endl;
		std::cout << std::endl;
	std::cout << header[0] << std::endl;



	return 0;
}

#endif
