// Задача 1. Умный массив

/*
Описание
Вам нужно реализовать умный массив для данных типа int в духе идиомы RAII, который сам управляет своей памятью: самостоятельно выделяет её при создании и очищает, когда объект данного класса не используется.

Должны быть реализованы следующие функции:

- Конструктор, принмающий количество элементов, которое будет хранить массив.
- Функция добавления нового элемента в массив. Не забудьте обработать случай, когда количество элементов больше количества элементов, на которую выделена память.
- Функция получения элемента по индексу. Не забудьте проверку на корректность индекса.
- Деструктор.

Пример правильной работы программы
Работа с вашим классом должна происходить так:
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
	int* data = 0;     // Указатель на массив данных
	int size = 0;      // Размер массива 
	int capacity = 0;  // Вместимость массива

	// Фун-я для выделения памяти
	void allocate_memory()
	{
		data = new int[capacity];
		if (!data)
		{
			throw std::bad_alloc();
		}
	}

	// Фун-я освобождения памяти
	void deallocate_memory()
	{
		if (data)
		{
			delete[] data;
			data = nullptr;
		}
	}
public:
	// Конструктор
	explicit smart_array(int initial_size) : size(0), capacity(initial_size)
	{
		allocate_memory();
	}

	// Деструктор
	~smart_array()
	{
		deallocate_memory();
	}

	// Фун-я добавления элемента
	void add_element(int element)
	{
		if (size == capacity)
		{
			// Увеличиваем вместимость массива, если он заполнен
			int new_capacity = capacity * 2;
			int* new_data = new int[new_capacity];
			if (!new_data)
			{
				throw std::bad_alloc();
			}

		   // Копируем данные в новый массив
		   for (int i = 0; i < size; ++i) {
			new_data[i] = data[i];
		   }

		   // Освобождаем память старого массива
		   deallocate_memory();

		   // Обновляем данные
		   data = new_data;
		   capacity = new_capacity;
		}

		data[size] = element;
		size++;
	}

	// Фун-я получения элемента по индексу
	int get_element(int index) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Индекс выходит за пределы массива");
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