#include <iostream>
#include <thread>

using namespace std;

int x;

int main()
{
	thread th1([&]() {
		for (int i = 0; i < 100000000; i++)
			x++;
		});
	thread th2([&]() {
		for (int i = 0; i < 100000000; i++) 
			x++;
		});

	if (th1.joinable()) 
		th1.join();

	if (th2.joinable()) 
		th2.join();

	cout << x << "\n";

	return 0;
}

/*

����� ���������� �Ͼ�� �ʾ����Ƿ� ������ ����� ��ó�� ������� ����

*/