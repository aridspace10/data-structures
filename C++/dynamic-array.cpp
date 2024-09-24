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
            int new_start = capacity / 4;
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
            std::cout << "[";
            for (int i = start; i < end + 1; i++) {
                std::cout << data[i];
                if (i != end) {
                    std::cout << ",";
                }
            }
            std::cout << "]";
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
                if (-index > getLength()) {
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

        void insert(int index, const T& value) {
            if (index < 0 || index > getLength()) {
                throw std::out_of_range("Index out of bounds");
            }

            if (end == getCapacity() - 1) {
                __resize(getCapacity() * 2);
            }

            for (int i = length; i > index; i--) {
                set_at(i, get_at(i - 1));
            }
            set_at(index, value);
            length += 1;
            end += 1;
        }
};

int main() {
    DynamicArray<int> arr;
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(5);
    arr.append(6);
    arr.insert(3, 4);
    arr.display();
    return 0;
}