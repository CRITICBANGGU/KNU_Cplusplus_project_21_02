#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#define ARR_SIZE 5

using namespace std;
//===================�ǽ� 1====================
//1���� : �⺻ ������Լ� cout, cin/ ���� ����
//2���� : �Լ� ���� �� ���/ �Լ� �����ε�
//3���� : ������
//4���� : ����

//===================�ǽ� 2====================
//5���� & 6���� : Ŭ���� ���� �� ���

//===================�ǽ� 3====================
//7���� & 8���� &9���� : ���� Ŭ���� ���� �� ���(��������� ���)

//===================�ǽ� 4====================
//10���� & 11���� &12���� : Ŭ���� ��ü�� ���� ������(line_116) & 
//							��������(line_239) & �迭��(line_225,line_304) & 
//							������� ���(line_118��) �� 4���� ver  

//===================�ǽ� 5====================
//13���� : ���� �б�

//===================�ǽ� 6====================
//14���� & 15���� : ���α׷� ���� �� �ϼ�

//���� �б� Ŭ���� ����
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
		cout << "=  1.�԰� ������(For Here)  =" << endl
			<< "=  2.����������(To Go)    =" << endl;
		cout << "=============================\n";
		cin >> orderType;
		
		return orderType;
	}

	char menu_screen() {
		char menu;
		cout << "===================================\n";
		cout << "=1.��õ�޴� 2.���� 3.ġŲ 4.���̵�=" << endl;
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

	//�Լ� �����ε�
	void result(string onlyorder) {
		cout << "=======�ֹ������Դϴ�=======\n";
		cout << onlyorder;
		num++;
		onlyorder += "\n";
		order_list.push_back(onlyorder);
		//order_list.push_back("\n");
		cout << "\n============================\n";
	}

	//���ͻ��
	void result(vector<string>& list) {

		cout << "\n=======�ֹ������Դϴ�=======\n";
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

//Ŭ���� ����
class Order {
	string beef[ARR_SIZE] = { "1955����","������ �丶�� �𷰽�","���","�Ұ�� ����","���� ���� �Ŀ��ġ��" };
	string chicken[ARR_SIZE] = { "�ƽ����̽� ������ ����","���Ͼ� ����","��ġŲ ��¥����","�������","��������" };
	string side[ARR_SIZE] = { "�ķ�ġ �Ķ���", "������","��������","�ݶ�", "��������Ʈ" };
public:
	//Ŭ���� ��ü�� ���� ������ ���
	vector <Result> result;
	//Ŭ���� ������� ���
	vector <string> order_list;
	
	Getfile db; 
	//���� ���(�����޴�)
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
		cout << "�߰��ֹ� �Ͻðڽ��ϱ�?(y/n) ";
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

	//�Լ� �����ε�
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
	//Ŭ���� ��ü����
	Order order;
	//Ŭ���� ��ü�� ���� �迭 ����
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
			cout << "������ ��� ���� ����\n";
			//Ŭ���� ��ü�� ��������
			Result* p;
			p = result;
			cout << "\n===���� �� �ֹ������Դϴ�===\n";
			for (int i = 0; i < num; i++) {
				p->outvector();
				p++;
			}
			p -= num;
			cout << "����ұ��?(y/n)\n";
			cin >> modify;
			if (modify == 'y') {
				time_t tnow;
				struct tm* t;
				time(&tnow);
				t = (struct tm*)localtime(&tnow);
				int year = (t->tm_year) + 1900;
				int month = (t->tm_mon) + 1;
				int date = (t->tm_mday);
				string YMD = to_string(year) + to_string(month) + to_string(date) + "_������Ȳ.txt";
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
			//��ü �迭 ���
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