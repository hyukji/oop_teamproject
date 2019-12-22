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
		Cuisine* cu = new Cuisine(cus_id, cus_me, 0);  //�̰� new�� �����Ҵ��ص� �ǳ�???

		m_Cuisine.insert(pair<int, Cuisine*>(order_num, cu));
		order_num += 1;
	}
}

void Store_status::show_list(void)
{
	cout << " �ֹ� ��� " << endl;
	cout << setw(10) << "��ȣ" << setw(10) << "�ֹ���" << setw(10) << "�޴�" << setw(10);
	for (auto it = m_Cuisine.begin(); it != m_Cuisine.end(); it++) {
		cout << setw(10) << it->first << setw(10) << it->second->get_order_cus();
		cout << setw(10) << it->second->get_order_menu() << endl;
	}
}

void Store_status::cooking_over(int n)
{
	m_Cuisine.find(n)->second->change_complete();
	cout << n << "��° �ֹ��� �Ϸ� �Ǿ����ϴ�." << endl;
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
