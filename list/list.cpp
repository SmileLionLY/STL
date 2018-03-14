#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

void list_create_add_insert() {
    std::vector<std::string> vec {std::string("my"), std::string("name")};
// create list
    std::list<std::string> list_default;
    std::list<std::string> list_num(20, std::string("liuyi"));
    std::cout << "list_num size : " << list_num.size() << std::endl;
    std::list<std::string> list_iter(std::begin(vec), std::end(vec));
    std::cout << "list_iter size : " << list_iter.size() << std::endl;
    for (auto& value : list_iter) 
        std::cout << value;
    std::cout << std::endl;
    std::list<std::string> list_copy(list_iter);
//add 
    list_iter.push_front(std::string("liuyi"));
    list_iter.push_back(std::string("yating"));
    std::copy(
        std::begin(list_iter),
        std::end(list_iter),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    list_iter.emplace_front(std::string("**"));
    list_iter.emplace_back(std::string("**"));
    std::copy(
        std::begin(list_iter),
        std::end(list_iter),
        std::ostream_iterator<std::string>(std::cout, " "));
//insert
    list_iter.insert(std::begin(list_iter), std::string("home"));
    std::copy(
        std::begin(list_iter),
        std::end(list_iter),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    list_iter.insert(std::begin(list_iter), 2, std::string("home"));
    std::copy(
        std::begin(list_iter),
        std::end(list_iter),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    list_iter.insert(
        std::begin(list_iter), 
        std::begin(vec),
        std::end(vec));
    std::copy(
        std::begin(list_iter),
        std::end(list_iter),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}

void list_remove_merge_sort() {
    std::list<std::string> list_num(20, std::string("liuyi"));
    std::vector<std::string> vec {
        std::string("my"),
        std::string("work"),
        std::string("apple") };
    list_num.insert(
        std::end(list_num),
        std::begin(vec),
        std::end(vec));
    std::copy(
        std::begin(list_num),
        std::end(list_num),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
//remove : erase
    std::cout << "==========erase elements use erase : " << std::endl;
    auto iter = std::begin(list_num);
    std::advance(iter, 20);
    list_num.erase(
        std::begin(list_num),
        iter);
    std::copy(
        std::begin(list_num),
        std::end(list_num),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    iter = std::begin(list_num);
    std::advance(iter, 1);
    list_num.erase(iter);
    std::copy(
        std::begin(list_num),
        std::end(list_num),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
//remove : remove and remove if
    std::cout << "==========erase elements use remove : " << std::endl;
    std::list<std::string> list_bak(20, std::string("liuyi"));
    list_num.insert(
        std::end(list_num),
        std::begin(list_bak),
        std::end(list_bak));
    list_num.remove(std::string("liuyi"));
    std::copy(
        std::begin(list_num),
        std::end(list_num),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    auto lambda_v =
        [] (std::string str) { return std::string("my") == str; };
    list_num.remove_if(lambda_v);
    std::copy(
        std::begin(list_num),
        std::end(list_num),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
// sort and merge
    std::cout << "==========sort elements : " << std::endl;
    std::list<int> list_int {2, 1, 3, 4, 5, 6};
    list_int.sort();
    std::copy(
        std::begin(list_int),
        std::end(list_int),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::list<int> list_aint {5, 8, 6, 10};
    list_aint.sort();
    list_int.merge(list_aint);
    std::copy(
        std::begin(list_int),
        std::end(list_int),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    auto lambda_int_compare = [] (int a, int b) {return (a >= b) ;};
    list_int.sort(lambda_int_compare);
    std::copy(
        std::begin(list_int),
        std::end(list_int),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

}
int main() {
    list_create_add_insert();
    list_remove_merge_sort();
    return 0;
}
