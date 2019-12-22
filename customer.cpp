#include <iostream>
#include "food.h"
//choose_store는 main으로 다시 할게용...
/*
void Customer::choose_store(void) {//가게를 int type으로 선택해서 해당하는 가게를 store에 할당해준다.
	cout << "Select restaurant!" << endl;
	cout << "1. 더큰 도시락" << endl;
	cout << "2. 김밥천국" << endl;
	cout << "3. 핫도그집" << endl;
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
void Customer::make_order(void) { //메뉴를 하나씩 입력받아 array로 만들어 order[]에 넣어준다. 
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
void Customer::show_order(Store_menu*) {// 본인이 무엇을 주문했는지 보여준다. 사람이 몇명있는지.
	cout << "Your ordered: ";
	for (int i = 0; i < order_list->size(); i++) {
		cout << store->menu[i][1]<<" ";
	}
	cout << endl;
}
void Customer::alarm() {//(completed_order가 0이 아니면) 음식 완료 알람 및 completed_order=0
	if (completed_order == order_list->size()) {
		cout << "Your order is done. Enjoy your meal"<<endl;
		completed_order = 0;
	}
	else {
		cout<< completed_order<<"order is done. You have "<< order_list->size() -completed_order<<"more order. Please wait more" << endl;
	}
}
*/
