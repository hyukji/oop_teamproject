#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Person.cpp"
using namespace std;

class Boss : public Person {
	string store_name; //가게 이름을 string type으로 저장
	string store_PH; //가게 전화번호를 string type으로 저장
	bool open = true; //open 상태를 bool type으로. 초기값은 열린 상태로
public:
	void set_store(void) 
	{
		string in;
		cout << "가게의 이름을 입력하세요" << endl;
		cin >> in;
		this->store_name = in;
	}; //가게 이름을 cin으로 string type으로 받아서 store_치name에 넣어준다. 

	void set_PH(void) {
		string in;
		cout << "가게의 전화번호를입력하세요" << endl;
		cin >> in;
		this->store_PH = in;
	}; //가게 전화번호를 cin으로 string type으로 받아서 store_PH에 넣어준다.
};
