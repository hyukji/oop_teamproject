#include "food.h"
#include <fstream>
using namespace std;

class Store_menu {
	vector<string[4]> menu; // 메뉴를 vector array type으로 저장한다. 번호, 이름, 가격, 예상 조리시간
public:
	vector<string> st_menu;
	string get_menu(int);
	void add_menu(void); //추가할 메뉴를 cin으로 입력받아서 menu에 넣어준다. 
	void rvs_menu(void); //메뉴를 일단 보여 준 후 수정할 메뉴의 번호를 cin으로 입력받은 후 다시 string을 cin으로 받아서 menu에 넣어준다. 
	void del_menu(void); //메뉴를 일단 보여 준 후 삭제할 메뉴의 번호를 cin으로 입력받아 삭제한다. 
	void show_menu(void); //고객이 메뉴를 볼 수 있도록 연결해준다.
	void load_menu();
	void save_menu();
};

void Store_menu::add_menu() {
	string input_menu[4];
	input_menu[0] = sizeof(menu) + 1;
	cout << "메뉴 이름: ";
	cin >> input_menu[1];
	cout << "메뉴 가격: ";
	cin >> input_menu[2];
	cout << "예상 조리시간: ";
	cin >> input_menu[3];
	vector<string> input_menu_vector;
	for (int i = 0; i < 4; i++) {
		input_menu_vector.push_back(input_menu[i]);
	}

}

void Store_menu::rvs_menu(){
	string input_menu[4];
	cout << "수정하고자 하는 메뉴 번호: ";
	cin >> input_menu[0];
	cout << input_menu[0]<<"번 메뉴를 수정합니다.";
	cout << "메뉴 이름: ";
	cin >> input_menu[1];
	cout << "메뉴 가격: ";
	cin >> input_menu[2];
	cout << "예상 조리시간: ";
	cin >> input_menu[3];
	menu.insert(menu.begin() + 3, input_menu);
}

void Store_menu::del_menu(){
	int input_number;
	cout << "지우고자 하는 메뉴 번호: ";
	cin >> input_number;
	vector<string[4]> temp = menu;
	menu.clear();
	for (int i = 1; i < input_number; i++) {
		menu.push_back(temp[i]);
	}
	for (int i = input_number + 1; i < sizeof(temp); i++) {
		temp[i][0] = to_string(stoi(temp[i][0])+1);
		menu.push_back(temp[i]);
	}
}
void order_list(string* arr) {
	cout.width(10);
	cout << arr[0];
	cout.width(10);
	cout << arr[1];
	cout.width(15);
	cout << arr[2];
	cout.width(10);
	cout << arr[3] << endl;
}
void Store_menu::show_menu() {
	cout.width(12);
	cout << "식별번호";
	cout.width(20);
	cout << "메뉴명";
	cout.width(20);
	cout << "가격";
	cout.width(20);
	cout << "조리시간";
	cout << endl;

	for (int i = 0; i < sizeof(menu); i++) 
	{
		cout.width(12);
		cout << menu[i][0];
		for (int j = 1; j < 4; j++) 
		{
			cout.width(20);
			cout << menu[i][j];
		}
		cout << endl;
	}
}


void Store_menu::load_menu() {
	cout << "경고! 메뉴가 텍스트 파일 기준으로 변경됩니다." << endl <<"메뉴를 불러오지 않으시려면 0번으로 되돌아가시고, 메뉴를 불러오려면 아무 키나 누르세요." << endl; 
	int input_check;
	cin >> input_check;
	if (input_check == 0) { return; }

	string menu_list_file_name;

	cout << "메뉴를 저장한 txt 파일의 이름을 입력해주세요." << endl;
	cin >> menu_list_file_name;
	std::ifstream ift("menu.txt", std::ios::in);;
	int index = 0;
	while (ift) {
		std::string text;
		getline(ift,text);
		string number = text.substr(0, 12);
		string name = text.substr(13, 32);
		string price = text.substr(33, 52);
		string time_to_cook = text.substr(53, 72);
		index++;
		
	}
}

void Store_menu::save_menu(void) {
	std::ofstream oft("menu.txt", std::ios::trunc);
	oft << cout.width(12) << "식별번호" << cout.width(20) << "메뉴명" << cout.width(20) << "가격" << cout.width(20) << "조리시간" << endl;
	for (int i = 0; i < sizeof(menu); i++) {
		oft << cout.width(12) << menu[i][0] << cout.width(20) << menu[i][1] << cout.width(20) << menu[i][2] << cout.width(20) << menu[i][3] << endl;
	}
}

