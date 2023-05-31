#include <iostream>

class smart_array {
private:
    int* data;
    int size;
    int capacity;

public:
    smart_array(int num_elements) : size(0), capacity(num_elements) {
        data = new int[capacity];
    }

    ~smart_array() {
        delete[] data;
    }

    void add_element(int element) {
        if (size >= capacity) {
            // Выделение нового блока памяти с увеличенной ёмкостью
            int new_capacity = capacity * 2;
            int* new_data = new int[new_capacity];

            // Копирование данных из старого блока в новый
            for (int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }

            // Освобождение старого блока памяти
            delete[] data;

            // Перенаправление указателя на новый блок памяти
            data = new_data;
            capacity = new_capacity;
        }

        // Добавление нового элемента
        data[size] = element;
        size++;
    }

    int get_element(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid index");
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
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
