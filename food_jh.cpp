#include "food.h"
#include <iostream>
#include <iomanip>
#include <map>

class Store_menu;
class Customer;
class Store_status;
class Cuisine;

///////////////////////////////////////////////////////////

void Store_status::take_order(Customer& cus)
{
	for (int i = 0; i < cus.order_list.size(); i++) {
		int a = cus.order_list[cus.order_list.size()];
		cus.order_list.pop_back();
		string cus_me = cus.store->sm->get_menu(a);
		string cus_id = cus.Person::get_ID();
		Cuisine* cu = new Cuisine(cus_id, cus_me, 0);  //이거 new로 동적할당해도 되나???

		m_Cuisine.insert(pair<int, Cuisine*>(order_num, cu));
		order_num += 1;
	}
}

void Store_status::show_list(void)
{
	cout << " 주문 명단 " << endl;
	cout << setw(10) << "번호" << setw(10) << "주문자" << setw(10) << "메뉴" << setw(10);
	for (auto it = m_Cuisine.begin(); it != m_Cuisine.end(); it++) {
		cout << setw(10) << it->first << setw(10) << it->second->get_order_cus();
		cout << setw(10) << it->second->get_order_menu() << endl;
	}
}

void Store_status::cooking_over(int n)
{
	m_Cuisine.find(n)->second->change_complete();
	cout << n << "번째 주문이 완료 되었습니다." << endl;
}

///////////////////////////////////////////////////////////



string Cuisine::get_order_cus(void)
{
	return order_cus;
}

string Cuisine::get_order_menu(void)
{
	return order_menu;
}

void Cuisine::change_complete(void)
{
	complete = 1;
}

/////////////////////////////////////////////////////////////
string Store_menu::get_menu(int n)
{
	return st_menu[n];
}
