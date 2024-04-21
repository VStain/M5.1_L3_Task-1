// ������ 1. ����� ������

/*
��������
��� ����� ����������� ����� ������ ��� ������ ���� int � ���� ������ RAII, ������� ��� ��������� ����� �������: �������������� �������� � ��� �������� � �������, ����� ������ ������� ������ �� ������������.

������ ���� ����������� ��������� �������:

- �����������, ���������� ���������� ���������, ������� ����� ������� ������.
- ������� ���������� ������ �������� � ������. �� �������� ���������� ������, ����� ���������� ��������� ������ ���������� ���������, �� ������� �������� ������.
- ������� ��������� �������� �� �������. �� �������� �������� �� ������������ �������.
- ����������.

������ ���������� ������ ���������
������ � ����� ������� ������ ����������� ���:
try {
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);
	arr.add_element(14);
	arr.add_element(15);
	std::cout << arr.get_element(1) << std::endl;
}
catch (const std::exception& ex) {
	std::cout << ex.what() << std::endl;
}
*/

#include <iostream>
#include <stdexcept>

class smart_array
{
private:
	int* data = 0;     // ��������� �� ������ ������
	int size = 0;      // ������ ������� 
	int capacity = 0;  // ����������� �������

	// ���-� ��� ��������� ������
	void allocate_memory()
	{
		data = new int[capacity];
		if (!data)
		{
			throw std::bad_alloc();
		}
	}

	// ���-� ������������ ������
	void deallocate_memory()
	{
		if (data)
		{
			delete[] data;
			data = nullptr;
		}
	}
public:
	// �����������
	explicit smart_array(int initial_size) : size(0), capacity(initial_size)
	{
		allocate_memory();
	}

	// ����������
	~smart_array()
	{
		deallocate_memory();
	}

	// ���-� ���������� ��������
	void add_element(int element)
	{
		if (size == capacity)
		{
			// ����������� ����������� �������, ���� �� ��������
			int new_capacity = capacity * 2;
			int* new_data = new int[new_capacity];
			if (!new_data)
			{
				throw std::bad_alloc();
			}

		   // �������� ������ � ����� ������
		   for (int i = 0; i < size; ++i) {
			new_data[i] = data[i];
		   }

		   // ����������� ������ ������� �������
		   deallocate_memory();

		   // ��������� ������
		   data = new_data;
		   capacity = new_capacity;
		}

		data[size] = element;
		size++;
	}

	// ���-� ��������� �������� �� �������
	int get_element(int index) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("������ ������� �� ������� �������");
		}

		return data[index];
	}

};

	int main() {

		try {
			smart_array arr(5);
			arr.add_element(1);
			arr.add_element(4);
			arr.add_element(155);
			arr.add_element(14);
			arr.add_element(15);
			std::cout << arr.get_element(0) << std::endl;
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
		}

		return 0;
	}