#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Store_menu;


class Login {
private:
	map<string, Person*> m;
public:
	Person* check_ID(); //ID�� �´� ��ü password�� ���纸�� ��P���� ��ü return
};

class Person {
	string ID; //�� ����� ID�� string type���� ����
	string password; //�� ����� ID�� string type���� ����
	int type;
public: 
	void set_ID(string); //string�� �Է¹޾� ID�� string type���� ����
	string get_ID(void); //ID�� string type���� return
	void set_password(string); //string�� �Է¹޾� password�� string type���� ����
	string get_password(void); //password�� string type���� return
	void set_type(int); //string�� �Է¹޾� type�� string type���� ����
	int get_type(void); //type�� string type���� return
};

class Boss : public Person {
	string store_name; //���� �̸��� string type���� ����
	string store_PH; //���� ��ȭ��ȣ�� string type���� ����
	bool open = true; //open ���¸� bool type����. �ʱⰪ�� ���� ���·�7
public:
	Store_menu sm;
	Store_status ss;
	void set_store(void); //���� �̸��� cin���� string type���� �޾Ƽ� store_ġname�� �־��ش�. 
	void set_PH(void); //���� ��ȭ��ȣ�� cin���� string type���� �޾Ƽ� store_PH�� �־��ش�.
	void store_open(void); //open�� false�� true��, true�� false�� �ٲ��ش�.-true���� false�� �� ���� cooking_over�� �����ؼ� true�϶��� ���� �� �ִ�. 
	bool checking(void); //order_list�� �ֹ��Ϸ� ���θ� Ȯ���Ͽ� ��� true�϶��� true�� return, �ϳ��� �ֹ� ���������� false return
};

class Customer:public Person {
	int completed_order=0; //�ֹ� �Ϸ�� ������ ����
	Store_menu* store; //���� ���� ���Ը� �����ߴ��� 
	vector<int> order_list; //���� �ֹ������� int array type ���� ����
public:
	friend class Store_status;
	void choose_store(int); //���Ը� int type���� �����ؼ� �ش��ϴ� ���Ը� store�� �Ҵ����ش�.
	void make_order(void); // ������ ������ȣ�� �������� �޴��� �ϳ��� �Է¹޾� array�� ����� order[]�� �־��ش�. 
//	friend void Store_status::take_order(Customer& cus); //take_order�� order�� ������ �� �ֵ���!
	void show_order(Store_menu*); // ������ ������ �ֹ��ߴ��� �����ش�. ����� ����ִ���.
	void alarm(); //(completed_order�� 0�� �ƴϸ�) ���� �Ϸ� �˶� �� completed_order=0
};

class Store_status {
	int order_num;
	map<int, Cuisine*> m_Cuisine;
	void take_order(Customer& cus);//�����κ��� �ֹ��� ������ orderlist�� �����ؼ� cousine�� ���� �����ϰ� m_cousine�� �ֹ���ȣ�� ���� �Է�. orderlist�� �ִ°� �� ������ �ֹ���ȣ+1
	void show_list(void); // m_cousine�� ����� ������� ���� ���¸� �� �� �ֵ���.
	void cooking_over(void); //show_list�� order_list�� ������� �� cin���� int���� �޾� �ش��ϴ� ��ȣ�� �ֹ� ���¸� false���� true�� �ٲ��ش�. Customer�� completed_order+=1
};

class Cuisine {
	string order_cus; //�ֹ��ڿ� ���� ����
	string order_menu; //�ֹ��� �޴��� ���� ����
	bool complete = 0; //�丮�� �� �Ǿ��µ� T/F
public:
	Cuisine(string cust, string cus_m, int b)
		: order_cus{ cust }, order_menu{ cus_m }, complete{ b } {}
	string get_order_cus(void); //order_cus�� string type���� return
	string get_order_menu(void); //order_menu�� string type���� return
	bool get_complete(void); //complete ���¸� t/f�� return

};

class Store_menu {
	vector<string[4]> menu; // �޴��� vector array type���� �����Ѵ�. ��ȣ, �̸�, ����, ���� �����ð�
public:
	vector<string> st_menu;
	string get_menu(int);
	void add_menu(void); //�߰��� �޴��� cin���� �Է¹޾Ƽ� menu�� �־��ش�. 
	void rvs_menu(void); //�޴��� �ϴ� ���� �� �� ������ �޴��� ��ȣ�� cin���� �Է¹��� �� �ٽ� string�� cin���� �޾Ƽ� menu�� �־��ش�. 
	void del_menu(void); //�޴��� �ϴ� ���� �� �� ������ �޴��� ��ȣ�� cin���� �Է¹޾� �����Ѵ�. 
	void show_menu(void); //���� �޴��� �� �� �ֵ��� �������ش�. 
	friend void Customer::show_order(Store_menu*);
};

