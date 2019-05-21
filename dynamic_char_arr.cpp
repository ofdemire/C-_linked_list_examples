#include <iostream>


std::size_t string_length(char* s_str){

	std::size_t size{0};

	for(int i{0}; s_str[i]!='\0'; ++i)
		++size;

	return size;
}

char *string_copy(char* s_str){

	std::size_t size = string_length(s_str);

	char* a_result{new char[size+1]};

	for(int i{0}; i <= size;++i)
		a_result[i]=s_str[i];


	return a_result;
}

int main(){

	char* kk{(char*) "asd"};

	std::cout << string_length(kk) << std::endl;

	char *ll = string_copy(kk);

	std::cout << ll << std::endl;


}