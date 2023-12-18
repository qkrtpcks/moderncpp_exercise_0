#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

template<typename T>
class MyVector {
public:
    MyVector()
        : data_(nullptr),
        capacity_(3),
        size_(0)
    { 
        data_ = new T[capacity_];
    }

    ~MyVector() { delete[] data_; }

    void push_back (const T& data) {
        if (size_ >= capacity_) {
            // �뷮 �ø���
            capacity_ = capacity_ * 2;
            // �޸� ���� �Ҵ�
            T* new_data = new T[capacity_];

            // ���� ������ ����
            copy(data_, data_ + size_, new_data);

            // ���� �޸� ����
            delete[] data_;

            // ���� ������ ��ü
            data_ = new_data;
        }

        data_[size_] = data;
        size_ += 1; // size_++;
    }

    void pop_back(const T& data) {
        size_ = size_ > 0 ? size_ - 1 : 0;
    }

    /* return-type */ 
    T& operator[](size_t i) { return data_[i]; }

    const T& operator[](size_t i) const { return data_[i]; }

    size_t size() const { return size_; }

private:
    T* data_;
    size_t size_;
    size_t capacity_;
    // Define other member variables if necessary
};


// Use case
int main() {

    {
        MyVector<int> v;

        v.push_back(1); // v.size() == 1
        cout << v.size() << "\n";
        v.push_back(2); // v.size() == 2
        cout << v.size() << "\n";
        v.push_back(3); // v.size() == 3
        cout << v.size() << "\n";
        v.push_back(4); // v.size() == 4
        cout << v.size() << "\n";
        v.push_back(5); // v.size() == 5
        cout << v.size() << "\n";
    } // v �Ҹ�


    return 0;
}