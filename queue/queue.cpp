#include <iostream>
#include <queue>
#include <deque>
#include <string>

void deque_create_add_remove() {
    std::deque<int> deque_int{1, 2, 3};
    std::queue<int> queue_int(deque_int);
    std::queue<int> queue_int1(queue_int);
    int a = 0;
    queue_int.push(a);
    queue_int.push(1);
    queue_int.emplace(2);
    while(!queue_int.empty()) {
        std::cout << "queue : " << queue_int.front() << std::endl;
        queue_int.pop();
    }
    queue_int.swap(queue_int1);
    while(!queue_int.empty()) {
        std::cout << "queue : " << queue_int.front() << std::endl;
        queue_int.pop();
    }
}

int main() {
    deque_create_add_remove();
}
