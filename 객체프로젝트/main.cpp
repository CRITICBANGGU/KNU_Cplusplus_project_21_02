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

//Ŭ���� ����
class Order {
	string beef[ARR_SIZE] = { "1955����","������ �丶�� �𷰽�","���","�Ұ�� ����","���� ���� �Ŀ��ġ��" };
	string chicken[ARR_SIZE] = { "�ƽ����̽� ������ ����","���Ͼ� ����","��ġŲ ��¥����","�������","��������" };
	string side[ARR_SIZE] = { "�ķ�ġ �Ķ���", "������","��������","�ݶ�", "��������Ʈ" };
public:
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
		cout << "�߰��ֹ� �Ͻðڽ��ϱ�?(y/n) ";
		cin >> YN;
		return YN;
	}
};


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

int main() {
	//Ŭ���� ��ü����
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