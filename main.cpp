#include "food.h"

#include <iostream>
#include <Windows.h>
using namespace std;


int main() {

	int selnum;

	Boss b_tk("��ū���ö�", "1111", 0);
	Boss b_kh("���õ��", "2222", 0);
	Boss b_hd("�ֵ���", "3333", 0);
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
			continue;
			break;
		case 2:
			// �α��� �ϴ� ����
			Person& using_user = login.check_ID();


			//�� ���� �������ֱ�
			if (using_user.get_type == 0) {
				//�α��� �� user�� ���� ���
				cout << "Hello, Customer!  Your ID is " << using_user.get_ID() << endl;
				Customer& user_cus = ((Customer&)using_user);
			
				while (1) {

					cout << "What restaurant do you want? Select a number." << endl;
					cout << "0. Logout\n" << "1. ��ū���ö�\n" << "2. ���õ��\n" << "3. �ֵ����� �̸� ��" << endl;

					//���� ��� Customer�� �־��ִ� ����.
					cin >> selnum;
					if (selnum == 0) { break; }
					switch (selnum) {
					case 1:
						user_cus.setstore(&b_tk);
						break;
					case 2:
						user_cus.setstore(&b_kh);
						break;
					}

					//���� ������ ������ �޴��� state�� ������ ���ϰ� ����� ����.
					Store_menu* cus_sm = user_cus.getstore()->sm;
					Store_status* cus_ss = user_cus.getstore()->ss;


					//�ϴ� �ֹ��� �ϴ� �� ����� ������.
					cout << "What do u want to do? Select a number." << endl;
					cout << "0. Logout\n" << "1. �ֹ��ϱ�\n";

					//�ֹ��ϱ� �� �޴��� ����ִ� ����.
					cin >> selnum;
					if (selnum == 0) { break; }
					switch (selnum) {
					case 1:
						cus_sm->show_menu();
						break;
					}

					//�޴� ���� ���� �Է¹޾� �ֹ��ϴ� ����
					cout << "Select dish u want\n";
					user_cus.make_order();
					cus_ss->take_order(user_cus);

					//�ֹ� �� ���� Ȯ�ξ˸�
					user_cus.show_order(*cus_sm);
					//�� �����ϴ� 
				}

			}
			else {
				//������ ���
				cout << "Hello, Customer!  Your ID is " << using_user.get_ID() << endl;
				Boss& user_bos = ((Boss&)using_user);

				while (1) {
					cout << "What do u want to do? Select a number." << endl;
					cout << "1. Confirm orders\n" << "2. Manage store information\n" << "0. Logout\n";
					cin >> selnum;
					if (selnum == 0) { break; }
					switch (selnum) {
					case 1:
						while (1) {
							//���� �ֹ� ����ֱ�
							user_bos.ss->show_list();

							cout << "if u complete dishes, press that number. press 0 if u want to go back.";

							//0�Է��Ҷ� ���� �ֹ���ȣ �޾Ƽ� �ٲ��� �� �ְ�.
							cin >> selnum;
							if (selnum == 0) { break; }
							user_bos.ss->cooking_over(selnum);
						}
						break;
					case 2:					
						//���� ���� ���� 					
						cout << "What do u want to do? Select a number." << endl;
						cout << "1. Store name & PH update" << endl << "2. Add menu" << endl;
						cout << "3. delete menu" << endl << "0.Logout" << endl;
						
						cin >> selnum;
						if (selnum == 0) { break; }
						switch (selnum) {
						case 1:
							void set_store(void);
							void set_PH(void);
							break;
						case 2:
							user_bos.sm->add_menu();
							break;
						case 3:
							user_bos.sm->del_menu();
							break;

						}
						break;
					}

				}
			}

		}

		break; // ���α׷� �����ϴ� break
	}

	
}