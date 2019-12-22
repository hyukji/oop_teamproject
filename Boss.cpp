#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Person.cpp"
using namespace std;

class Boss : public Person {
	string store_name; //���� �̸��� string type���� ����
	string store_PH; //���� ��ȭ��ȣ�� string type���� ����
	bool open = true; //open ���¸� bool type����. �ʱⰪ�� ���� ���·�
public:
	void set_store(void) 
	{
		string in;
		cout << "������ �̸��� �Է��ϼ���" << endl;
		cin >> in;
		this->store_name = in;
	}; //���� �̸��� cin���� string type���� �޾Ƽ� store_ġname�� �־��ش�. 

	void set_PH(void) {
		string in;
		cout << "������ ��ȭ��ȣ���Է��ϼ���" << endl;
		cin >> in;
		this->store_PH = in;
	}; //���� ��ȭ��ȣ�� cin���� string type���� �޾Ƽ� store_PH�� �־��ش�.

	void store_open(void) {
		if (store_open == false)
			this -> store_open = true;
		bool poss = checking();
		if (poss == true) {
			this->store_open = false;
		}
		else {
			cout << "������ �Ϸ���� ���� �׸��� �־� ���Թ��� ���� �� �����ϴ�." << endl;
		}
	}; //open�� false�� true��, true�� false�� �ٲ��ش�.-true���� false�� �� ���� cooking_over�� �����ؼ� true�϶��� ���� �� �ִ�. 
	bool checking(void) {
		for (bool order_stat : order_list)
			if (order_stat == false) {
				cout << "�Ϸ���� ���� ������ �����մϴ�." << endl;
				break;
			}
		cout << "��� ������ �Ϸ�� �����Դϴ�." << endl;
		return true;
	}; //order_list�� �ֹ��Ϸ� ���θ� Ȯ���Ͽ� ��� true�϶��� true�� return, �ϳ��� �ֹ� ���������� false return
};
