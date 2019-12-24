#include <iostream>
#include "food.h"



Customer::Customer(int type, string id, string pw, Login* login) :Person(id, pw, 2, login)
{

};

Customer::Customer(string id, string pw, Login* login) : Person(id, pw, 1, login) {

};
void Customer::make_order(Store_status ss) { //�޴��� �ϳ��� �Է¹޾� array�� ����� order[]�� �־��ش�. 
	cout << "Select Menu!" << endl;
	while (true) {
		int select_menu;
		cin >> select_menu;
		if (select_menu == 0) {
			cout << "Your order is ready. Please wait.I will call you when the food is ready\n" << endl;
			break;
		}
		order_list.push_back(select_menu);
		cout << "Select Menu! if you want to end order, press 0\n";
		my_order = ss.order_num;
	}
}

void Customer::show_order(Store_menu m, Store_status ss) {// ������ ������ �ֹ��ߴ��� �����ش�. ����� ����ִ���.??????
	cout << "Your ordered: ";
	for (int i = 0; i < order_list.size(); i++) {
		int a = order_list[i] - 1;
		string cus_me = store->sm->get_menu(a);

		cout << cus_me << " ";
	}
	cout << endl;
	int a = 0;
	for (auto it = ss.m_Cuisine.begin(); it != ss.m_Cuisine.end(); it++) {
		if (it->second->complete == 0)
			a += 1;
		if (it->first == my_order) { break; };
	}
	cout << "��� ���� ó������ ���� �ֹ���" << a-1 << "�� �ֽ��ϴ�.\n";
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


