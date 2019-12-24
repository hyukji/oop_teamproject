#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

class Store_menu {
	vector<vector<string>> menu; // 메뉴를 vector array type으로 저장한다. 번호, 이름, 가격, 예상 조리시간

public:
	vector<string> st_menu;
	Store_menu() {
	}
	Store_menu(string file_name) {
		std::ifstream ift(file_name + ".txt", std::ios::in);
		while (ift)
		{
			std::string text;
			getline(ift, text);
			if (text.length() == 72)
			{
				string number = text.substr(0, 12);
				number.erase(std::remove(number.begin(), number.end(), ' '), number.end());
				string name = text.substr(12, 20);
				name.erase(std::remove(name.begin(), name.end(), ' '), name.end());
				string price = text.substr(32, 20);
				price.erase(remove(price.begin(), price.end(), ' '), price.end());
				string time = text.substr(52, 20);
				time.erase(remove(time.begin(), time.end(), ' '), time.end());

				vector<string> info_of_a_menu;
				info_of_a_menu.push_back(number);
				info_of_a_menu.push_back(name);
				info_of_a_menu.push_back(price);
				info_of_a_menu.push_back(time);
				menu.push_back(info_of_a_menu);
			}
		}
		show_menu();
	}
	void add_menu(void) //추가할 메뉴를 cin으로 입력받아서 menu에 넣어준다. 	
	{
		string input_menu[4];
		input_menu[0] = to_string(menu.size() + 1);
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
		menu.push_back(input_menu_vector);
		st_menu.push_back(input_menu[1]);
	}
	void rvs_menu(void) //메뉴를 일단 보여 준 후 수정할 메뉴의 번호를 cin으로 입력받은 후 다시 string을 cin으로 받아서 menu에 넣어준다. 
	{
		int index;
		cout << "수정하고자 하는 메뉴 번호: ";
		cin >> index;
		cout << index << "번 메뉴를 수정합니다.";
		index--;
		string menu_name;
		cout << "메뉴 이름: ";
		cin >> menu_name;
		if (menu_name != menu[index][1]) {
			st_menu[index] = menu_name;
			menu[index][1] = menu_name;
		}
		cout << "메뉴 가격: ";
		cin >> menu[index][2];
		cout << "예상 조리시간: ";
		cin >> menu[index][3];


		show_menu();
	}
	void del_menu(void) //메뉴를 일단 보여 준 후 삭제할 메뉴의 번호를 cin으로 입력받아 삭제한다. 
	{
		int input_number;
		cout << "지우고자 하는 메뉴 번호: ";
		cin >> input_number;
		cout << input_number << "번 메뉴를 지웁니다." << endl;

		if (input_number <= 0 or input_number > menu.size()) {
			cout << "out of index" << endl;
			del_menu();
		}
		else if (input_number == menu.size())
		{
			menu.pop_back();
			st_menu.pop_back();
		}
		else
		{
			vector<vector<string>> temp = menu;
			menu.clear();
			if (input_number == 1) {
				for (int i = 1; i < temp.size(); i++) {
					temp[i][0] = to_string(stoi(temp[i][0]) - 1);
					menu.push_back(temp[i]);
					st_menu.push_back(temp[i][1]);
				}
			}
			else {
				for (int i = 0; i < input_number - 1; i++)
				{
					menu.push_back(temp[i]);
					st_menu.push_back(temp[i][1]);
				}
				for (int i = input_number; i < temp.size(); i++)
				{
					temp[i][0] = to_string(stoi(temp[i][0]) - 1);
					menu.push_back(temp[i]);
					st_menu.push_back(temp[i][1]);
				}
			}
		}

	}
	void show_menu(void) //고객이 메뉴를 볼 수 있도록 연결해준다.
	{
		cout.width(12);
		cout << "식별번호";
		cout.width(20);
		cout << "메뉴명";
		cout.width(20);
		cout << "가격";
		cout.width(20);
		cout << "조리시간";
		cout << endl;

		for (int i = 0; i < menu.size(); i++)
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
	void load_menu()
	{
		cout << "경고! 메뉴가 텍스트 파일 기준으로 변경됩니다." << endl << "메뉴를 불러오지 않으시려면 0번으로 되돌아가시고, 메뉴를 불러오려면 아무 키나 누르세요." << endl;
		int input_check;
		cin >> input_check;
		if (input_check == 0) { return; }

		menu.clear();
		string menu_list_file_name;

		cout << "메뉴를 저장한 txt 파일의 이름을 입력해주세요." << endl;
		cin >> menu_list_file_name;
		std::ifstream ift("menu.txt", std::ios::in);
		while (ift)
		{
			std::string text;
			getline(ift, text);
			if (text.length() == 72)
			{
				string number = text.substr(0, 12);
				number.erase(std::remove(number.begin(), number.end(), ' '), number.end());
				string name = text.substr(12, 20);
				name.erase(std::remove(name.begin(), name.end(), ' '), name.end());
				string price = text.substr(32, 20);
				price.erase(remove(price.begin(), price.end(), ' '), price.end());
				string time = text.substr(52, 20);
				time.erase(remove(time.begin(), time.end(), ' '), time.end());

				vector<string> info_of_a_menu;
				info_of_a_menu.push_back(number);
				info_of_a_menu.push_back(name);
				info_of_a_menu.push_back(price);
				info_of_a_menu.push_back(time);
				menu.push_back(info_of_a_menu);
				st_menu.push_back(name);
			}
		}
		show_menu();
	}
	void save_menu()
	{
		std::ofstream oft("menu.txt", std::ios::trunc);
		for (int i = 0; i < menu.size(); i++) {
			oft << setw(12) << menu[i][0] << setw(20) << menu[i][1] << setw(20) << menu[i][2] << setw(20) << menu[i][3] << "\n";
		}
	}
};