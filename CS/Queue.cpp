#include <iostream>
#include <cmath>

#define O std::cout<<
#define I std::cin>>
#define E <<std::endl;

template <typename T>
class Node {
    public:
        T value;
        Node<T>* reference_next;
        Node<T>* reference_previous;
        
};
template <typename T>
class queue {
    private:
        int length = 0;;
        Node<T>* first;
        Node<T>* last;
    public:
        void push(T value) {
            if (first == nullptr) {
                first = new Node<T>();
                first->value = value;
                first->reference_next = nullptr;
                first->reference_previous = nullptr;
                length++;
            }
            else {
                Node<T>* ref = first;
                first = new Node<T>();
                first->reference_next = ref;
                ref->reference_previous = first;
                first->value = value;
                if (length == 1) {
                    last = ref;
                }
                length++;
            }
        }
        void pop() {
            if (length != 0) {
                Node<T>* poped= last;
                last = last->reference_previous;
                delete poped;
                length--;
            }
            else {
                O "Queue is empty" E
            }
        }
        void print() {
            Node<T>* iterator = first;
            for (int i = 0; i < length; i++) {
                O iterator->value;
                iterator = iterator->reference_next;
            }
        }
        void Initialize(T* arr, int n) {
            for (int i = 0; i < n; i++) {
                this->push(*(arr + i));
            }
        }
        T GetFirst() {
            if (length == 0) {
                return 0;
            }
            return first->value;
        }
        T GetLast() {
            if (length == 0) {
                return 0;
            }
            return last->value;
        }
        int GetLength() {
            return this->length;
        }
};
int main()
{
    queue<int> q;
    system("pause");
    return 0;
}