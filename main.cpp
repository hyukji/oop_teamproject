#include "food.h"

#include <iostream>
#include <Windows.h>
using namespace std;


int main() {

	int selnum;
	
	Boss b_kh("��õ", "1111", 0);
	Boss b_tk("��ū", "2222", 0);
	//Boss b_hd("�ֵ���", "3333", 0);
	// ���� 2�� �޴��� ���±��� �ؼ� �� �����س���.


	//���� �޴��� ���� �־��ִ� �Լ���.

	Login login;
	
	while (1) {

		//���̵� �α��� ���� ������.
		cout << "What do you want to do? Select a number." << endl;
		cout << "1. Make new account" << endl << "2. Login" << endl;
		cin >> selnum;
		switch (selnum) {
		case 1:
			// ���� ���� ����� �ִ� �� 
			break;
		case 2:
			// �α��� �ϴ� ����
			Person * using_user = login.check_ID();


			//�� ���� �������ֱ�
			if (using_user->get_type == 0) {
				cout << "Hello, Customer!  Your ID is " << using_user->get_ID() << endl;
				while (1) {
					//�α��� �� user�� ���� ���
					cout << "What restaurant do you want? Select a number." << endl;
					cout << "0. Logout" << "1. ��ū���ö�" << endl << "2. ���õ��" << endl << "3. �ֵ����� �̸� ��" << endl;

					////////////////////////////////////////////////////////

					//���� �߰��� ��� �� ���Դ� ��� ����?

					//////////////////////////////////////////////////////////
					cin >> selnum;
					if (selnum == 0) { break; }
					switch (selnum) {
					case 1:

						break;
					case 2:

						break;

					}
					cout << "What do u want to order? Select a number." << endl;
					cout << "1. Store name & PH update" << endl << "2. Set_menu" << endl;
					cout << "3. Add_menu" << endl << "4. Open Your Store" << endl;
					cout << "5. Close your store" << endl << "0.Logout" << endl;


					cin >> selnum;
					switch (selnum) {
					case 0:
						break;
					case 1:
						break;
					case 2:
						break;

					}

					//�� �����ϴ� 
					break;
				}

			}
			else { 
				//������ ����� switch
				; }

		}



		break; // ���α׷� �����ϴ� break
	}

	
}