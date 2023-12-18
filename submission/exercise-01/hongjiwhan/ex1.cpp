//����ڷκ��� ���� 10���� �Է¹޾� std::list�� ���ʴ�� ���� �մϴ�
//
//0 ���� 10 ������ ���� 2���� �߰��� �Է¹ް� �� ���� �� ���� ���� a, ū ���� b �� ����
//
//��, ���ǹ�(if, ���׿�����)�� ����ؼ��� �ȵ˴ϴ�
//
//std::list��[a, b) ������ ����ϴ�
//
//std::list �� ��� �Ѵ�
//
//for ���� ����ؼ��� �ȵ˴ϴ�.

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main() {

	list<int> num_list;

	for (int i = 0; i < 10; i++) {
		int temp;
		cin >> temp;
		num_list.push_back(temp);
	}

	int a, b;
	cin >> a >> b;

	num_list.erase(find(num_list.begin(), num_list.end(), a), find(num_list.begin(), num_list.end(), b));

	for (auto it : num_list) {
		cout << it << " ";
	}

	return 0;
}