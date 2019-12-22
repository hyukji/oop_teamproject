#pragma once
#include "food.h"

#include <string>
#include <iostream>
using namespace std;

	//생성자
	Boss::Boss(string name, string ph, string pw, Login* login) : Person(name, pw, 0, login) {
		this->store_name = name;
		this->store_PH = ph;
	}

	void Boss::set_store(void)
	{
		cout << "원하시는 가게의 이름을 입력하세요\n";

		string input_name;
		cin >> input_name;
		this->store_name = input_name;
	}; //가게 이름을 cin으로 string type으로 받아서 store_치name에 넣어준다. 

	void Boss::set_PH(void) {
		string in;
		cout << "가게의 전화번호를입력하세요" << endl;
		cin >> in;
		this->store_PH = in;
		; //가게 전화번호를 cin으로 string type으로 받아서 store_PH에 넣어준다.
	}
	void Boss::set_sm(Store_menu* rsm)
	{
		this->sm = rsm;
	}

	void Boss::set_ss(Store_status* rss)
	{
		ss = rss;
	}

