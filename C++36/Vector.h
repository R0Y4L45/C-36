#pragma once



class Vector
{
	int* _array = nullptr;
	size_t _size = 0;
	size_t _capacity = 4;
public:

#pragma region Ctor

	Vector()
	{
		_array = new int[_capacity];
	}

	Vector(size_t capacity)
	{
		assert(capacity > 0);

		_capacity = capacity;
		_array = new int[_capacity];
	}


	Vector(const Vector& other)
	{
		_capacity = other._capacity;
		_size = other._size;

		_array = new int[other._capacity];

		for (size_t i = 0; i < other._size; i++)
			_array[i] = other._array[i];
	}

#pragma endregion


	void push_back(int element)
	{
		if (_size < _capacity)
		{
			_array[_size++] = element;
			return;
		}


		_capacity *= 2;
		int* temp = new int[_capacity];

		for (size_t i = 0; i < _size; i++)
			temp[i] = _array[i];

		temp[_size++] = element;

		delete[] _array;
		_array = temp;
	}


	void push_front(const int value)
	{
		if (_size < _capacity)
		{
			int* temp = new int[_capacity];
			temp[0] = value;
			for (size_t i = 0,k = 1; i < _size; i++)
				temp[k++] = _array[i];

			delete[] _array;  
			_array = temp;
			_size++;
			return;
		}

		_capacity *= 2;
		int* temp = new int[_capacity]; 
		temp[0] = value;
		for (size_t i = 0, k = 1; i < _size; i++)
			temp[k++] = _array[i];

		delete[] _array;
		_size++;
		_array = temp;
	}



	void pop_back()
	{
		int* temp = new int[_capacity];
		_size--;
		for (size_t i = 0; i < _size; i++)
			temp[i] = _array[i];

		delete[] _array;
		_array = temp;
	}


	void pop_front()
	{
		int* temp = new int[_capacity];
		for (size_t i = 1, k = 0; i < _size; i++)
			temp[k++] = _array[i];
		_size--;
		delete[] _array;
		_array = temp;
	}


	void delete_by_index(const size_t index)
	{
		bool isExist = false;
		int* temp = new int[_capacity];
		for (size_t i = 0, k = 0; i < _size; i++)
		{
			if (i != index)
				temp[k++] = _array[i];
			else
				isExist = true;
		}

		if (!isExist)
		{
			cout << "There is no such index....(\n";
			return;
		}

		delete[] _array;
		_array = temp;
		_size--;
	}


	void insert_by_index(const size_t index, const int element)
	{
		bool checker = false;
		if (index >= 0 && index <= _size)
		{
			if ((_size + 1) < _capacity)
			{
				int* temp = new int[_capacity];

				for (size_t i = 0, k = 0; i < _size; i++)
				{
					if (k == index)
						temp[k++] = element;

					temp[k++] = _array[i];
				}

				if (index == _size)
					temp[index] = element;

				delete[] _array;
				_array = temp;
				_size++;
				return;
			}

			_capacity *= 2;
			int* temp = new int[_capacity];

			for (size_t i = 0, k = 0; i < _size; i++)
			{
				if (k == index)
					temp[k++] = element;

				temp[k++] = _array[i];
			}

			if (index == _size)
				temp[index] = element;

			delete[] _array;
			_array = temp;
			_size++;
		}
		else
			cout << "Index bigger or smaller than size...\n";
	}


	void print()
	{
		for (size_t i = 0; i < _size; i++)
			cout << _array[i] << ' ';
		cout << endl;
	}


	void operator()() {
		for (size_t i = 0; i < _size; i++)
			cout << _array[i] << ' ';
		cout << endl;
	}





	size_t size() const { return _size; }
	size_t capacity() const { return _capacity; }



	// tapsa index - ni qaytarsin,
		// tapmasa -1 (unsigned int-in max qiymeti qayidacaq)
	size_t find(const int element)
	{
		for (size_t i = 0; i < _size; i++)
			if (_array[i] == element)
				return i;

		return -1;
	}


	size_t rfind(const int element)
	{
		for (size_t i = _size; i != -1 ; i--)
			if (_array[i] == element)
				return i;

		return -1;
	}
	// reverse true gonderilse, tersine sort olunsun.
	void sort(bool reverse = false)
	{
		if (reverse)
		{
			int* temp = new int[_capacity];

			for (size_t i = _size - 1, k = 0; i != -1 ; i--)
				temp[k++] = _array[i];

			delete[] _array;
			_array = temp;
		}
	}



	int operator[](size_t index) {
		if (!(index >= 0 && index < _size))
			assert(!"Index out of range");

		return _array[index];
	}




	// Prefix

	Vector& operator++()
	{
		for (size_t i = 0; i < _size; i++)
			++_array[i];

		return *this;
	}


	Vector& operator--()
	{
		for (size_t i = 0; i < _size; i++)
			--_array[i];

		return *this;
	}





	// Postfix

	Vector operator++(int)
	{
		Vector temp = *this;

		for (size_t i = 0; i < _size; i++)
			_array[i]++;

		return temp;
	}


	Vector operator--(int)
	{
		Vector temp = *this;

		for (size_t i = 0; i < _size; i++)
			_array[i]--;

		return temp;
	}





	//// Type conversion

	operator int()
	{
		int sum = 0;

		for (size_t i = 0; i < _size; i++)
			sum += _array[i];

		return sum;
	}


	operator bool()
	{
		return _size;
	}



	~Vector()
	{
		delete[] _array;
	}
};

