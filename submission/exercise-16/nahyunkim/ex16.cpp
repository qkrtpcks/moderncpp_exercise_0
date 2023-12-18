#include <thread>
#include <iostream>
#include <atomic>
#include <mutex>
#include <chrono>
std::atomic<int> x1(0);
int x2 = 0;
std::mutex x2_mutex;
int y = 0;
void Async();
void solution1();
void solution2();


int main() {

	//�����϶� ������ ����� 200,000,000�� ������ �ʴ´�.
	//th1�� th2�� ���ÿ� ����Ǳ� ������
	std::cout << "Aync:";
	Async();

	//atomic�� ���� �ذ�
	std::cout << "Atomic: ";

	solution1();

	//���ؽ��� ���� �ذ�
	std::cout << "Mutex: ";

	solution2();

	exit(0);


}

void solution1() { // atomic�� ���� �ذ�
	std::thread th1([&] {
		for (int i = 0; i < 100'000'000; ++i) {
			x1.fetch_add(1, std::memory_order_relaxed);
		}
		});

	std::thread th2([&] {for (int i = 0; i < 100'000'000; ++i) {
		x1.fetch_add(1, std::memory_order_relaxed);
	}});

	th1.join();
	th2.join();

	std::cout << x1 << '\n';
	auto _time = std::chrono::steady_clock::now();
	
	auto time_point = std::chrono::duration_cast<std::chrono::milliseconds>(_time.time_since_epoch());

	std::cout << "atomic time(ms): " << time_point.count() << '\n';

	
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

	
}


void solution2() { // ���ؽ� Ȱ��

	std::thread t1 = std::thread([&] {
		for (int i = 0; i < 100'000'000; ++i) {
		
			{
				std::lock_guard<std::mutex> lock(x2_mutex);
				x2++;
			}
			
			 
		}
		});

	std::thread t2 = std::thread([&] {
		for (int i = 0; i < 100'000'000; ++i) {
			{
			std::lock_guard<std::mutex> lock(x2_mutex);
			x2++; }
		}
		});

	t1.join();
	t2.join();

	if (t1.joinable()) {
		t1.join();
	}

	if (t2.joinable()) {
		t2.join();
	}
	std::cout << x2 << '\n';
	auto _time = std::chrono::steady_clock::now();

	auto time_point = std::chrono::duration_cast<std::chrono::milliseconds>(_time.time_since_epoch());

	std::cout << "mutex time(ms): " << time_point.count() << '\n';


	
}

