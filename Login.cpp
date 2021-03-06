#pragma once
#include "food.h"

#include <string>
#include <iostream>
#include <map>
#include <Algorithm>

using namespace std;

void Login::check_user(Person* user) {
	string a = user->get_ID();
	if (m.count(a) == 0) {
		m.insert(pair<string, Person*>(a, user));

	}
	else {
		m.erase(a);
		m.insert(pair<string, Person*>(a, user));
		//유저의 비밀번호나 정보가 변경된 경우 기존의 map에서의 할당을 해제하고 새로 할당하는 역할을 담당합니다.
		// 계정을 생성하고 map으로 모두 관리하므로 객체를 생성할 때마다 위 함수를 사용하면 맵을 유저 현황과 동일하게 관리할 수 있을것이라 생각됩니다.
	}
}

Person& Login::check_ID()
{
	string input_id;
	string input_pw;
	while (1) {
		cout << "input your ID\n";
		cin >> input_id;
		map<string, Person*>::iterator itr = m.find(input_id);
		if (itr == m.end()) {
			cout << "There is no ID " << input_id << endl;
		}
		else {
			cout << "input your PW\n";
			cin >> input_pw;

			if (m[input_id]->get_password() == input_pw) {
				cout << endl;
				return *m[input_id];
			}
			else {
				cout << "it's wrong PW. " << "Try again\n" << endl;
				cout << endl;
			}
		}
	}
	cout << endl;
}

void Login::Store_name_out()
{
	int num = 1;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second->get_type() != 0) { continue; }
		cout << num << ". " << ((Boss*)(it->second))->get_name() << endl;
		num++;
	}
}


void Login::sign_up() {
	
	string id;
	string pw;

	cout << "Enter Your ID\n";
	cin >> id;
	cout << "Enter Your Password\n";
	cin >> pw;
	Customer* c = new Customer(id, pw, this);

	cout << "Your Account(customer) is created!\n";
	cout << endl;
};
//ID에 맞는 객체 password와 맞춰보고 맞으면 객체 return
