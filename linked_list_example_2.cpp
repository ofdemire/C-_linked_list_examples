#include <iostream>

class Node{
public:
	Node(int id,Node* pointer=nullptr);
	friend class Linked_list;

private:
	int identifier;
	Node* p_next;
};

class Linked_list{
public:
	void print() const;
	void sort();
	void delete_by(int const datum);
	void push_back(int datum);
	void insert_after(const int prev_id, const int datum);
	Linked_list();
private:
	Node* head;
};

void Linked_list::delete_by(int const datum){

	Node* traverse{head};
	Node* previous{nullptr};

	if(head!=nullptr){

		while(traverse!=nullptr && traverse->identifier !=datum){
			previous = traverse;
			traverse=traverse->p_next;
		}

		if(previous==nullptr){
			head =traverse->p_next;
			delete traverse;
			traverse=nullptr;
		}

		else{
			previous->p_next =traverse->p_next;
			delete traverse;
			traverse=nullptr;
		}
	}
}

void Linked_list::insert_after(const int prev_id, const int datum){

	Node * new_node{new Node{datum,nullptr}};


	if(head==nullptr){
		head =new_node;
	}

	else{
		Node* traverse{head};
		Node* previous{traverse};

		while(traverse!=nullptr && previous->identifier!=prev_id){
			previous =traverse;
			traverse = traverse->p_next;
		}

		if(previous == traverse){
			std::cout << "test" << std::endl;
			new_node->p_next =previous->p_next;
			previous->p_next = new_node;
		}

		else if(previous->identifier == prev_id){
			previous->p_next =new_node;
			new_node->p_next = traverse;
		}

		else{
			previous->p_next =new_node;
		}
	}

}

void Linked_list::print() const{

	Node* traverse{head};

	while(traverse!=nullptr){
		std::cout << traverse->identifier << std::endl;

		traverse=traverse->p_next;
	}

}

Node::Node(int id, Node* pointer){
	p_next =pointer;
	identifier=id;
}

Linked_list::Linked_list(){
	head=nullptr;
}

void Linked_list::push_back(int datum){
	head=new Node{datum,head};
}

void Linked_list::sort(){
	int size{0};
	Node* previous{nullptr};
	int temp{0};
	Node* traverse{head};


	while(traverse!=nullptr){
		++size;
		traverse=traverse->p_next;
	}
	traverse=head;

	for(int k{1}; k <size; ++k){

		for(int i{k}; i>0; --i){

			for(int l{0}; l<i ; ++l){
				previous=traverse;
				traverse=traverse->p_next;
			}

			if(previous->identifier > traverse->identifier){
				temp=traverse->identifier;
				traverse->identifier=previous->identifier;
				previous->identifier=temp;
			}
			else{
				break;
			}
		traverse=head;
		}
		traverse=head;
	}
}

int main(){

	// Linked_list ss{};

	// ss.push_back(23);
	// ss.push_back(123);
	// ss.push_back(123);
	// ss.push_back(54);
	// ss.push_back(52);
	// ss.push_back(0);
	// ss.push_back(-654);
	// ss.push_back(1);
	// ss.push_back(-432);
	// ss.push_back(43);
	// ss.push_back(-11);

	// ss.insert_after(0,12);
	// ss.print();
	// ss.delete_by(0);
	// ss.print();

	char* str{(char*)"asd asf sa sad    asdasf asf asf asfasf assf"};
	int i{0};
	

	for(int i{0}; i< 25; ++i){
		while(str[i]!=' '){
			std::cout << str[i];
			++i;
		}

		if(str[i-1]!=' ')
			std::cout << std::endl;
	

	}


}
