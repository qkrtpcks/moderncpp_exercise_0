#include <iostream>
#include <memory>


class MyBaseClass {
public:
	virtual void Hello() {
		std::cout << "This is Base\n";
	}

	virtual ~MyBaseClass() = default; // �����Լ��� �ϳ��� ������ �Ҹ��ڵ� virtual

};

class MyDerivedClass : public MyBaseClass {
public:
	void Hello() override {
		std::cout << "This is Derived\n";
	}

	virtual ~MyDerivedClass() = default;
};

int main() {
	std::unique_ptr<MyBaseClass> ptr = std::make_unique<MyDerivedClass>();
	ptr->Hello();

	return 0;
}