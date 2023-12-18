
template<typename T>
class MyVector {
public:
	// �⺻ ������
	MyVector()
		: data_(nullptr),
		capacity_(3),
		size_(0)
	{
		data_ = new T[capacity_];
	}

	// ���� ������
	MyVector(const MyVector& other)
		: capacity_(other.capacity_),
		size_(other.size_)
	{
		// �޸� �Ҵ�
		data_ = new T[capacity_];

		// �迭�� ���� ����
		std::copy(other.data_, other.data_ + other.size_, data_);
	}

	// ���� ���� ������
	MyVector& operator=(const MyVector& other) {
		capacity_ = other.capacity_;
		size_ = other.size_;
		// ������ �޸� ����
		delete[] data_;

		// �޸� ���� �Ҵ�
		data_ = new T[capacity_];

		// �迭�� ���� ����
		std::copy(other.data_, other.data_ + other.size_, data_);
	}

	// �̵� ������
	MyVector(MyVector&& other) noexcept // ���ܸ� ������ ����!
		: capacity_(other.capacity_),
		size_(other.size_),
		data_(other.data_)
	{
		other.data_ = nullptr;
		other.size_ = 0;
		other.capacity_ = 0;
	}

	// �̵� ���� ������
	MyVector& operator=(MyVector&& other) noexcept {
		capacity_ = other.capacity_;
		size_ = other.size_;
		// ���� �޸� ����
		delete[] data_;
		data_ = other.data_;

		other.data_ = nullptr;
		other.size_ = 0;
		other.capacity_ = 0;
	}

	// {1, 2, 3, 4} �� ���� �����ϰ� ��
	MyVector(std::initializer_list<T> il)
		: size_(il.size()),
		capacity_(il.size() * 2),
		data_(nullptr)
	{
		data_ = new T[capacity_];
		std::copy(il.begin(), il.end(), data_);
	}

	// �Ҹ���
	~MyVector() {
		// �޸� ����
		delete[] data_;
	}

	// ���� ���� ����
	void push_back(const T& data) {
		increase_if_needed();

		data_[size_] = data;
		size_ += 1;
	}

	// ���� ���� ����
	// Perfect forwarding
	template<typename... T>
	void emplace_back(T&&... args) {
		increase_if_needed();

		data_[size_] = T(std::forward<T>(args)...);
		size_ += 1;
	}

	// �ϳ� ����(�䳻��)
	void pop_back() {
		if (size_ > 0) {
			size_ -= 1;
		}
	}

	// ���� �迭�� ũ�� ��ȯ
	std::size_t size() const {
		return size_;
	}

	// ���� ����
	// non-const lvalue ��ü�� ȣ�� ����
	T& operator[](std::size_t index)& {
		return data_[index];
	}

	// ���� ����
	// lvalue ��ü�� ȣ�� ����
	const T& operator[](std::size_t index) const& {
		return data_[index];
	}

	// ���� ����
	// non-const rvalue ��ü�� ȣ�� ����
	T&& operator[](std::size_t index)&& {
		return std::move(data_[index]);
	}

	// ó���� �ǹ��ϴ� iterator ��ȯ
	T* begin() {
		return data_;
	}

	const T* begin() const {
		return data_;
	}


	// ���� �ǹ��ϴ� iterator ��ȯ
	T* end() {
		return data_ + size_;
	}

	const T* end() const {
		return data_ + size_;
	}

private:
	void increase_if_needed() {
		if (size_ >= capacity_) {
			// �뷮 �ø���
			capacity_ = capacity_ * 2;

			// �޸� ���� �Ҵ�
			T* new_data = new T[capacity_];

			// ���� ������ ����
			std::copy(data_, data_ + size_, new_data);

			// ���� �޸� ����
			delete[] data_;

			// ���� ������ ��ü
			data_ = new_data;
		}
	}

	T* data_;
	std::size_t capacity_;
	std::size_t size_;
};