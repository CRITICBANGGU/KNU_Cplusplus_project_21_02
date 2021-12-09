#include <iostream>
#include <vector>

#define ARR_SIZE 5

using namespace std;
//===================실습 1====================
//1주차 : 기본 입출력함수 cout, cin/ 난수 설정
//2주차 : 함수 선언 및 사용/ 함수 오버로딩
//3주차 : 참조자
//4주차 : 벡터

//===================실습 2====================
//5주차 & 6주차 : 클래스 선언 및 사용
void first_screan() {
	char orderType;
	cout << "=========Mc Donalds==========" << endl;
	cout << "=  1.먹고 갈래요(For Here)  =" << endl
		<< "=  2.가지고갈래요(To Go)    =" << endl;
	cout << "=============================\n";
	cin >> orderType;
}

char menu_screen() {
	char menu;
	cout << "===================================\n";
	cout << "=1.추천메뉴 2.비프 3.치킨 4.사이드=" << endl;
	cout << "===================================\n";
	cin >> menu;

	return menu;
}

//클래스 선언
class Order {
	string beef[ARR_SIZE] = { "1955버거","베이컨 토마토 디럭스","빅맥","불고기 버거","더블 쿼터 파운더치즈" };
	string chicken[ARR_SIZE] = { "맥스파이시 상하이 버거","슈니언 버거","맥치킨 모짜렐라","슈비버거","슈슈버거" };
	string side[ARR_SIZE] = { "후렌치 후라이", "스낵랩","애플파이","콜라", "스프라이트" };
public:
	//난수 사용(랜덤메뉴)
	string Rand_menu() {
		int rand_type_ch[ARR_SIZE] = { -1,-1,-1,-1,-1 };
		int rand_menu_ch[ARR_SIZE] = { 0, };
		char ch_rand_num = 5;
		char ch;
		int num;
		for (int n = 0; n < ch_rand_num; n++) {
			char rand_num = rand() % ARR_SIZE;

			if (rand_num % 2 == 0) {
				ch = rand_num;
				cout << n + 1 << ". " << beef[rand_num] << endl;
				rand_type_ch[n] = 1;
				rand_menu_ch[n] = rand_num;
			}
			else {
				cout << n + 1 << ". " << chicken[rand_num] << endl;
				rand_type_ch[n] = 0;
				rand_menu_ch[n] = rand_num;
			}

		}
		cin >> num;
		if (rand_type_ch[num - 1] == 1) {
			return beef[rand_menu_ch[num - 1]];
		}
		else {
			return chicken[rand_menu_ch[num - 1]];
		}
	}

	string Beef_menu() {
		int num;
		for (int n = 0; n < ARR_SIZE; n++) {
			cout << n + 1 << ". " << beef[n] << ' ';
		}
		cout << endl;
		cin >> num;
		return beef[num - 1];
	}

	string Chicken_menu() {
		int num;
		for (int n = 0; n < ARR_SIZE; n++) {
			cout << n + 1 << ". " << chicken[n] << ' ';
		}
		cout << endl;
		cin >> num;
		return chicken[num - 1];
	}

	string Side_menu() {
		int num;
		for (int n = 0; n < ARR_SIZE; n++) {
			cout << n + 1 << ". " << side[n] << ' ';
		}
		cout << endl;
		cin >> num;
		return side[num - 1];
	}

	char add_order() {
		char YN;
		cout << "추가주문 하시겠습니까?(y/n) ";
		cin >> YN;
		return YN;
	}
};


//함수 오버로딩
void result(string onlyorder) {
	cout << "=======주문내역입니다=======\n";
	cout << onlyorder;
}

//벡터사용
void result(vector<string>& list) {

	cout << "=======주문내역입니다=======\n";
	for (string b : list) {
		cout << b << "/\n";
	}
}
//void result_screen(string side) {
//	cout << "=======주문내역입니다=======\n"
//		<< " 사이드메뉴 :" << side;
//}

int main() {
	//클래스 객체선언
	Order order;
	char menu_type;
	char continue_order = 'y';
	string main_menu = "";
	string side_menu = "";
	vector <string> order_list;
	first_screan();
	menu_type = menu_screen();
	while (continue_order == 'y')
	{
		switch (menu_type)
		{
		case '1':
			main_menu = order.Rand_menu();
			cout << main_menu;
			order_list.push_back(main_menu);
			continue_order = order.add_order();
			if (continue_order == 'y') {
				menu_type = menu_screen();
				main_menu = "+";
				side_menu = "+";
			}
			break;
		case '2':
			main_menu = order.Beef_menu();
			cout << main_menu;
			order_list.push_back(main_menu);
			continue_order = order.add_order();
			if (continue_order == 'y') {
				menu_type = menu_screen();
				main_menu = "+";
				side_menu = "+";
			}
			break;
		case '3':
			main_menu = order.Chicken_menu();
			cout << main_menu;
			order_list.push_back(main_menu);
			continue_order = order.add_order();
			if (continue_order == 'y') {
				menu_type = menu_screen();
				main_menu = "+";
				side_menu = "+";
			}
			break;
		case '4':
			side_menu = order.Side_menu();
			cout << side_menu;
			order_list.push_back(side_menu);
			continue_order = order.add_order();
			if (continue_order == 'y') {
				menu_type = menu_screen();
				main_menu = "+";
				side_menu = "+";
			}
			break;
		default:
			break;
		}
	}
	if (main_menu == "") {
		result(side_menu);
	}
	else if (side_menu == "") {
		result(main_menu);
	}
	else {
		result(order_list);
	}
}