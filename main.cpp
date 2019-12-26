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

	//Boss 3개와 그에 맞는 person까지 생성.
	Boss b_tk("더큰도시락", "053-1234-1234","1111", login );
	Boss b_kh("김밥천국", "053-1234-4567","2222", login );
	Boss b_hd("뉴욕핫도그", "053-7894-4561", "3333", login );

	//각자 메뉴랑 상태 넣어주는 함수들.
	b_tk.sm = new Store_menu("더큰도시락");
	b_kh.sm = new Store_menu("김밥천국");
	b_hd.sm = new Store_menu("핫도그");

	b_tk.ss = new Store_status();
	b_kh.ss = new Store_status();
	b_hd.ss = new Store_status();

	//임시로 고객들 생성해 놓음
	Customer* cuss = new Customer("1", "1", login);
	Customer* cu = new Customer("2", "2", login);
	 
	
	while (1) {

		//아이디 로그인 할지 만들지.
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
			// 로그인 하는 과정
			Person & using_user = login->check_ID();

			//고객 사장 구분해주기
			if (using_user.get_type() == 1) {
				//로그인 한 user가 고객인 경우
				cout << "Hello, Customer!  Your ID is " << using_user.get_ID() << endl;
				cout << endl;
				Customer& user_cus = ((Customer&)using_user);

				flag = 0;
				while (flag == 0) {
					flag = 1;

					//일단 주문만 하는 거 만들어 놓았음.

					user_cus.alarm();

					cout << "What do u want to do? Select a number." << endl;
					cout << "1. 주문하기\n" << "2. 주문 내역 확인하기\n" << "0. Logout\n" << endl;

					//주문 완료된게 있다면 알람 띄워주기

					cin >> selnum;
					cout << endl;

					if (selnum == 0) { break; }
					switch (selnum) {
					case 1:
					{
						while (1) {

							//가게 골라서 Customer에 넣어주는 과정.
							cout << "What restaurant do you want? Select a number." << endl;
							login->Store_name_out(); //cout << "0. Logout\n" << "1. 더큰도시락\n" << "2. 김밥천국\n" << "3. 핫도그집 이름 모름" << endl;
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

							//고객이 선정한 가게의 메뉴와 state를 변수로 편하게 만들어 놓음.
							Store_menu* cus_sm = user_cus.getstore()->sm;
							Store_status* cus_ss = user_cus.getstore()->ss;
							//주문하기 전 메뉴를 띄어주는 과정.

							cus_sm->show_menu();

							//메뉴 보고 숫자 입력받아 주문하는 과정
							user_cus.make_order(*cus_ss);
							if (cus_ss->take_order(user_cus) == 1) {
								//주문 잘 들어갔나 확인알림
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
				//사장일 경우
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
							//들어온 주문 띄워주기
							user_bos.ss->show_list();

							cout << "if u complete dishes, press that number. press 0 if u want to go back.";

							//0입력할때 까지 주문번호 받아서 바꿔줄 수 있게.
							cin >> selnum;
							cout << endl;
							if (selnum == 0) { break; }
							user_bos.ss->cooking_over(selnum);
						}if (selnum == 0) { continue; }
					case 2:
						//가게 정보 관리 			
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

		//break; // 프로그램 종료하는 break
	}

	
}