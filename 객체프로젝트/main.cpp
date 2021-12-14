#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#define ARR_SIZE 5

using namespace std;
//===================실습 1====================
//1주차 : 기본 입출력함수 cout, cin/ 난수 설정
//2주차 : 함수 선언 및 사용/ 함수 오버로딩
//3주차 : 참조자
//4주차 : 벡터

//===================실습 2====================
//5주차 & 6주차 : 클래스 선언 및 사용

//===================실습 3====================
//7주차 & 8주차 &9주차 : 연개 클래스 선언 및 사용(멤버변수로 사용)

//===================실습 4====================
//10주차 & 11주차 &12주차 : 클래스 객체에 대해 벡터형(line_116) & 
//							포인터형(line_239) & 배열형(line_225,line_304) & 
//							멤버변수 사용(line_118등) 총 4가지 ver  

//===================실습 5====================
//13주차 : 파일 읽기

//===================실습 6====================
//14주차 & 15주차 : 프로그램 수정 및 완성

//파일 읽기 클래스 선언
class Getfile {
	ifstream inf;
	string menu[3];
public:
	Getfile() :inf("menu.txt") {};
	void dbRead() {
		int i = 0;
		while (!inf.eof())
		{
			getline(inf, menu[i]);
			i++;
		}
	}
	void display(int k) {
		cout << menu[k - 1];
	}
};

class Screen {
public:
	int first_screan() {
		int orderType;
		cout << "=========Mc Donalds==========" << endl;
		cout << "=  1.먹고 갈래요(For Here)  =" << endl
			<< "=  2.가지고갈래요(To Go)    =" << endl;
		cout << "=============================\n";
		cin >> orderType;
		
		return orderType;
	}

	char menu_screen() {
		char menu;
		cout << "===================================\n";
		cout << "=1.추천메뉴 2.비프 3.치킨 4.사이드=" << endl;
		cout << "===================================\n";
		cin >> menu;

		return menu;
	}
};

class Result {
	int i = 1;
public:
	Result() {}
	Result(vector <string> &list) {
		this->order_list = list;
	}
	vector <string> order_list;
	int num = 0;
	void push_list(vector <string>& list) {
	}

	//함수 오버로딩
	void result(string onlyorder) {
		cout << "=======주문내역입니다=======\n";
		cout << onlyorder;
		num++;
		onlyorder += "\n";
		order_list.push_back(onlyorder);
		//order_list.push_back("\n");
		cout << "\n============================\n";
	}

	//벡터사용
	void result(vector<string>& list) {

		cout << "\n=======주문내역입니다=======\n";
		for (string b : list) {
			cout << b << "/\n";
			//b += ' ';
			order_list.push_back(b);
		}
		string laststring = (order_list.back())+"\n";
		order_list.pop_back();
		order_list.push_back(laststring);
		cout << "\n==============================\n";
		//order_list.push_back("\n");
		num++;

	}

	void outvector() {
		for (vector<string>::iterator iter = order_list.begin(); iter != order_list.end(); ++iter)
		{
			cout << *iter << " ";
		}
	}
	void printVector(ofstream &out, string YMD,int i) {
		out << ' ' << i+1 << ". ";
		for (vector<string>::iterator iter = order_list.begin(); iter != order_list.end(); ++iter)
		{	
			out << *iter;
		}
	}
};

//클래스 선언
class Order {
	string beef[ARR_SIZE] = { "1955버거","베이컨 토마토 디럭스","빅맥","불고기 버거","더블 쿼터 파운더치즈" };
	string chicken[ARR_SIZE] = { "맥스파이시 상하이 버거","슈니언 버거","맥치킨 모짜렐라","슈비버거","슈슈버거" };
	string side[ARR_SIZE] = { "후렌치 후라이", "스낵랩","애플파이","콜라", "스프라이트" };
public:
	//클래스 객체에 대한 벡터형 사용
	vector <Result> result;
	//클래스 멤버변수 사용
	vector <string> order_list;
	
	Getfile db; 
	//난수 사용(랜덤메뉴)
	string Rand_menu(int k) {
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
			order_list.push_back(beef[rand_menu_ch[num - 1]]);
			return beef[rand_menu_ch[num - 1]];
		}
		else {
			order_list.push_back(chicken[rand_menu_ch[num - 1]]);
			return chicken[rand_menu_ch[num - 1]];
		}
	}

	string Beef_menu(int k) {
		db.dbRead();
		db.display(1);
		int num;
		cout << endl;
		cin >> num;
		order_list.push_back(beef[num - 1]);
		return beef[num - 1];
	}

	string Chicken_menu(int k) {
		db.dbRead();
		db.display(2);
		int num;
		cout << endl;
		cin >> num;
		order_list.push_back(chicken[num - 1]);
		return chicken[num - 1];
	}

	string Side_menu(int k) {
		db.dbRead();
		db.display(3);
		int num;
		cout << endl;
		cin >> num;
		order_list.push_back(side[num - 1]);
		return side[num - 1];
	}

	char add_order() {
		char YN;
		cout << "추가주문 하시겠습니까?(y/n) ";
		cin >> YN;
		if (YN == 'n') {
			result.push_back(Result(order_list));
		}
		return YN;
	}
};


class Init {
public:
	char menu_type;
	char continue_order = 'y';
	string main_menu = "";
	string side_menu = "";
	int admin = 0;

	//함수 오버로딩
	void init() {
		continue_order = 'y';
		main_menu = "";
		side_menu = "";
	}
	void init(char y) {
		main_menu = "+";
		side_menu = "+";
	}
};

int main() {
	//클래스 객체선언
	Order order;
	//클래스 객체에 대해 배열 선언
	Result result[100];
	Init init;
	Screen screen; 
	ofstream outf;
	int num = 0;
	int adminOrhereOrgo = 0;
	char modify;

	while (true)
	{
		init.init();
		
		adminOrhereOrgo = screen.first_screan();
		if (adminOrhereOrgo == 1122) {
			cout << "관리자 모드 접속 성공\n";
			//클래스 객체의 포인터형
			Result* p;
			p = result;
			cout << "\n===오늘 총 주문내역입니다===\n";
			for (int i = 0; i < num; i++) {
				p->outvector();
				p++;
			}
			p -= num;
			cout << "출력할까요?(y/n)\n";
			cin >> modify;
			if (modify == 'y') {
				time_t tnow;
				struct tm* t;
				time(&tnow);
				t = (struct tm*)localtime(&tnow);
				int year = (t->tm_year) + 1900;
				int month = (t->tm_mon) + 1;
				int date = (t->tm_mday);
				string YMD = to_string(year) + to_string(month) + to_string(date) + "_매출현황.txt";
				ofstream outF(YMD);
				for (int i = 0; i < num; i++) {
					p->printVector(outF,YMD,i);
					p++;
				}
				outF.close();
			}
			p -= num;
		}
		else {
			init.menu_type = screen.menu_screen(); 
			while (init.continue_order == 'y')
			{
				switch (init.menu_type)
				{
				case '1':
					init.main_menu = order.Rand_menu(num);
					cout << init.main_menu << endl;
					init.continue_order = order.add_order();
					if (init.continue_order == 'y') {
						init.menu_type = screen.menu_screen();
						init.init(init.continue_order);
					}
					break;
				case '2':
					init.main_menu = order.Beef_menu(num);
					cout << init.main_menu << endl;
					init.continue_order = order.add_order();
					if (init.continue_order == 'y') {
						init.menu_type = screen.menu_screen();
						init.init(init.continue_order);
					}
					break;
				case '3':
					init.main_menu = order.Chicken_menu(num);
					cout << init.main_menu << endl;
					init.continue_order = order.add_order();
					if (init.continue_order == 'y') {
						init.menu_type = screen.menu_screen();
						init.init(init.continue_order);
					}
					break;
				case '4':
					init.side_menu = order.Side_menu(num);
					cout << init.side_menu << endl;
					init.continue_order = order.add_order();
					if (init.continue_order == 'y') {
						init.menu_type = screen.menu_screen();
						init.init(init.continue_order);
					}
					break;
				default:
					break;
				}
			}
			//객체 배열 사용
			if (init.main_menu == "") {
				result[num].result(init.side_menu);
				order.order_list.clear();
			}
			else if (init.side_menu == "") {
				result[num].result(init.main_menu);
				order.order_list.clear();
			}
			else {
				result[num].result(order.order_list);
				order.order_list.clear();
			}
			num++;
		}
	}
	
}