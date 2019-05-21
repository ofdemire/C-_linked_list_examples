#include <iostream>

struct array_t{
	std::size_t capacity;
	int *data;
};

array_t* create_str(int array[], int size){
	array_t* new_str=new array_t{};

	new_str->data = new int[size]{};

	for(int i{0}; i <size;++i)
		new_str->data[i]=array[i]; 

	new_str->capacity=size;

	return new_str;
}


int string_length(char* str){
	int length{0};

	for(int i{0}; str[i]!='\0'; ++i)
		++length;

	return length;
}

void add_char(char *&str, std::size_t position, char ch){

	char * new_string{new char[string_length(str)+2]};

	int k{0};

	for(int i{0}; i<position;++i,++k)
		new_string[k] = str[i];



	new_string[position] =ch;
	++k;



	for(std::size_t i{position}; i <=string_length(str); ++i,++k){
		new_string[k]=str[i];
	}



	delete[] str;
	str = new_string;


			std::cout << str << std::endl;
	new_string =nullptr;
}

char* copy(char* ss){

	char* a_result{new char[string_length(ss)+1]};

	for(int i{0}; i<=string_length(ss); ++i)
		a_result[i]=ss[i];

	return a_result;
}


int main(){

	char* str{(char*)"Hello world!"};

	std::cout << str << std::endl;



	char *kk{copy(str)};

	add_char(kk,string_length(kk),'!');

	add_char(kk,string_length(kk),'!');

	std::cout << kk << std::endl;




}

