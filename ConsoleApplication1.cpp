#include <iostream>

class SmartArray {
private:
    int* data;
    int size;

public:
    SmartArray(int size) : size(size) {
        data = new int[size];
    }

    ~SmartArray() {
        delete[] data;
    }

    void add_element(int element) {
        if (size < size + 1) {
            int* new_data = new int[size + 1];

            for (int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }

            new_data[size] = element;

            delete[] data;
            data = new_data;
            size++;
        }
    }

    int get_element(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        } else {
            throw std::out_of_range("Invalid index");
        }
    }
};

int main() {
    SmartArray arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    SmartArray new_array(2);
    new_array.add_element(44); 
    new_array.add_element(34);

    arr = new_array;

    return 0;
}
