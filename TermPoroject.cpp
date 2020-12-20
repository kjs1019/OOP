#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAX_BYTE 75
#define MAX_LINE 20

using namespace std;
std::vector<std::string> vt = {};
int head = 0;
void printtxt(std::vector<string> printvector) {		// 파일을 출력하는 함수
	int result = 0;
	int linecount = 1;
	cout << linecount << "| ";

	for (int i = 0; linecount <= MAX_LINE; i++) {
		
		result += printvector[i].size();
		result++;

		if(result < MAX_BYTE){
			cout << printvector[i] << " ";
		}
		else {
			linecount++;
			if (linecount <= 20) {
				cout << "\n" << linecount << "| ";
			}
			result = 0;
		}
	}
	cout << "\n---------------------------------------------------------------------------------\n";
	cout << "n:다음페이지, p:이전페이지 i:삽입, d:삭제, c:변경, s:찾기, t:저장후종료\n";
	cout << "---------------------------------------------------------------------------------\n";
	cout << "(콘솔메시지)\n";
	cout << "---------------------------------------------------------------------------------\n";
	cout << "입력: \n";

}
void inputtext(int line, int numword, string text) {	// 텍스트 추가 함수
	int linecount = 1;
	int result = 0;
	for (int i = 0; i < vt.size(); i++) {
		result += vt[i].size();
		result++;

		if (result > MAX_BYTE) {
			linecount++;
		}
		if (line == linecount) {
			vt.insert(vt.begin() + i + numword, text);
			break;
		}

	}
};

void deletetext(int line, int numword) {
	int linecount = 1;
	int result = 0;
	for (int i = 0; i < vt.size(); i++) {
		result += vt[i].size();
		result++;

		if (result > MAX_BYTE) {
			linecount++;
		}
		if (line == linecount) {
			vt.erase(vt.begin() + i + numword-1);
			break;
		}

	}
}

void changetext(string testtext,string text) {		//텍스트 변경 함수
	for (int i = 0; i < vt.size(); i++) {
		if (vt[i] == testtext) {
			vt.erase(vt.begin()+i);
			vt.insert(vt.begin()+i, text);
		}
	}
}

void nextpage() {

}

int main() {
	std::string str;
	std::ifstream fin("test.txt");
	

	while (std::getline(fin, str,' '))
	{
		vt.push_back(str);
	}

	printtxt(vt);
	//inputtext(2, 10, "hello");
	//deletetext(2, 1);
	changetext("The", "hello");
	printtxt(vt);

}