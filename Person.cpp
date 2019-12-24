#pragma once
#include "food.h"

#include <string>
#include <iostream>
using namespace std;

//Person::Person() : ID{ "" }, password{ "" }, type{ 0 } { };
Person::Person(string id, string pw, int rhs, Login* login) : ID{ id }, password{ pw }, type{rhs} {
	login->check_user(this);

};

	void Person::set_ID(string id)
	{
		this -> ID = id;
		cout << "당신의 ID는 " << id << "입니다."; 
	}; //string을 입력받아 ID를 string type으로 저장

	string Person::get_ID(void)
	{
		cout << "your ID is " << ID << ".\n";
		return ID;
	}; //ID를 string type으로 return
	
	void Person::set_password(string pw)
	{
		this-> password = pw;
		cout << "your PW is " << pw << ".\n";
	}; //string을 입력받아 password를 string type으로 저장

	string Person::get_password(void)
	{
		return password;
	}; //password를 string type으로 return
	
	void Person::set_type(int input)
	{
		this->type = input;
	}; //string을 입력받아 type를 string type으로 저장

	int Person::get_type(void)
	{
		return type;
	}; //type를 string type으로 return
