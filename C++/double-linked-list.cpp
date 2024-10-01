#include "node.cpp"
template <typename T>
class DoubleLinkedList {
    private:
        void _insert_to_back(const T& value) {
            if (size == 0) {
                head = Node<T>(value);
                tail = Node<T>(value);
            } else {
                Node<T> new_tail = Node<T>(value);
                new_tail.prev = tail;
                tail.next = new_tail;
                tail = new_tail;
            }
            size += 1;
        }

        void _insert_to_front(const T& value) {
            if (size == 0) {
                head = Node<T>(value);
                tail = Node<T>(value);
            } else {
                Node<T> new_head = Node<T>(value);
                new_head.next = head;
                head.prev = new_head;
                tail = new_head;
            }
            size += 1;
        }

    public:
        Node<T> head;
        Node<T> tail;
        int size;
        bool reversed;

        void insert_to_back(const T& value) {
            if (reversed) {
                _insert_to_front(value);
            } else {
                _insert_to_back(value);
            }
        }

        void insert_to_front(const T& value) {
            if (reversed) {
                _insert_to_back(value);
            } else {
                _insert_to_front(value);
            }
        }

        void reverse() {
            reversed = !reversed;
        }

};