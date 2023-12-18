#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int main() {
	std::list<int> numbers;
	int value;

	cout << "���� 10�� �Է��ϱ� : " << endl;

	for (int i = 0; i < 10; ++i)
	{
		cin >> value;
		numbers.push_back(value);
	}


	numbers.sort();


	int a, b;
	cout << "0�� 10������ �� �ֱ� : " << endl;
	cin >> a >> b;

	int smaller = min(a, b);
	int larger = max(a, b);

	auto it_a = numbers.begin();
	advance(it_a, smaller);
	auto it_b = numbers.begin();
	advance(it_b, larger);

	numbers.erase(it_a, it_b);

	cout << "��� : " << endl;
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	//cout << endl;
	return 0;
}
