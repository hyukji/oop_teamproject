#include "food.h"
#include <iostream>
#include <iomanip>
#include <map>

class Store_menu;
class Customer;
class Store_status;
class Cuisine;

///////////////////////////////////////////////////////////

int Store_status::take_order(Customer& cus)
{
	if (cus.order_list.size() == 0) { cout << "�ֹ��� ��� �Ǿ����ϴ�.\n" << endl; return 0; }
	for (int i = 0; i < cus.order_list.size(); i++) {
		int a = cus.order_list[i]-1;
		string cus_me = cus.store->sm->get_menu(a);

		string cus_id = cus.Person::get_ID();
		Cuisine* cu = new Cuisine(cus, cus_me, 0); 
		
		m_Cuisine.insert(pair<int, Cuisine*>(order_num, cu));

		order_num += 1;
		cout <<  cus_me << " �ֹ��� �Ϸ� �Ǿ����ϴ�.\n" << endl;
	}
	return 1;
}

void Store_status::show_list(void)
{
	cout << " �ֹ� ��� " << endl;
	cout << setw(10) << "��ȣ" << setw(20) << "�ֹ���" << setw(20) << "�޴�" << setw(20) << endl;
	for (auto it = m_Cuisine.begin(); it != m_Cuisine.end(); it++) {
		if (it->second->get_order_complete() == 0) {
			cout << setw(10) << it->first << setw(20) << it->second->get_order_cus().get_ID();
			cout << setw(20) << it->second->get_order_menu() << endl;
		}
	}
}

void Store_status::cooking_over(int n)
{
	m_Cuisine.find(n)->second->change_complete();
	//m_Cuisine.find(n)->second->get_order_cus().end_list.push_back(a);
	string a = m_Cuisine.find(n)->second->get_order_menu(); //�̼����� �߰��Ѱ���
	m_Cuisine.find(n)->second->get_order_cus().end_list.push_back(a); //�̼����� �߰��Ѱ���
}

///////////////////////////////////////////////////////////



Customer& Cuisine::get_order_cus(void)
{
	return order_cus;
}

string Cuisine::get_order_menu(void)
{
	return order_menu;
}

int Cuisine::get_order_complete(void)
{
	return complete;
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
