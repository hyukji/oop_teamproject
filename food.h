#pragma once


#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Login;
class Store_menu;
class Store_status;
class Cuisine;
class Person;
class Boss;
class Customer;

class Login {
private:
	map<string, Person*> m;
public:
	Login() { cout << "�α��� ���� �Ϸ�\n;"; }
	void check_user(Person*);
	Person& check_ID(); //ID�� �´� ��ü password�� ���纸�� ��P���� ��ü return
};

class Person {
	string ID; //�� ����� ID�� string type���� ����
	string password; //�� ����� ID�� string type���� ����
	int type;
public:
	Person(string id, string pw, int rhs, Login*);
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
	Store_menu* sm;
	Store_status* ss;

	Boss(string, string, string, Login*);
	void set_store(void); //���� �̸��� cin���� string type���� �޾Ƽ� store_ġname�� �־��ش�. 
	void set_PH(void); //���� ��ȭ��ȣ�� cin���� string type���� �޾Ƽ� store_PH�� �־��ش�.

	void set_sm(Store_menu*);
	void set_ss(Store_status*);


	//void store_open(void); //open�� false�� true��, true�� false�� �ٲ��ش�.-true���� false�� �� ���� cooking_over�� �����ؼ� true�϶��� ���� �� �ִ�. 
	//bool checking(void); //order_list�� �ֹ��Ϸ� ���θ� Ȯ���Ͽ� ��� true�϶��� true�� return, �ϳ��� �ֹ� ���������� false return
};

class Customer :public Person {
	int completed_order = 0; //�ֹ� �Ϸ�� ������ ����
	int my_order=0;
	Boss* store; //���� ���� ���Ը� �����ߴ��� 
	vector<int> order_list; //���� �ֹ������� int array type ���� ����
public:
	friend class Store_status;
	Customer(int,string,string,Login*);
	Customer(string id, string pw, Login* login);

	Boss* getstore() { return store; };
	void setstore(Boss* b) { store = b; };
	void make_order(Store_status); // ������ ������ȣ�� �������� �޴��� �ϳ��� �Է¹޾� array�� ����� order[]�� �־��ش�. 
//	friend void Store_status::take_order(Customer& cus); //take_order�� order�� ������ �� �ֵ���!
	void show_order(Store_menu, Store_status); // ������ ������ �ֹ��ߴ��� �����ش�. ����� ����ִ���.
	void alarm(); //(completed_order�� 0�� �ƴϸ�) ���� �Ϸ� �˶� �� completed_order=0
};

class Store_status {
	int order_num = 1;
	map<int, Cuisine*> m_Cuisine;
public:
	void take_order(Customer& cus);//�����κ��� �ֹ��� ������ orderlist�� �����ؼ� cousine�� ���� �����ϰ� m_cousine�� �ֹ���ȣ�� ���� �Է�. orderlist�� �ִ°� �� ������ �ֹ���ȣ+1
	void show_list(void); // m_cousine�� ����� ������� ���� ���¸� �� �� �ֵ���.
	void cooking_over(int); //show_list�� order_list�� ������� �� cin���� int���� �޾� �ش��ϴ� ��ȣ�� �ֹ� ���¸� false���� true�� �ٲ��ش�. Customer�� completed_order+=1
	friend void Customer::make_order(Store_status);
	friend void Customer::show_order(Store_menu, Store_status);
};

class Cuisine {
	Customer& order_cus; //�ֹ��ڿ� ���� ����
	string order_menu; //�ֹ��� �޴��� ���� ����
	int complete = 0; //�丮�� �� �Ǿ��µ� T/F
public:
	Cuisine(Customer& cust, string cus_m, int b)
		: order_cus{ cust }, order_menu{ cus_m }, complete{ b } {}
	Customer& get_order_cus(void); //order_cus�� string type���� return
	string get_order_menu(void); //order_menu�� string type���� return
	int get_order_complete();
	void change_complete(void); //complete ���¸� t/f�� return
	friend void Customer::show_order(Store_menu, Store_status);
};
class Store_menu {
	vector<vector<string>> menu; // �޴��� vector array type���� �����Ѵ�. ��ȣ, �̸�, ����, ���� �����ð�
public:
	Store_menu();
	Store_menu(string file_name);

	vector<string> st_menu = {"��ġ�","��ġ������","�ұݱ���"};
	string get_menu(int);
	void add_menu(void); //�߰��� �޴��� cin���� �Է¹޾Ƽ� menu�� �־��ش�. 
	void rvs_menu(void); //�޴��� �ϴ� ���� �� �� ������ �޴��� ��ȣ�� cin���� �Է¹��� �� �ٽ� string�� cin���� �޾Ƽ� menu�� �־��ش�. 
	void del_menu(void); //�޴��� �ϴ� ���� �� �� ������ �޴��� ��ȣ�� cin���� �Է¹޾� �����Ѵ�. 
	void show_menu(void); //���� �޴��� �� �� �ֵ��� �������ش�.
	void load_menu();
	void save_menu();
	//friend void Customer::show_order(Store_menu, Store_status);

};
