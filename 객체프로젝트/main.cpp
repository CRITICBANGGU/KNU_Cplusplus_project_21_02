#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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

	void modify_screen() {
		char modify;
		int num;
		cout << "�����Ͻðڽ��ϱ�?(y/n)\n";
		cin >> modify;
		if (modify == 'y') {
			cout << "���° �����Ͻðڽ��ϱ�?\n";
			cin >> num;
		}
	}
};

class Result {
public:
	Result() {}
	Result(string name) {
		push_list(name);
	}
	vector <string> order_list;
	int num = 0;
	void push_list(string menu) {
		order_list.push_back(menu);
	}

	//�Լ� �����ε�
	void result(string onlyorder) {
		cout << "=======�ֹ������Դϴ�=======\n";
		cout << onlyorder;
		num++;
		order_list.push_back(onlyorder);
		order_list.push_back("\n");
	}

	//���ͻ��
	void result(vector<string>& list) {

		cout << "=======�ֹ������Դϴ�=======\n";
		for (string b : list) {
			cout << b << "/\n";
			b += ' ';
			order_list.push_back(b);
		}
		order_list.push_back("\n");
		num++;

	}

	void outvector() {
		for (vector<string>::iterator iter = order_list.begin(); iter != order_list.end(); ++iter)
		{
			cout << *iter << " ";
		}
	}

	void result_reset() {
	}
	//void result_screen(string side) {
	//	cout << "=======�ֹ������Դϴ�=======\n"
	//		<< " ���̵�޴� :" << side;
	//}
};

//Ŭ���� ����
class Order {
	string beef[ARR_SIZE] = { "1955����","������ �丶�� �𷰽�","���","�Ұ�� ����","���� ���� �Ŀ��ġ��" };
	string chicken[ARR_SIZE] = { "�ƽ����̽� ������ ����","���Ͼ� ����","��ġŲ ��¥����","�������","��������" };
	string side[ARR_SIZE] = { "�ķ�ġ �Ķ���", "������","��������","�ݶ�", "��������Ʈ" };
	
public:
	//Ŭ���� ��ü�� ���� ������ ���
	vector <Result> result ;
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
			result.push_back(Result(beef[rand_menu_ch[num - 1]]));
			return beef[rand_menu_ch[num - 1]];
		}
		else {
			result.push_back(Result(chicken[rand_menu_ch[num - 1]]));
			return chicken[rand_menu_ch[num - 1]];
		}
	}

	string Beef_menu(int k) {
		db.dbRead();
		db.display(1);
		int num;
		cout << endl;
		cin >> num;
		result.push_back(Result(beef[num - 1]));
		return beef[num - 1];
	}

	string Chicken_menu(int k) {
		db.dbRead();
		db.display(2);
		int num;
		cout << endl;
		cin >> num;
		result.push_back(Result(chicken[num - 1]));
		return chicken[num - 1];
	}

	string Side_menu(int k) {
		db.dbRead();
		db.display(3);
		int num;
		cout << endl;
		cin >> num;
		result[k].push_list(side[num - 1]);
		return side[num - 1];
	}

	char add_order() {
		char YN;
		cout << "�߰��ֹ� �Ͻðڽ��ϱ�?(y/n) ";
		cin >> YN;
		return YN;
	}

	void add_newline(int k) {
		result[k].push_list("\n");
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
	Result result[3];
	Init init;
	Screen screen;
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
			/*cout << "�����Ͻðڽ��ϱ�?(y/n)\n";
			cin >> modify;
			if (modify == 'y') {
				cout << "���° �����Ͻðڽ��ϱ�?\n";
				cin >> num;
				for (int i = 0; i < num; i++) {
					p++;
				}

			}*/
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
			}
			else if (init.side_menu == "") {
				result[num].result(init.main_menu);
			}
			else {
				result[num].result(order.result[num].order_list);
			}
			order.add_newline(num);
			num++;
		}
	}
	
}