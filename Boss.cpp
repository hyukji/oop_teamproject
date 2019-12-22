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

	void store_open(void) {
		if (store_open == false)
			this -> store_open = true;
		bool poss = checking();
		if (poss == true) {
			this->store_open = false;
		}
		else {
			cout << "조리가 완료되지 않은 항목이 있어 가게문을 닫을 수 없습니다." << endl;
		}
	}; //open이 false면 true로, true면 false로 바꿔준다.-true에서 false로 갈 때는 cooking_over을 실해해서 true일때만 닫을 수 있다. 
	bool checking(void) {
		for (bool order_stat : order_list)
			if (order_stat == false) {
				cout << "완료되지 않은 조리가 존재합니다." << endl;
				break;
			}
		cout << "모두 조리가 완료된 상태입니다." << endl;
		return true;
	}; //order_list의 주문완료 여부를 확인하여 모두 true일때만 true를 return, 하나라도 주문 남아있으면 false return
	//지금 order_list의 원소중 몇번째 항목이 조리완료인지 몰라 일단은 저렇게 표현해뒀습니다. 담당하신분 
};
