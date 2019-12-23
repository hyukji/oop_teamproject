#include "food.h"
#include <fstream>
using namespace std;

class Store_menu {
	vector<string[4]> menu; // �޴��� vector array type���� �����Ѵ�. ��ȣ, �̸�, ����, ���� �����ð�
public:
	vector<string> st_menu;
	string get_menu(int);
	void add_menu(void); //�߰��� �޴��� cin���� �Է¹޾Ƽ� menu�� �־��ش�. 
	void rvs_menu(void); //�޴��� �ϴ� ���� �� �� ������ �޴��� ��ȣ�� cin���� �Է¹��� �� �ٽ� string�� cin���� �޾Ƽ� menu�� �־��ش�. 
	void del_menu(void); //�޴��� �ϴ� ���� �� �� ������ �޴��� ��ȣ�� cin���� �Է¹޾� �����Ѵ�. 
	void show_menu(void); //���� �޴��� �� �� �ֵ��� �������ش�.
	void load_menu();
	void save_menu();
};

void Store_menu::add_menu() {
	string input_menu[4];
	input_menu[0] = sizeof(menu) + 1;
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

}

void Store_menu::rvs_menu(){
	string input_menu[4];
	cout << "�����ϰ��� �ϴ� �޴� ��ȣ: ";
	cin >> input_menu[0];
	cout << input_menu[0]<<"�� �޴��� �����մϴ�.";
	cout << "�޴� �̸�: ";
	cin >> input_menu[1];
	cout << "�޴� ����: ";
	cin >> input_menu[2];
	cout << "���� �����ð�: ";
	cin >> input_menu[3];
	menu.insert(menu.begin() + 3, input_menu);
}

void Store_menu::del_menu(){
	int input_number;
	cout << "������� �ϴ� �޴� ��ȣ: ";
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
	cout << "�ĺ���ȣ";
	cout.width(20);
	cout << "�޴���";
	cout.width(20);
	cout << "����";
	cout.width(20);
	cout << "�����ð�";
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
	cout << "���! �޴��� �ؽ�Ʈ ���� �������� ����˴ϴ�." << endl <<"�޴��� �ҷ����� �����÷��� 0������ �ǵ��ư��ð�, �޴��� �ҷ������� �ƹ� Ű�� ��������." << endl; 
	int input_check;
	cin >> input_check;
	if (input_check == 0) { return; }

	string menu_list_file_name;

	cout << "�޴��� ������ txt ������ �̸��� �Է����ּ���." << endl;
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
	oft << cout.width(12) << "�ĺ���ȣ" << cout.width(20) << "�޴���" << cout.width(20) << "����" << cout.width(20) << "�����ð�" << endl;
	for (int i = 0; i < sizeof(menu); i++) {
		oft << cout.width(12) << menu[i][0] << cout.width(20) << menu[i][1] << cout.width(20) << menu[i][2] << cout.width(20) << menu[i][3] << endl;
	}
}

