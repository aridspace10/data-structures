template <typename T>
class Node {
    public:
        T data;
        Node* next;

        Node(const T& data) {
            data = data;
            next = nullptr;
        }
};

int main() {
    return 0;
}