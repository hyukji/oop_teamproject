#include <iostream>
#include "food.h"

void Customer::make_order(Store_status ss) { //메뉴를 하나씩 입력받아 array로 만들어 order[]에 넣어준다. 
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

void Customer::show_order(Store_menu m, Store_status ss) {// 본인이 무엇을 주문했는지 보여준다. 사람이 몇명있는지.??????
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
	cout << "당신 전에 처리되지 않은 주문이" << a << "개 있습니다. ";
}


void Customer::alarm() {//(completed_order가 0이 아니면) 음식 완료 알람 및 completed_order=0
	if (completed_order == order_list.size()) {
		cout << "Your order is done. Enjoy your meal!" << endl;
		completed_order = 0;
	}
	else {
		cout << completed_order << "order is done. You have " << order_list.size() - completed_order << "more order. Please wait more!" << endl;
	}
}


