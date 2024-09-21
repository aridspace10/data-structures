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

        int getCapacity() {
            return capacity;
        }

        void __resize(int new_capacity) {
            capacity = new_capacity;
            std::vector<T>* new_list = [NULL] * (capacity);
            //Reset pointer to put content in middle of array with equal memory
            // buffers on both size
            int new_start = self.capacity;
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
        std::vector<T>* data;

        DynamicArray() {
            start = 2;
            end = 1;
            capacity = 4;
            length = 0;
        }

        int getLength() {
            return length;
        }

        void append(<T> value) {
            if (data[getCapacity() - 1] != NULL) {
                __resize(getCapacity() * 2);
            }
            end += 1;        
            length += 1;
        }

};

int main() {
    return 0;
}