#include <list>
#include <vector>
#include <iostream>
template <typename T>
class DynamicArray {
    private:
        int start;
        int end;
        int length;
        int capacity;
        std::vector<T> data;

        int getCapacity() {
            return capacity;
        }

        void __resize(int new_capacity) {
            capacity = new_capacity;
            std::vector<T> new_list(new_capacity);
            //Reset pointer to put content in middle of array with equal memory
            // buffers on both size
            int new_start = capacity;
            int new_end = new_start + length - 1;
            // Copy both lists to new bigger array
            for (int i = 0; i < length; i++) {
                new_list[new_start + i] = data[start + i];
            }
            data = new_list;
            start = new_start;
            end = new_end;
        }

    public:
        DynamicArray() {
            start = 2;
            end = 1;
            capacity = 4;
            length = 0;
            data = {NULL, NULL, NULL, NULL};
        }

        void display() {
            for (int i = start; i < end + 1; i++) {
                std::cout << data[i];
            }
        }

        int getLength() {
            return length;
        }

        void append(const T& value) {
            if (end == getCapacity() - 1) {
                __resize(getCapacity() * 2);
            }
            end += 1;
            set_at(-1, value);
            length += 1;
        }

        //allows DynamicArray[] operation
        int& operator[](int index) {
            if (index < 0 || index >= getLength()) {
                throw std::out_of_range("Index out of bounds");
            }
            return data[index];
        }

        const T& get_at(int index) {
            if (index >= 0) {
                if (index > getLength()) {
                    throw std::out_of_range("Index out of bounds");
                }
                return data[start + index];
            } else {
                if (-index > getLength) {
                    throw std::out_of_range("Index out of bounds");
                }
                return data[end + index + 1];
            }
        }

        void set_at(int index, const T& value) {
            if (index >= 0) {
                if (index > getLength()) {
                    throw std::out_of_range("Index out of bounds");
                }
                data[start + index] = value;
            } else {
                if (-index - 1 > getLength()) {
                    throw std::out_of_range("Index out of bounds");
                }
                data[end + index + 1] = value;
            }
        }
};

int main() {
    DynamicArray<int> arr;
    arr.append(5);
    arr.display();
    return 0;
}