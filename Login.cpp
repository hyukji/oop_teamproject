#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Person.cpp"
#include <Algorithm>
using namespace std;
class Person;

class Login {
private:
	map<string, Person&> m;
	
public:
	void check_user(const Person& user){
		string a = user.get_ID;
		if (m.count(a) == 0) {
			m.insert(pair<string, Person>(a,user));
		}// ������ map�� ��ϵǾ����� ���� ��� �߰����ݴϴ�.
		else {
			map<string, Person&>::iterator index=m.begin() ;
			while ((index = find(index, m.end(),a)) != m.end())
				m.erase(index++);
			m.insert(pair<string, Person>(a, user));
			//������ ��й�ȣ�� ������ ����� ��� ������ map������ �Ҵ��� �����ϰ� ���� �Ҵ��ϴ� ������ ����մϴ�.
			// ������ �����ϰ� map���� ��� �����ϹǷ� ��ü�� ������ ������ �� �Լ��� ����ϸ� ���� ���� ��Ȳ�� �����ϰ� ������ �� �������̶� �����˴ϴ�.
		}
	}
	Person& check_ID() 
	{
		string input_id;
		string input_pw;
		
		cout <<  "���̵� �Է��ϼ���" << endl;
		cin >> input_id;
		map<string, Person&>::iterator itr=m.find(input_id);
		if (itr == m.end()) {
			cout << "�������� �ʴ� ���̵� �Դϴ�." << endl;
		}
		else {
			cout << "��й�ȣ�� �Է��ϼ���" << endl;
			cin >> input_pw;
			if (m[input_id].get_password == input_pw) {
				return m[input_id];
			}
			else {
				cout << "��й�ȣ�� Ʋ���ϴ�. �ٽ� Ȯ�����ּ���" << endl;
			}
		}
	}; //ID�� �´� ��ü password�� ���纸�� ������ ��ü return
};