#include <iostream>
#include <stdexcept>
using namespace std;

int main(){
	int c;
	std::cin >> c;
	try{
		if(c<10)
		 throw std::out_of_range("Invalid Input!!");
	}
	catch(std::out_of_range& e){
		std::cout << "Exception : " << e.what() <<std::endl;
	}
}

