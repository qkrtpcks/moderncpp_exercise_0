#include <thread>
#include <iostream>
int y=0;
void Async();

int main() {

	//�����϶� ������ ����� 200,000,000�� ������ �ʴ´�.
	//th1�� th2�� ���ÿ� ����Ǳ� ������
	Async();
			
}


void Async() {
	std::thread t1 = std::thread([&] {
		for (int i = 0; i < 100'000'000; ++i) {
			++y;
		}
		});

	std::thread t2 = std::thread([&] {
		for (int i = 0; i < 100'000'000; ++i) {
			++y;
		}
		});

	t1.join();
	t2.join(); // ���� ������ ���� t1,t2 �����带 �����Ű���ʴ´�.

	if (t1.joinable()) {
		t1.join();
	}

	if (t2.joinable()) {
		t2.join();
	}

	std::cout << y << '\n';

	exit(0);
}


