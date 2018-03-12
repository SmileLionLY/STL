#include <deque>
#include <iterator>
#include <string>
#include <iostream>
#include <algorithm>

void deque_create_read_add_remove_assign() {
//init create
    std::deque<std::string> deque_init_size(10);
    std::deque<std::string> deque_init_list {"my", "name", "liuyi"};
    std::deque<std::string> deque_init_iter(
        std::begin(deque_init_list),
        std::end(deque_init_list) - 1);
    for(auto&& iter : deque_init_list) {
        std::cout << iter << " " ;
    }
    std::cout << std::endl;
    for (auto&& iter : deque_init_iter) {
        std::cout << iter << " " ;
    }
    std::cout << std::endl;

    std::cout << "deque_init_size size : " << deque_init_size.size() << std::endl;
    std::cout << "deque_init_list size : " << deque_init_list.size() << std::endl;
    std::cout << "deque_init_iter size : " << deque_init_iter.size() << std::endl;

// read
    int i = 0;
    for (auto iter = std::begin(deque_init_list); 
        iter != std::end(deque_init_list);
        iter++) {
        i++;
        std::cout << "deque_init_list[" << i << "] : " << *iter << std::endl;    
    }
// add or remove
    deque_init_list.push_back(std::string("yating"));
    deque_init_list.push_front(std::string("yating"));
    std::copy(
        std::begin(deque_init_list), 
        std::end(deque_init_list), 
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    deque_init_list.pop_back();
    deque_init_list.pop_front();
    std::copy(
        std::begin(deque_init_list), 
        std::end(deque_init_list), 
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
// assign
    auto initializer_list = {std::string("liuyi"), std::string("yating")};
    deque_init_list.assign(initializer_list);
    std::copy(
        std::begin(deque_init_list), 
        std::end(deque_init_list), 
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

}

int main() {
    deque_create_read_add_remove_assign();
    return 0;    
}
