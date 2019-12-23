#include <iostream>
#include "food.h"
//choose_store는 main으로 다시 할게용...

void Customer::make_order(void) { //메뉴를 하나씩 입력받아 array로 만들어 order[]에 넣어준다. 
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
void Customer::show_order(Store_menu a) {// 본인이 무엇을 주문했는지 보여준다. 사람이 몇명있는지.??????
	cout << "Your ordered: ";
	for (int i = 0; i < order_list.size(); i++) {
		cout << a.st_menu[i-1]<<": "<<여기에 무엇을<<endl;
	}
	cout << endl;
}
void Customer::alarm() {//(completed_order가 0이 아니면) 음식 완료 알람 및 completed_order=0
	if (completed_order == order_list.size()) {
		cout << "Your order is done. Enjoy your meal"<<endl;
		completed_order = 0;
	}
	else {
		cout<< completed_order<<"order is done. You have "<< order_list.size() -completed_order<<"more order. Please wait more" << endl;
	}
}
