#include <iostream>
#include "food.h"
//choose_store�� main���� �ٽ� �ҰԿ�...
/*
void Customer::choose_store(void) {//���Ը� int type���� �����ؼ� �ش��ϴ� ���Ը� store�� �Ҵ����ش�.
	cout << "Select restaurant!" << endl;
	cout << "1. ��ū ���ö�" << endl;
	cout << "2. ���õ��" << endl;
	cout << "3. �ֵ�����" << endl;
	int stores;
	while (true) {
		cin >> stores;
		if (stores == 1) {
			store = the_bigger;
			break;
		}
		if (stores == 2) {
			store =kimchun;
			break;
		}
		if (stores == 3) {
			store = hotdog;
			break;
		}
		else {
			cout<<"Wrong restaurent. Select restarant again";
		}
	}
}
void Customer::make_order(void) { //�޴��� �ϳ��� �Է¹޾� array�� ����� order[]�� �־��ش�. 
	cout << "Select Menu!" << endl;
	store->show_menu();
	while (true) {
		int select_menu;
		cin >> select_menu;
		if (select_menu == 0) {
			cout << "Your order is ready. Please wait.I will call you when the food is ready" << endl;
			break;
		}
		order_list->push_back(select_menu);
		cout << "Select Menu! if you want to end order, press 0";
	}
	completed_order += order_list->size();

}
void Customer::show_order(Store_menu*) {// ������ ������ �ֹ��ߴ��� �����ش�. ����� ����ִ���.
	cout << "Your ordered: ";
	for (int i = 0; i < order_list->size(); i++) {
		cout << store->menu[i][1]<<" ";
	}
	cout << endl;
}
void Customer::alarm() {//(completed_order�� 0�� �ƴϸ�) ���� �Ϸ� �˶� �� completed_order=0
	if (completed_order == order_list->size()) {
		cout << "Your order is done. Enjoy your meal"<<endl;
		completed_order = 0;
	}
	else {
		cout<< completed_order<<"order is done. You have "<< order_list->size() -completed_order<<"more order. Please wait more" << endl;
	}
}
*/
