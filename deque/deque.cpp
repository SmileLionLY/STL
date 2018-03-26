#include <deque>
#include <iterator>
#include <string>
#include <iostream>
#include <algorithm>

void deque_create_read_add_remove_assign() {
//init create
    std::cout << "===================deque create : " << std::endl;
    std::deque<std::string> deque_init_repeat(10, "name");
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
    std::cout << "deque_init_list : " << deque_init_list.front() << std::endl;
    std::cout << "deque_init_list : " << deque_init_list.back() << std::endl;
    std::cout << "deque_init_list : " << deque_init_list.front() << std::endl;
    std::cout << "deque_init_list : " << deque_init_list.at(0) << std::endl;
    std::cout << "deque_init_list : " << deque_init_list[0] << std::endl;
// push pop
    std::cout << "===================deque emplace or push : " << std::endl;
    std::deque<int> deque_int {1, 2, 3, 4};
    deque_int.push_back(5);
    deque_int.push_front(0);
    deque_int.emplace_back(6);
    deque_int.emplace_front(-1);
    std::copy(
        std::begin(deque_int), 
        std::end(deque_int), 
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    deque_int.pop_back();
    deque_int.pop_front();
// insert
    std::cout << "===================insert : " << std::endl;
    std::deque<int> deque_insert(20, 5);
    deque_insert.insert(
        std::begin(deque_insert),
        19);
    std::vector<int> vector_insert {32,32,32};
    deque_insert.insert(
        std::end(deque_insert),
        std::begin(vector_insert),
        std::end(vector_insert));
    std::copy(
        std::begin(deque_insert), 
        std::end(deque_insert), 
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

// add or remove
    std::cout << "===================add or remove : " << std::endl;
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
    deque_init_list.push_front(std::string("yating"));
    deque_init_list.push_front(std::string("yating"));
    std::copy(
        std::begin(deque_init_list), 
        std::end(deque_init_list), 
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    auto ptr = std::remove(
        std::begin(deque_init_list), 
        std::end(deque_init_list),
        std::string("yating"));
    deque_init_list.erase(
        ptr,
        std::end(deque_init_list));
    std::copy(
        std::begin(deque_init_list), 
        ptr, 
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

// assign
    std::cout << "===================assign : " << std::endl;
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
