#include <list>
#include <vector>
#include <iostream>
template <typename T>
class DynamicArray {
    private:
        int start;
        int end;
        int size;
        int capacity;

        int getCapacity() {
            return capacity;
        }

    public:
        std::vector<T>* data;

        DynamicArray() {
            start = 2;
            end = 1;
            capacity = 4;
            size = 0;
        }
        int getLength() {
            return size;
        }
};

int main() {
    return 0;
}