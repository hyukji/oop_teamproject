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
		}// 유저가 map에 등록되어있지 않은 경우 추가해줍니다.
		else {
			map<string, Person&>::iterator index=m.begin() ;
			while ((index = find(index, m.end(),a)) != m.end())
				m.erase(index++);
			m.insert(pair<string, Person>(a, user));
			//유저의 비밀번호나 정보가 변경된 경우 기존의 map에서의 할당을 해제하고 새로 할당하는 역할을 담당합니다.
			// 계정을 생성하고 map으로 모두 관리하므로 객체를 생성할 때마다 위 함수를 사용하면 맵을 유저 현황과 동일하게 관리할 수 있을것이라 생각됩니다.
		}
	}
	Person& check_ID() 
	{
		string input_id;
		string input_pw;
		
		cout <<  "아이디를 입력하세요" << endl;
		cin >> input_id;
		map<string, Person&>::iterator itr=m.find(input_id);
		if (itr == m.end()) {
			cout << "존재하지 않는 아이디 입니다." << endl;
		}
		else {
			cout << "비밀번호를 입력하세요" << endl;
			cin >> input_pw;
			if (m[input_id].get_password == input_pw) {
				return m[input_id];
			}
			else {
				cout << "비밀번호가 틀립니다. 다시 확인해주세요" << endl;
			}
		}
	}; //ID에 맞는 객체 password와 맞춰보고 맞으면 객체 return
	
	// 완성된건지 모르겠는데 일단 생각나는대로 만들었습니다. feedback 환영! -12/23 김태윤
};
