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
	Login() { cout << "로그인 생성 완료\n;"; }
	void check_user(Person*);
	Person& check_ID(); //ID에 맞는 객체 password와 맞춰보고 맞P으면 객체 return
};

class Person {
	string ID; //각 사람의 ID를 string type으로 저장
	string password; //각 사람의 ID를 string type으로 저장
	int type;
public:
	Person(string id, string pw, int rhs, Login*);
	void set_ID(string); //string을 입력받아 ID를 string type으로 저장
	string get_ID(void); //ID를 string type으로 return
	void set_password(string); //string을 입력받아 password를 string type으로 저장
	string get_password(void); //password를 string type으로 return
	void set_type(int); //string을 입력받아 type를 string type으로 저장
	int get_type(void); //type를 string type으로 return
};

class Boss : public Person {
	string store_name; //가게 이름을 string type으로 저장
	string store_PH; //가게 전화번호를 string type으로 저장
	bool open = true; //open 상태를 bool type으로. 초기값은 열린 상태로7
public:
	Store_menu* sm;
	Store_status* ss;

	Boss(string, string, string, Login*);
	void set_store(void); //가게 이름을 cin으로 string type으로 받아서 store_치name에 넣어준다. 
	void set_PH(void); //가게 전화번호를 cin으로 string type으로 받아서 store_PH에 넣어준다.

	void set_sm(Store_menu*);
	void set_ss(Store_status*);


	//void store_open(void); //open이 false면 true로, true면 false로 바꿔준다.-true에서 false로 갈 때는 cooking_over을 실해해서 true일때만 닫을 수 있다. 
	//bool checking(void); //order_list의 주문완료 여부를 확인하여 모두 true일때만 true를 return, 하나라도 주문 남아있으면 false return
};

class Customer :public Person {
	int completed_order = 0; //주문 완료된 음식의 개수
	int my_order=0;
	Boss* store; //고객이 무슨 가게를 선택했는지 
	vector<int> order_list; //고객의 주문내역을 int array type 으로 저장
public:
	friend class Store_status;
	Customer(int,string,string,Login*);
	Customer(string id, string pw, Login* login);

	Boss* getstore() { return store; };
	void setstore(Boss* b) { store = b; };
	void make_order(Store_status); // 가게의 고유번호를 바탕으로 메뉴를 하나씩 입력받아 array로 만들어 order[]에 넣어준다. 
//	friend void Store_status::take_order(Customer& cus); //take_order가 order에 접근할 수 있도록!
	void show_order(Store_menu, Store_status); // 본인이 무엇을 주문했는지 보여준다. 사람이 몇명있는지.
	void alarm(); //(completed_order가 0이 아니면) 음식 완료 알람 및 completed_order=0
};

class Store_status {
	int order_num = 1;
	map<int, Cuisine*> m_Cuisine;
public:
	void take_order(Customer& cus);//고객으로부터 주문을 받으면 orderlist를 분해해서 cousine을 각각 생성하고 m_cousine에 주문번호랑 같이 입력. orderlist에 있는거 다 넣으면 주문번호+1
	void show_list(void); // m_cousine을 출력해 사장님이 현재 상태를 볼 수 있도록.
	void cooking_over(int); //show_list로 order_list을 출력해준 후 cin으로 int값을 받아 해당하는 번호의 주문 상태를 false에서 true로 바꿔준다. Customer의 completed_order+=1
	friend void Customer::make_order(Store_status);
	friend void Customer::show_order(Store_menu, Store_status);
};

class Cuisine {
	Customer& order_cus; //주문자에 대한 정보
	string order_menu; //주문한 메뉴에 대한 정보
	int complete = 0; //요리가 다 되었는데 T/F
public:
	Cuisine(Customer& cust, string cus_m, int b)
		: order_cus{ cust }, order_menu{ cus_m }, complete{ b } {}
	Customer& get_order_cus(void); //order_cus를 string type으로 return
	string get_order_menu(void); //order_menu를 string type으로 return
	int get_order_complete();
	void change_complete(void); //complete 상태를 t/f로 return
	friend void Customer::show_order(Store_menu, Store_status);
};
class Store_menu {
	vector<vector<string>> menu; // 메뉴를 vector array type으로 저장한다. 번호, 이름, 가격, 예상 조리시간
public:
	Store_menu();
	Store_menu(string file_name);

	vector<string> st_menu = {"김치찌개","김치볶음밥","소금구이"};
	string get_menu(int);
	void add_menu(void); //추가할 메뉴를 cin으로 입력받아서 menu에 넣어준다. 
	void rvs_menu(void); //메뉴를 일단 보여 준 후 수정할 메뉴의 번호를 cin으로 입력받은 후 다시 string을 cin으로 받아서 menu에 넣어준다. 
	void del_menu(void); //메뉴를 일단 보여 준 후 삭제할 메뉴의 번호를 cin으로 입력받아 삭제한다. 
	void show_menu(void); //고객이 메뉴를 볼 수 있도록 연결해준다.
	void load_menu();
	void save_menu();
	//friend void Customer::show_order(Store_menu, Store_status);

};
