#include <iostream>

class Edit{
protected:
	char const* string;
	int size;
public:
	void print() const{
		std::cout << string << std::endl;
	}
	Edit(char const* str);
	int getSize() const {
		return size;
	}

	void length();
	char getInstance(int position) const;
	virtual void transform(Edit const &ee)=0;
};

Edit::Edit(char const* str){
	string=str;
	length();
}

void Edit::length(){
	int count{0};
	for(int i{0}; string[i]!='\0'; ++i)
		++count;

	size=count;
}

char Edit::getInstance(int position) const{
	return string[position];
}

class Push_back: public Edit{
public:
	virtual void transform(Edit const &ee);
	Push_back(char const* str):Edit{str}{

	}

};

void Push_back::transform(Edit const &ee){
	char* a_result = new char[size+ee.getSize()];
	int k=0;

	for(int i{0}; i <size;++i,++k)
		a_result[k]=string[i];

	for(int i{0};i <=ee.getSize(); ++i,++k)
		a_result[k]=ee.getInstance(i);


	string=a_result;

	size += (ee.getSize());
	a_result=nullptr;
}

class Push_front: public Edit{
public:
	virtual void transform(Edit const &ee);
	Push_front(char const* str):Edit{str}{

	}
};

void Push_front::transform(Edit const &ee){
	char *a_result=new char[size+ ee.getSize()];

	int k{0};

	for(int i{0}; i < ee.getSize(); ++i,++k)
		a_result[k] = ee.getInstance(i);

	for(int i{0}; i<=size;++i,++k)
		a_result[k]=string[i];

	string=a_result;

	size += ee.getSize();
	a_result=nullptr;
}

int main(){

	char const* str="asd";
	char const* aa="aa";
	char const* bb="bb";
	char const* cc="cc";
	char const* dd="dd";
	char const* kk="kk";

	char const* ekle="ilkson";

	Push_back ptr{ekle};

	Edit *arr[6]={new Push_back{str}, new Push_front{aa}, new Push_front{bb},new Push_back{cc}, new Push_front{dd}, new Push_back{kk}};

	for(int i{0}; i < 6;++i){
		arr[i]->transform(ptr);
	}

	for(int i{0}; i<6;++i)
		arr[i]->print();



}