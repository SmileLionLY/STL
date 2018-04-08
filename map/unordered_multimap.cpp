#include <unordered_map>
#include <vector>
#include <iostream>

void unordered_multimap_create() {
    std::unordered_multimap<std::string, std::string> map1 {
        {std::string("liuyi"), std::string("yating")}};
    std::unordered_multimap<std::string, std::string> map2 (
        {{std::string("liuyi"), std::string("yating")}}, 5); //
        //{std::string("liuyi"), std::string("yating")} = make_pair
    std::vector<std::pair<std::string, std::string>> vec1 {
        {"jan", "sd"},
        {"asd", "123"}};
    std::unordered_multimap<std::string, std::string> unmap3(
        std::begin(vec1),
        std::end(vec1),
        100);
}

void unordered_multimap_insert_add_read_remove() {
// emplace
    std::unordered_multimap<std::string, std::string> map1 {
        {std::string("liuyi"), std::string("yating")}};
    auto iter = map1.emplace(std::make_pair("liuyi", "yating"));
    map1.emplace_hint(iter, std::make_pair("liuyi", "asdsd"));
    for (auto value : map1) {
        std::cout << "map1.first : " << value.first << "map1.second : " << 
            value.second << std::endl;
    }
//insert
    std::cout << "=====================insert : " << std::endl;
    auto iter1 =
        map1.insert(std::make_pair(std::string("map"), std::string("map2")));
    std::cout << "iter1->first : " << iter1->first << " iter1->second : " << 
        iter1->second << std::endl;
    std::vector<std::pair<std::string, std::string>> vec1 {
        {"jan", "sd"},
        {"asd", "123"}};
    map1.insert(
        std::begin(vec1),
        std::end(vec1));
    for (auto value : map1) {
        std::cout << "map1.first : " << value.first << "map1.second : " << 
            value.second << std::endl;
    }
// read
    std::cout << "=======================read : " << std::endl;
    std::unordered_multimap<std::string, int> map3 {
        {std::string("apple"), 4},
        {std::string("apple"), 6},
        {std::string("banana"), 6},
        {std::string("banana"), 6},
        {std::string("oringe"), 8}};
    auto iter3 = map3.find("apple");
    if (iter3 != map3.end()) {
        std::cout << iter3->first << " : " << iter3->second << std::endl;    
        std::cout << "count : " << map3.count(iter3->first) << std::endl;
    } else {
        std::cout << "can't find this value." << std::endl;    
    }

    auto pr = map3.equal_range("banana");
    for (auto it = pr.first; it != pr.second; it++) {
        std::cout << (pr.first)->first << " : " << (pr.second)->second <<
            std::endl;    
    }



}

int main() {
    unordered_multimap_create();
    unordered_multimap_insert_add_read_remove();
    return 0;    
}
