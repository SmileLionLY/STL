#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>

void stack_create_read_add_remove () {
    std::deque<std::string> deque_string {
        std::string("liuyi")};
    std::stack<std::string> stack(deque_string);
    std::stack<std::string> stack_copy(stack);
    while (!stack.empty()) {
        std::cout << "stack elements : " << stack.top() << std::endl;    
        stack.pop();
    }
    stack.push(*(std::begin(deque_string)));
    stack.push(std::string("at"));
    stack.emplace(std::string("apple"));
    std::cout << "stack size : " << stack.size() << std::endl;
    while (!stack.empty()) {
        std::cout << "stack elements : " << stack.top() << std::endl;    
        stack.pop();
    }
    std::cout << "stack size : " << stack.size() << std::endl;
    std::deque<std::string> deque_string1 {
        std::string("liuyi"),
        std::string("at ")};
    std::stack<std::string> stack1(deque_string1);
    std::stack<std::string> stack2;
    stack2.swap(stack1);
    while (!stack2.empty()) {
        std::cout << "stack 2 elements : " << stack2.top() << std::endl;    
        stack2.pop();
    }
    std::list<int> list {1, 2, 3};
    std::stack<int, std::list<int>> stack_list(list);
}

int main() {
    stack_create_read_add_remove();
    return 0;
}
