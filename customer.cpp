#include <iostream>
#include "food.h"
//choose_store�� main���� �ٽ� �ҰԿ�...

void Customer::make_order(void) { //�޴��� �ϳ��� �Է¹޾� array�� ����� order[]�� �־��ش�. 
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
	}
	completed_order += order_list.size();

}
void Customer::show_order(Store_menu a) {// ������ ������ �ֹ��ߴ��� �����ش�. ����� ����ִ���.??????
	cout << "Your ordered: ";
	for (int i = 0; i < order_list.size(); i++) {
		cout << a.st_menu[i-1]<<": "<<���⿡ ������<<endl;
	}
	cout << endl;
}
void Customer::alarm() {//(completed_order�� 0�� �ƴϸ�) ���� �Ϸ� �˶� �� completed_order=0
	if (completed_order == order_list.size()) {
		cout << "Your order is done. Enjoy your meal"<<endl;
		completed_order = 0;
	}
	else {
		cout<< completed_order<<"order is done. You have "<< order_list.size() -completed_order<<"more order. Please wait more" << endl;
	}
}
