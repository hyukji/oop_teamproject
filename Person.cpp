#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Login;

class Person {
	string ID; //각 사람의 ID를 string type으로 저장
	string password; //각 사람의 ID를 string type으로 저장
	int type;

public:
	Person() : ID{ "" }, password{ "" }, type{ 0 } { };
	Person(string id, string pw, int rhs) : ID{ id }, password{ pw }, type{rhs} {};

	void set_ID(string id) 
	{
		this -> ID = id;
		cout << "당신의 ID는 " << id << "입니다."; 
	}; //string을 입력받아 ID를 string type으로 저장

	string get_ID(void) 
	{
		cout << "당신 의 ID는 " << ID << "입니다.";
		return ID;
	}; //ID를 string type으로 return
	
	void set_password(string pw) 
	{
		this-> password = pw;
		cout << "당신의 PW는 " << pw << "입니다.";
	}; //string을 입력받아 password를 string type으로 저장


	string get_password(void) 
	{
		return password;
	}; //password를 string type으로 return
	
	void set_type(int input) 
	{
		this->type = input;
	}; //string을 입력받아 type를 string type으로 저장

	int get_type(void) 
	{
		return type;
	}; //type를 string type으로 return
};
