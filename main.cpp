#include "food.h"

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {
	int selnum;
	
	Login log_in;
	Login* login = &log_in;
	//Boss 3개와 그에 맞는 person까지 생성.
	Boss b_tk("더큰도시락", "053-1234-1234","1111", login );
	Boss b_kh("김밥천국", "053-1234-4567","2222", login );
	Boss b_hd("핫도그", "053-7894-4561", "3333", login );

	b_tk.sm = new Store_menu("menu");
	b_kh.sm = new Store_menu("menu");
	b_hd.sm = new Store_menu("menu");

	b_tk.ss = new Store_status();
	b_kh.ss = new Store_status();
	b_hd.ss = new Store_status();


	Customer* cus = new Customer("manager", "0000", login);
	//각자 메뉴랑 상태 넣어주는 함수들.
	 
	
	while (1) {

		//아이디 로그인 할지 만들지.
		cout << "What do you want to do? Select a number." << endl;
		cout << "1. Make new account" << endl << "2. Login" << endl << "0. exit\n";
		cin >> selnum;
		if (selnum == 0) { break; }

		switch (selnum) {
		case 1:
			// 새로 계정 만들어 주는 거 
		//	Customer * cus = new Customer("manager", "0000", login);
			break;
		case 2:
			// 로그인 하는 과정
			Person& using_user = login->check_ID();


			//고객 사장 구분해주기
			if (using_user.get_type() == 1) {
				//로그인 한 user가 고객인 경우
				cout << "Hello, Customer!  Your ID is " << using_user.get_ID() << endl;
				Customer& user_cus = ((Customer&)using_user);
			
				while (1) {

					cout << "What restaurant do you want? Select a number." << endl;
					cout << "0. Logout\n" << "1. 더큰도시락\n" << "2. 김밥천국\n" << "3. 핫도그집 이름 모름" << endl;

					//가게 골라서 Customer에 넣어주는 과정.
					cin >> selnum;
					if (selnum == 0) { break; }
					switch (selnum) {
					case 1:
						user_cus.setstore(&b_tk);
						break;
					case 2:
						user_cus.setstore(&b_kh);
						break;
					case 3:
						user_cus.setstore(&b_hd);
						break;
					}

					//고객이 선정한 가게의 메뉴와 state를 변수로 편하게 만들어 놓음.
					Store_menu* cus_sm = user_cus.getstore()->sm;
					Store_status* cus_ss = user_cus.getstore()->ss;


					//일단 주문만 하는 거 만들어 놓았음.
					cout << "What do u want to do? Select a number." << endl;
					cout << "0. Logout\n" << "1. 주문하기\n";

					//주문하기 전 메뉴를 띄어주는 과정.
					cin >> selnum;
					if (selnum == 0) { break; }
					switch (selnum) {
					case 1:
						cus_sm->show_menu();
						break;
					}

					//메뉴 보고 숫자 입력받아 주문하는 과정
					user_cus.make_order(*cus_ss);
					cus_ss->take_order(user_cus);

					//주문 잘 들어갔나 확인알림
					user_cus.show_order(*cus_sm,*cus_ss);
					//고객 종료하는 
				}

			}
			else {
				//사장일 경우
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
							//들어온 주문 띄워주기
							user_bos.ss->show_list();

							cout << "if u complete dishes, press that number. press 0 if u want to go back.";

							//0입력할때 까지 주문번호 받아서 바꿔줄 수 있게.
							cin >> selnum;
							if (selnum == 0) { break; }
							user_bos.ss->cooking_over(selnum);
						}
						break;
					case 2:					
						//가게 정보 관리 					
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

		//break; // 프로그램 종료하는 break
	}

	
}