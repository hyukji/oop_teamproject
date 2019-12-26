#include "food.h"

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {
	int selnum;
	bool flag;

	Login log_in;
	Login* login = &log_in;

	//Boss 3���� �׿� �´� person���� ����.
	Boss b_tk("��ū���ö�", "053-1234-1234","1111", login );
	Boss b_kh("���õ��", "053-1234-4567","2222", login );
	Boss b_hd("�����ֵ���", "053-7894-4561", "3333", login );

	//���� �޴��� ���� �־��ִ� �Լ���.
	b_tk.sm = new Store_menu("��ū���ö�");
	b_kh.sm = new Store_menu("���õ��");
	b_hd.sm = new Store_menu("�ֵ���");

	b_tk.ss = new Store_status();
	b_kh.ss = new Store_status();
	b_hd.ss = new Store_status();

	//�ӽ÷� ���� ������ ����
	Customer* cuss = new Customer("1", "1", login);
	Customer* cu = new Customer("2", "2", login);
	 
	
	while (1) {

		//���̵� �α��� ���� ������.
		cout << "What do you want to do? Select a number." << endl;
		cout << "1. Make new account" << endl << "2. Login" << endl << "0. exit\n";
		cin >> selnum;
		cout << endl;
		if (selnum == 0) { break; }
		switch (selnum) {
		case 1:
			login->sign_up();
			break;
		case 2: {
			// �α��� �ϴ� ����
			Person & using_user = login->check_ID();

			//�� ���� �������ֱ�
			if (using_user.get_type() == 1) {
				//�α��� �� user�� ���� ���
				cout << "Hello, Customer!  Your ID is " << using_user.get_ID() << endl;
				cout << endl;
				Customer& user_cus = ((Customer&)using_user);

				flag = 0;
				while (flag == 0) {
					flag = 1;

					//�ϴ� �ֹ��� �ϴ� �� ����� ������.

					user_cus.alarm();

					cout << "What do u want to do? Select a number." << endl;
					cout << "1. �ֹ��ϱ�\n" << "2. �ֹ� ���� Ȯ���ϱ�\n" << "0. Logout\n" << endl;

					//�ֹ� �Ϸ�Ȱ� �ִٸ� �˶� ����ֱ�

					cin >> selnum;
					cout << endl;

					if (selnum == 0) { break; }
					switch (selnum) {
					case 1:
					{
						while (1) {

							//���� ��� Customer�� �־��ִ� ����.
							cout << "What restaurant do you want? Select a number." << endl;
							login->Store_name_out(); //cout << "0. Logout\n" << "1. ��ū���ö�\n" << "2. ���õ��\n" << "3. �ֵ����� �̸� ��" << endl;
							cout << "0. Go Back\n";

							flag = 0;
							while (flag == 0) {
								cin >> selnum;
								cout << endl;
	
								if (selnum == 0) { break; }
								flag = 1;
								switch (selnum) {
								case 1:
									user_cus.setstore(&b_kh);
									break;
								case 2:
									user_cus.setstore(&b_hd);
									break;
								case 3:
									user_cus.setstore(&b_tk);
									break;
								default:
									flag = 0;
									cout << "your input is not valid.\n";
									break;
								}
							}
							if (selnum == 0) { break; }

							//���� ������ ������ �޴��� state�� ������ ���ϰ� ����� ����.
							Store_menu* cus_sm = user_cus.getstore()->sm;
							Store_status* cus_ss = user_cus.getstore()->ss;
							//�ֹ��ϱ� �� �޴��� ����ִ� ����.

							cus_sm->show_menu();

							//�޴� ���� ���� �Է¹޾� �ֹ��ϴ� ����
							user_cus.make_order(*cus_ss);
							if (cus_ss->take_order(user_cus) == 1) {
								//�ֹ� �� ���� Ȯ�ξ˸�
								user_cus.show_order(*cus_sm, *cus_ss);
							};

							break;
						};

						break;
					}
					case 2: {
						user_cus.check_menu();
						flag = 0;
						break; }
					default:
						flag = 0; cout << "your input is not valid.\n";
						break;
					}
					
					if (selnum == 0) { continue; }
					flag = 0;
					//continue;

				};

				if (selnum == 0) { continue; }
			}
			else {
				//������ ���
				cout << "Hello, Customer!  Your ID is " << using_user.get_ID() << endl;
				Boss& user_bos = ((Boss&)using_user);

				while (1) {
					cout << "What do u want to do? Select a number." << endl;
					cout << "1. Confirm orders\n" << "2. Manage store information\n" << "0. Logout\n";

					cin >> selnum;
					cout << endl;

					if (selnum == 0) { break; }

					switch (selnum) {
					case 1:
						while (1) {
							//���� �ֹ� ����ֱ�
							user_bos.ss->show_list();

							cout << "if u complete dishes, press that number. press 0 if u want to go back.";

							//0�Է��Ҷ� ���� �ֹ���ȣ �޾Ƽ� �ٲ��� �� �ְ�.
							cin >> selnum;
							cout << endl;
							if (selnum == 0) { break; }
							user_bos.ss->cooking_over(selnum);
						}if (selnum == 0) { continue; }
					case 2:
						//���� ���� ���� 			
						cout << "What do u want to do? Select a number." << endl;
						cout << "1. Store name & PH update" << endl << "2. Add menu" << endl;
						cout << "3. delete menu" << endl << "4. revise menu" << endl << "5. show menu" << endl << "0. Go Back" << endl;

						flag = 0;
						while (flag == 0) {
							flag = 1;
							cin >> selnum;
							cout << endl;
							if (selnum == 0) { break; }
							switch (selnum) {
							case 1:
								user_bos.set_store();
								user_bos.set_PH();
								cout << endl;
								break;
							case 2:
								user_bos.sm->add_menu();
								user_bos.sm->save_menu();
								cout << endl;
								break;
							case 3:
								user_bos.sm->show_menu();
								user_bos.sm->del_menu();
								user_bos.sm->save_menu();
								user_bos.sm->show_menu();
								break;
							case 4:
								user_bos.sm->show_menu();
								user_bos.sm->rvs_menu();
								user_bos.sm->save_menu();

								break;
							case 5:
								user_bos.sm->show_menu();
								break;
							default:
								flag = 0;
								cout << "your input is not valid.\n" << endl;
								break;

							}
						}
					default:
						break;
					}

				}
			}}

		default:
			continue;
		}

		//break; // ���α׷� �����ϴ� break
	}

	
}