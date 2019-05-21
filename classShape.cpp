#include <iostream>



class Student {
protected:
	std::string name;
	std::string idNumber;
	int yearAdmitted;

public:
	Student(){
		name="\0";
		idNumber="\0";
		yearAdmitted=0;
	}


	virtual int getRemainingHours() const=0;
};



class Derived:public Student{
public:

	virtual int getRemainingHours() const;
	Derived():Student(){

	}


};

int Derived::getRemainingHours() const{
	std::cout << "derived" << std::endl;
}



int main(){

	Student *ss=new Derived{};

	Derived dd{};
	dd.getRemainingHours();
	ss->getRemainingHours();
}