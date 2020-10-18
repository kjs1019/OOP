#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class AnyString {
	std::string anyString;

public:
	AnyString(const std::string& anyString) : anyString(anyString) {}
	std::string getAnyString() {
		return "Stored String :: " + anyString;
	}
	friend ostream& operator<<(ostream&, const AnyString&);
};

ostream& operator<<(ostream& os, const AnyString& str) {
	os << str.anyString;
	return os;
}
int main() {
	AnyString a("Hello, this is operator overloading test!!!");
	cout << a << std::endl;

	return 0;
}
