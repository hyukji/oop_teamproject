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
	vector<vector<string>> menu; // �޴��� vector array type���� �����Ѵ�. ��ȣ, �̸�, ����, ���� �����ð�

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
	void add_menu(void) //�߰��� �޴��� cin���� �Է¹޾Ƽ� menu�� �־��ش�. 	
	{
		string input_menu[4];
		input_menu[0] = to_string(menu.size() + 1);
		cout << "�޴� �̸�: ";
		cin >> input_menu[1];
		cout << "�޴� ����: ";
		cin >> input_menu[2];
		cout << "���� �����ð�: ";
		cin >> input_menu[3];
		vector<string> input_menu_vector;
		for (int i = 0; i < 4; i++) {
			input_menu_vector.push_back(input_menu[i]);
		}
		menu.push_back(input_menu_vector);
		st_menu.push_back(input_menu[1]);
	}
	void rvs_menu(void) //�޴��� �ϴ� ���� �� �� ������ �޴��� ��ȣ�� cin���� �Է¹��� �� �ٽ� string�� cin���� �޾Ƽ� menu�� �־��ش�. 
	{
		int index;
		cout << "�����ϰ��� �ϴ� �޴� ��ȣ: ";
		cin >> index;
		cout << index << "�� �޴��� �����մϴ�.";
		index--;
		string menu_name;
		cout << "�޴� �̸�: ";
		cin >> menu_name;
		if (menu_name != menu[index][1]) {
			st_menu[index] = menu_name;
			menu[index][1] = menu_name;
		}
		cout << "�޴� ����: ";
		cin >> menu[index][2];
		cout << "���� �����ð�: ";
		cin >> menu[index][3];


		show_menu();
	}
	void del_menu(void) //�޴��� �ϴ� ���� �� �� ������ �޴��� ��ȣ�� cin���� �Է¹޾� �����Ѵ�. 
	{
		int input_number;
		cout << "������� �ϴ� �޴� ��ȣ: ";
		cin >> input_number;
		cout << input_number << "�� �޴��� ����ϴ�." << endl;

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
	void show_menu(void) //���� �޴��� �� �� �ֵ��� �������ش�.
	{
		cout.width(12);
		cout << "�ĺ���ȣ";
		cout.width(20);
		cout << "�޴���";
		cout.width(20);
		cout << "����";
		cout.width(20);
		cout << "�����ð�";
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
		cout << "���! �޴��� �ؽ�Ʈ ���� �������� ����˴ϴ�." << endl << "�޴��� �ҷ����� �����÷��� 0������ �ǵ��ư��ð�, �޴��� �ҷ������� �ƹ� Ű�� ��������." << endl;
		int input_check;
		cin >> input_check;
		if (input_check == 0) { return; }

		menu.clear();
		string menu_list_file_name;

		cout << "�޴��� ������ txt ������ �̸��� �Է����ּ���." << endl;
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