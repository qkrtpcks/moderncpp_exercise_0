#include <iostream>
#include <memory>

#ifdef _MSC_VER
#define MY_FUNCTION __FUNCSIG__ 
#else
#define MY_FUNCTION __PRETTY_FUNCTION__
#endif
int default_constructor_count = 0;
int copy_constructor_count = 0;
int move_constructor_count = 0;
int copy_assignment_operator_count = 0;
int move_signment_operator_count = 0;
int desturctor_count = 0;

class MyApplication {
public:
	MyApplication() {
		default_constructor_count += 1;
		std::cout << MY_FUNCTION << '\n';
	}

	MyApplication(const MyApplication&) {
		copy_constructor_count += 1;
		std::cout << MY_FUNCTION << '\n';
	}

	MyApplication(MyApplication&&) noexcept {
		move_constructor_count += 1;
		std::cout << MY_FUNCTION << '\n';
	}

	MyApplication& operator=(const MyApplication&) {
		copy_assignment_operator_count += 1;
		std::cout << MY_FUNCTION << '\n';
		return *this;
	}

	MyApplication& operator=(MyApplication&&) noexcept {
		move_signment_operator_count += 1;
		std::cout << MY_FUNCTION << '\n';
		return *this;
	}

	~MyApplication() {
		desturctor_count += 1;
		std::cout << MY_FUNCTION << '\n';
	}
};

void TestUniquePtr() {
	// MyApplication ����
	auto p = std::make_unique<MyApplication>();

	// MyApplication �̵�
	auto p2 = std::move(p);
}

void TestSharedPtr() {
	// MyApplication ����
	auto p = std::make_shared<MyApplication>();

	// ? //����� ���ÿ� �ʱ�ȭ ��
	//shared_ptr�� ���� ������ ȣ��
	
	auto p2 = p;

	// p2 �ʱ�ȭ
	p2.reset();

	// ? // ���� ���� ��ü 
	std::weak_ptr<MyApplication> weak_p = p;

	auto lock = weak_p.lock();
	if (lock) {
		std::cout << "Acquired ownership\n";
	}
}

int main() {

	//MyApplication my_app;
	TestUniquePtr();
	//TestSharedPtr();
	std::cout << "�⺻ ������ ȣ�� Ƚ��: " << default_constructor_count << '\n';
	std::cout << "���� ������ ȣ�� Ƚ��: " << copy_constructor_count << '\n';
	std::cout << "�̵� ������ ȣ�� Ƚ��: " << move_constructor_count << '\n';
	std::cout << "���� ���� ������ ȣ�� Ƚ��: " << copy_assignment_operator_count << '\n';
	std::cout << "�̵� ���� ������ ȣ�� Ƚ��: " << move_signment_operator_count << '\n';
	std::cout << "�Ҹ��� ȣ�� Ƚ��: " << desturctor_count << '\n';

	//TestUniquePtr();
	TestSharedPtr();
	std::cout << "�⺻ ������ ȣ�� Ƚ��: " << default_constructor_count << '\n';
	std::cout << "���� ������ ȣ�� Ƚ��: " << copy_constructor_count << '\n';
	std::cout << "�̵� ������ ȣ�� Ƚ��: " << move_constructor_count << '\n';
	std::cout << "���� ���� ������ ȣ�� Ƚ��: " << copy_assignment_operator_count << '\n';
	std::cout << "�̵� ���� ������ ȣ�� Ƚ��: " << move_signment_operator_count << '\n';
	std::cout << "�Ҹ��� ȣ�� Ƚ��: " << desturctor_count << '\n';


	return 0;
}