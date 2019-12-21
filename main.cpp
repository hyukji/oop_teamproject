#include "food.h"

#include <iostream>
#include <Windows.h>
using namespace std;


int main() {

	int selnum;
	
	Boss b_kh("김천", "1111", 0);
	Boss b_tk("더큰", "2222", 0);
	//Boss b_hd("핫도그", "3333", 0);
	// 사장 2개 메뉴랑 상태까지 해서 다 생성해놓기.


	//각자 메뉴랑 상태 넣어주는 함수들.

	Login login;
	
	while (1) {

		//아이디 로그인 할지 만들지.
		cout << "What do you want to do? Select a number." << endl;
		cout << "1. Make new account" << endl << "2. Login" << endl;
		cin >> selnum;
		switch (selnum) {
		case 1:
			// 새로 계정 만들어 주는 거 
			break;
		case 2:
			// 로그인 하는 과정
			Person * using_user = login.check_ID();


			//고객 사장 구분해주기
			if (using_user->get_type == 0) {
				cout << "Hello, Customer!  Your ID is " << using_user->get_ID() << endl;
				while (1) {
					//로그인 한 user가 고객인 경우
					cout << "What restaurant do you want? Select a number." << endl;
					cout << "0. Logout" << "1. 더큰도시락" << endl << "2. 김밥천국" << endl << "3. 핫도그집 이름 모름" << endl;

					////////////////////////////////////////////////////////

					//가게 추가할 경우 그 가게는 어떻게 하지?

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

					//고객 종료하는 
					break;
				}

			}
			else { 
				//사장일 경우의 switch
				; }

		}



		break; // 프로그램 종료하는 break
	}

	
}