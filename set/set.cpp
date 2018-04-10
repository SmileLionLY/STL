#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

void set_create_add_read_erase() {
// create
    std::cout << "===============create : " << std::endl;
    std::set<int, std::less<int>> set1 {2, 4, 6, 9};
    for(auto value : set1) {
        std::cout << value << " : ";
    }
    std::cout << std::endl;
    std::set<int, std::greater<int>> set2 {2, 4, 6, 9};
    for(auto value : set2) {
        std::cout << value << " : ";
    }
    std::cout << std::endl;
    std::vector<int> vec {1, 3, 9, 6};
    std::set<int> set3(
        std::begin(vec),
        std::end(vec));
    for(auto value : set3) {
        std::cout << value << " : ";
    }
    std::cout << std::endl;
// insert
    auto pair_set = set1.insert(5);
    if (pair_set.second) {
        std::cout << *(pair_set.first) << std::endl;    
    }

    auto iter = set1.insert(pair_set.first, 9);
    std::cout << "set 1 : " << *iter << std::endl;

    set1.insert(std::begin(vec), std::end(vec));
    for(auto value : set1) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
//emplace
    std::set<int> s1 {1, 4, 3, 19, 8};
    auto p1 = s1.emplace(1);
    if (p1.second) {
        
    } else {
        std::cout << "failed." << std::endl;    
    }

    auto iter2 = s1.emplace_hint(p1.first, 4);
    std::cout << *iter2 << std::endl;
// erase 
    for(auto value : s1) {
        std::cout << value << " ";
    }

    s1.erase(std::begin(s1));
    for(auto value : s1) {
        std::cout << value << " ";
    }

    s1.erase(std::begin(s1), std::end(s1));
//read 
    std::cout << "find 1 count :" << s1.count(1) << std::endl;
    std::cout << "1 : " << *(s1.find(1));

}

int main() {
    set_create_add_read_erase();
    return 0;
}
