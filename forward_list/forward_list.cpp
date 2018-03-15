#include <forward_list>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>

void forward_create() {
// create
    std::cout << "=====================create : " << std::endl;
    std::forward_list<std::string> forward_initialize {
        std::string("my"),
        std::string("name")};
    std::copy(
        std::begin(forward_initialize),
        std::end(forward_initialize),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    std::forward_list<std::string> forward_copy(
        20, std::string("apple"));
    std::copy(
        std::begin(forward_copy),
        std::end(forward_copy),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    std::vector<std::string> vec {
        std::string("banane"),
        std::string("china")};
    std::forward_list<std::string> forward_iter(
        std::begin(vec),
        std::end(vec));
    std::copy(
        std::begin(vec),
        std::end(vec),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}

void forward_read() {
    std::cout << "=====================read : " << std::endl;
    std::forward_list<std::string> forward_initialize {
        std::string("my"),
        std::string("name")};
    std::copy(
        std::begin(forward_initialize),
        std::end(forward_initialize),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    int i = 0;
    for(auto value : forward_initialize) {
        std::cout << "forward_initialize[" << i++ << "] : " << value << "\n";    
    }

    std::cout << "forward_initialize front : " << forward_initialize.front();
    std::cout << std::endl;
}

void forward_add() {
    std::cout << "=====================add : " << std::endl;
    std::forward_list<std::string> forward_initialize {
        std::string("my"),
        std::string("name")};
    forward_initialize.push_front(std::string("yating"));
    forward_initialize.emplace_front(std::string("yating"));
    std::copy(
        std::begin(forward_initialize),
        std::end(forward_initialize),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}

void forward_splice_insert() {
    std::cout << "=====================splice and insert : " << std::endl;
    std::forward_list<std::string> forward_initialize {
        std::string("my"),
        std::string("name"),
        std::string("liuyi")};
    std::forward_list<std::string> forward_copy(forward_initialize);
    auto iter = std::begin(forward_initialize);
    std::advance(iter, 1);
    forward_copy.insert_after(
        ++(std::begin(forward_copy)), 
        *iter);
    std::copy(
        std::begin(forward_copy),
        std::end(forward_copy),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    forward_initialize.insert_after(
        forward_initialize.before_begin(),
        {std::string("liuyi")});
    std::copy(
        std::begin(forward_initialize),
        std::end(forward_initialize),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    std::forward_list<std::string> vec{
        std::string("aa"),
        std::string("bb")};
    forward_initialize.insert_after(
        forward_initialize.before_begin(),
        std::begin(vec),
        std::end(vec));
    std::copy(
        std::begin(forward_initialize),
        std::end(forward_initialize),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
// splice 移动指定位置后面的元素到指定位置
    std::forward_list<int> list_1 {1, 2, 3, 4};
    std::forward_list<int> list_2 {5, 6, 7, 8};
    list_1.splice_after(
        list_1.before_begin(),
        list_2,
        std::begin(list_2),
        std::end(list_2));
    std::copy(
        std::begin(list_1),
        std::end(list_1),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void forward_erase_remove() {
    std::cout << "====================== erase : " << std::endl;
    std::forward_list<int> forward_int{1, 2, 3, 4};
    forward_int.erase_after(
        std::begin(forward_int),
        std::end(forward_int));
    std::copy(
        std::begin(forward_int),
        std::end(forward_int),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "====================== remove : " << std::endl;
    std::forward_list<int> forward_remove{1, 2, 3, 4};
    forward_remove.remove(2);
    auto lambdaa = [] (int n) {return n == 1;};
    forward_remove.remove_if(lambdaa);
    std::copy(
        std::begin(forward_remove),
        std::end(forward_remove),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int main() {
    forward_create();
    forward_read();
    forward_add();
    forward_splice_insert();
    forward_erase_remove();
    return 0;
}
