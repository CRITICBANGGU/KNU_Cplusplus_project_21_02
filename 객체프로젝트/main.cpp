#include <iostream>
#include <vector>

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

void first_screan() {
	char orderType;
	cout << "=========Mc Donalds==========" << endl;
	cout << "=  1.�԰� ������(For Here)  =" << endl
		<< "=  2.����������(To Go)    =" << endl;
	cout << "=============================\n";
	cin >> orderType;
}

char menu_screen() {
	char menu;
	cout << "===================================\n";
	cout << "=1.��õ�޴� 2.���� 3.ġŲ 4.���̵�=" << endl;
	cout << "===================================\n";
	cin >> menu;

	return menu;
}

class Result {
public:
	vector <string> order_list;
	void push_list(string menu) {
		order_list.push_back(menu);
	}
	//�Լ� �����ε�
	void result(string onlyorder) {
		cout << "=======�ֹ������Դϴ�=======\n";
		cout << onlyorder;
	}

	//���ͻ��
	void result(vector<string>& list) {

		cout << "=======�ֹ������Դϴ�=======\n";
		for (string b : list) {
			cout << b << "/\n";
		}
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
	//Ŭ���� ������� ���
	Result result;
	vector <string> order_list;

	//���� ���(�����޴�)
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
			result.push_list(beef[rand_menu_ch[num - 1]]);
			return beef[rand_menu_ch[num - 1]];
		}
		else {
			result.push_list(chicken[rand_menu_ch[num - 1]]);
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
		result.push_list(beef[num - 1]);
		return beef[num - 1];
	}

	string Chicken_menu() {
		int num;
		for (int n = 0; n < ARR_SIZE; n++) {
			cout << n + 1 << ". " << chicken[n] << ' ';
		}
		cout << endl;
		cin >> num;
		result.push_list(chicken[num - 1]);
		return chicken[num - 1];
	}

	string Side_menu() {
		int num;
		for (int n = 0; n < ARR_SIZE; n++) {
			cout << n + 1 << ". " << side[n] << ' ';
		}
		cout << endl;
		cin >> num;
		result.push_list(side[num - 1]);
		return side[num - 1];
	}

	char add_order() {
		char YN;
		cout << "�߰��ֹ� �Ͻðڽ��ϱ�?(y/n) ";
		cin >> YN;
		return YN;
	}
};


class Init {
public:
	char menu_type;
	char continue_order = 'y';
	string main_menu = "";
	string side_menu = "";

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
	Result result;
	Init init;

	init.init();
	first_screan();
	init.menu_type = menu_screen();
	while (init.continue_order == 'y')
	{
		switch (init.menu_type)
		{
		case '1':
			init.main_menu = order.Rand_menu();
			cout << init.main_menu << endl;
			init.continue_order = order.add_order();
			if (init.continue_order == 'y') {
				init.menu_type = menu_screen();
				init.init(init.continue_order);
			}
			break;
		case '2':
			init.main_menu = order.Beef_menu();
			cout << init.main_menu << endl;
			init.continue_order = order.add_order();
			if (init.continue_order == 'y') {
				init.menu_type = menu_screen();
				init.init(init.continue_order);
			}
			break;
		case '3':
			init.main_menu = order.Chicken_menu();
			cout << init.main_menu<<endl;
			init.continue_order = order.add_order();
			if (init.continue_order == 'y') {
				init.menu_type = menu_screen();
				init.init(init.continue_order);
			}
			break;
		case '4':
			init.side_menu = order.Side_menu();
			cout << init.side_menu << endl;
			init.continue_order = order.add_order();
			if (init.continue_order == 'y') {
				init.menu_type = menu_screen();
				init.init(init.continue_order);
			}
			break;
		default:
			break;
		}
	}
	if (init.main_menu == "") {
		result.result(init.side_menu);
	}
	else if (init.side_menu == "") {
		result.result(init.main_menu);
	}
	else {
		result.result(order.result.order_list);
	}
}