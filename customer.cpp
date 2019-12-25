#include <iostream>
#include "food.h"



Customer::Customer(int type, string id, string pw, Login* login) :Person(id, pw, 2, login)
{

};

Customer::Customer(string id, string pw, Login* login) : Person(id, pw, 1, login) {

};
void Customer::make_order(Store_status ss) { //메뉴를 하나씩 입력받아 array로 만들어 order[]에 넣어준다. 
	cout << "Select Menu! If you want nothing, press 0" << endl;
	order_list.clear();

	while (true) {
		int select_menu;
		cin >> select_menu;
		if (select_menu == 0) {
<<<<<<< HEAD
			if (order_list.size() == 0) { break; }
=======
>>>>>>> 608d75b11d7ed7f9636889a980146692f05b4513
			cout << "Your order is ready. Please wait.I will call you when the food is ready\n" << endl;
			break;
		}
		order_list.push_back(select_menu);
		cout << "Select Menu! if you want to end order, press 0\n";
		my_order = ss.order_num;
	}
<<<<<<< HEAD
	orders += order_list.size();
=======
>>>>>>> 608d75b11d7ed7f9636889a980146692f05b4513
}

void Customer::show_order(Store_menu m, Store_status ss) {// 본인이 무엇을 주문했는지 보여준다. 사람이 몇명있는지.??????
	cout << "Your ordered: ";
	for (int i = 0; i < order_list.size(); i++) {
		int a = order_list[i] - 1;
		string cus_me = store->sm->get_menu(a);
<<<<<<< HEAD
		cout << cus_me << " ";
		string b[2];
		b[0] = cus_me;
		b[1] = "False";
		vector<string> orvector;
		for (int j = 0; j < 2; j++) {
			orvector.push_back(b[j]);
		}
		order_check.push_back(orvector);
=======

		cout << cus_me << " ";
>>>>>>> 608d75b11d7ed7f9636889a980146692f05b4513
	}
	cout << endl;
	int a = 0;
	for (auto it = ss.m_Cuisine.begin(); it != ss.m_Cuisine.end(); it++) {
		if (it->first == my_order) { break; };
		if (it->second->complete == 0)
			a += 1;
		
	}
<<<<<<< HEAD
	if (a == 0 || a == 1) {
		cout << "There is " << a << " order before your order" << endl;
	}
	else { cout << "There are " << a << " orders before your order"; }
=======
	cout << "당신 전에 처리되지 않은 주문이" << a-1 << "개 있습니다.\n";
>>>>>>> 608d75b11d7ed7f9636889a980146692f05b4513
}

void Customer::check_menu(void) {
	cout.width(20);
	cout << "Menu";
	cout.width(20);
	cout << "Finished";
	cout << endl;
	for (int i = 0; i < order_check.size(); i++) {
		for (int j = 0; j < 2; j++) {
			cout.width(20);
			cout << order_check[i][j];
		}
		cout << endl;
	}
}
void Customer::alarm(void) {//(completed_order가 0이 아니면) 음식 완료 알람 및 completed_order=0
	if (end_list.size()!=0) {
		
		for (int i = 0; i < end_list.size(); i++) {
			cout<<end_list[i]<<" ";
			for (int j = 0; j < order_check.size(); j++) {
				if (order_check[j][0] == end_list[i]) {
					order_check[j][1] = "True";
					break;
				}
			}
		}
		orders -= end_list.size();
		end_list.clear();
		cout << "is done. ";

		
		if (orders == 0) {
			cout << "Your order is done. Enjoy your meal!" << endl;

		}
		else {
			cout << "You have " << orders << "more orders. Please wait more" << endl;
		}
	}
}

