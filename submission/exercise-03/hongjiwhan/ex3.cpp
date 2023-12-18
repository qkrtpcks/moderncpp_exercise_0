#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int soinsu(int a, int b) {
	int c = 0;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {

	/*�� ���ǥ����(constexpr) �ڿ��� a, b �� �־�������, 
	�̵��� �ִ������� ������ �ð��� ���ϴ� ������ �ۼ��ϼ���
	constexpr �Լ� / ���ø� Ư��ȭ �� ��� ��η� �����մϴ�*/

	static_assert(soinsu(192, 72) == 24, "");

	return 0;
}