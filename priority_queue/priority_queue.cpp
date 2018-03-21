#include <queue>
#include <iostream>

void priority_queue_create_read_add_remove() {
// create
    std::priority_queue<int> pri_que1;
    std::vector<int> vec {1, 2, 3};
    std::priority_queue<int> pri_que2(std::begin(vec), std::end(vec));
    std::priority_queue<int> pri_que3(pri_que2);
// add and read
    int a = 9;
    pri_que2.push(0);
    pri_que2.push(a);
    pri_que2.emplace(90);
    std::cout << "priority size : " << pri_que2.size() << std::endl;
    while (!pri_que2.empty()) {
        std::cout << "pri_que2 : " << pri_que2.top() << std::endl; 
        pri_que2.pop();
    }
    std::cout << std::endl;
    while (!pri_que3.empty()) {
        std::cout << "pri_que3 : " << pri_que3.top() << std::endl; 
        pri_que3.pop();
    }
} 

int main() {
    priority_queue_create_read_add_remove();
    return 0;
}
