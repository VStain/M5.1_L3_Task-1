#pragma once

class smart_array
{
 private:
	 int* data = 0;   // Указатель на массив данных
	 int size = 0;   // Размер массива 
	 int capacity;  // Вместимость массива

	 // Фун-я для выделения памяти
	 void allocate_memory()
	 {
		 data = new int[capacity];
		 if (!data)
		 {
			 throw std::bad_alloc()
		 }
	 }
};