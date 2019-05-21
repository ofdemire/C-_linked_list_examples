#include <iostream>
#include <string>

class String{
private:
	char const* str;
	int length;
	int capacity;
public:
	int getlength() const{
		return length;
	}

	char const* get_str() const{
		return str;
	}

	int getcap() const{
		return capacity;
	}
	String(char const * ss);
	void sorted_strings(char const * arr[],int size);
	void setlength();
};

String::String(char const* ss){
	str=ss;
	setlength();
}

void String::setlength(){
	int count{0};

	for(int i{0}; str[i]!='\0'; ++i)
		++count;

	length=count;
	capacity=count+1;
}

int size_str( char const * ss){

	int count{0};
	for(int i{0}; ss[i]!='\0';++i)
		++count;

	return count;
}

void String::sorted_strings(char const* arr[], int size){

	int SIZE{0};

	for(int i{0}; i< size; ++i)
		SIZE +=size_str(arr[i]);

	char *a_result = new char[SIZE+1];
	char const* temp{};

	for(int k{1}; k < size; ++k){
		for(int i{k}; i >0;--i){

			if(arr[i] < arr[i-1]){
				temp=arr[i];
				arr[i]=arr[i-1];
				arr[i-1]=temp;
			}

			else{
				break;
			}
		}
	}


	int k{0};

	for(int i{0}; i<length;++i,++k)
		a_result[k]=str[i];


	for(int i{0}; i < size; ++i){
		for(int m{0}; m < size_str(arr[i]); ++m,++k){
			std::cout << arr[i][m] << std::endl;
			a_result[k]=arr[i][m];
		}

		
	}

	std::cout << a_result << std::endl;


	a_result[k]='\0';
	str=a_result;
	a_result=nullptr;
	length=SIZE;
	capacity=SIZE+1;
}


int main(){

	char const * str{"omer"};

	String kk{str};

	char const* arr[10]{"sad","safasf","wqeqwe","we","sad","231","kop","wqe","sad","sad"};

	kk.sorted_strings(arr,10);

	std::cout << kk.getlength() << " " << kk.getcap() << std::endl;

	std::cout << kk.get_str() << std::endl;


}