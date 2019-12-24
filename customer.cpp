#include <iostream>
#include "food.h"

void Customer::make_order(Store_status ss) { //�޴��� �ϳ��� �Է¹޾� array�� ����� order[]�� �־��ش�. 
	cout << "Select Menu!" << endl;
	while (true) {
		int select_menu;
		cin >> select_menu;
		if (select_menu == 0) {
			cout << "Your order is ready. Please wait.I will call you when the food is ready" << endl;
			break;
		}
		order_list.push_back(select_menu);
		cout << "Select Menu! if you want to end order, press 0";
		my_order = ss.order_num;
	}
}

void Customer::show_order(Store_menu m, Store_status ss) {// ������ ������ �ֹ��ߴ��� �����ش�. ����� ����ִ���.??????
	cout << "Your ordered: ";
	for (int i = 0; i < order_list.size(); i++) {
		cout << m.st_menu[i - 1] << " " << endl;
	}
	int a = 0;
	for (auto it = ss.m_Cuisine.begin(); it != ss.m_Cuisine.end(); it++) {
		if (it->second->complete == 0)
			a += 1;
		if (it->first == my_order) { break; };
	}
	cout << "��� ���� ó������ ���� �ֹ���" << a << "�� �ֽ��ϴ�. ";
}


void Customer::alarm() {//(completed_order�� 0�� �ƴϸ�) ���� �Ϸ� �˶� �� completed_order=0
	if (completed_order == order_list.size()) {
		cout << "Your order is done. Enjoy your meal!" << endl;
		completed_order = 0;
	}
	else {
		cout << completed_order << "order is done. You have " << order_list.size() - completed_order << "more order. Please wait more!" << endl;
	}
}


