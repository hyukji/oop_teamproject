#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Person {
	string ID; //�� ����� ID�� string type���� ����
	string password; //�� ����� ID�� string type���� ����
	int type;
public:
	Person() {
		this -> ID = "";
		this-> password = "";
		this-> type = 0;
	};
	void set_ID(string id) 
	{
		this -> ID = id;
		cout << "����� ID�� " << id << "�Դϴ�."; 
	}; //string�� �Է¹޾� ID�� string type���� ����

	string get_ID(void) 
	{
		cout << "����� ID�� " << ID << "�Դϴ�.";
		return ID;
	}; //ID�� string type���� return
	
	void set_password(string pw) 
	{
		this-> password = pw;
		cout << "����� PW�� " << pw << "�Դϴ�.";
	}; //string�� �Է¹޾� password�� string type���� ����


	string get_password(void) 
	{
		return password;
	}; //password�� string type���� return
	
	void set_type(int input) 
	{
		this->type = input;
	}; //string�� �Է¹޾� type�� string type���� ����

	int get_type(void) 
	{
		return type;
	}; //type�� string type���� return
};
