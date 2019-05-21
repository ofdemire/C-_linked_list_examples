#include <iostream>

void reserver(char *str){

	int size{0};
	char ch{};

	for(int i{0}; str[i]!='\0';++i)
		++size;


	for(int i{0};  i <size/2; ++i){
		ch = str[i];
		str[i] =str[size-1-i];
		str[size-1-i] =ch;
	}
}


char* copy(char *ss){
	int size{0};



	for(int i{0}; ss[i]!='\0';++i)
		++size;

	char* a_result{new char[size+1]};

	for(int i{0}; i <=size ; ++i){
		a_result[i]=ss[i];

	}

	return a_result;

}

char** resserve_pointer(char* str){
	int size{0};

	for(int i{0}; str[i]!='\0'; ++i)
		++size;

	char** a_result{new char*[size+1]};

	for(int i{0}; i <size; ++i)
		a_result[i] = &(str[size-1-i]);


	return a_result;
}


int main(){


char name[]= "J";

std::cout  << sizeof(name)/sizeof(name[0]) << std::endl;

	
}
