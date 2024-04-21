#pragma once

class smart_array
{
 private:
	 int* data = 0;   // ��������� �� ������ ������
	 int size = 0;   // ������ ������� 
	 int capacity;  // ����������� �������

	 // ���-� ��� ��������� ������
	 void allocate_memory()
	 {
		 data = new int[capacity];
		 if (!data)
		 {
			 throw std::bad_alloc()
		 }
	 }
};