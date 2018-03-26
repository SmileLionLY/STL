#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

void map_create_read_insert() {
// create map
    std::map<std::string, int> map1 {
        {std::string("liuyi"), 1},
        {std::string("yating"), 2}};
    std::map<std::string, int> map2 {
        std::make_pair("rose", 2),
        std::make_pair("rosea", 2)};
    std::map<std::string, int> map3(
        std::begin(map1),
        std::end(map1));
    for (auto value : map1) {
        std::cout << "map1.first : " << value.first << " map1.second : " <<
            value.second << std::endl;    
    }
    std::cout << std::endl;
    for (auto value : map2) {
        std::cout << "map2.first : " << value.first << " map2.second : " <<
            value.second << std::endl;    
    }
    std::cout << std::endl;
    for (auto value : map3) {
        std::cout << "map3.first : " << value.first << " map3.second : " <<
            value.second << std::endl;    
    }
    std::cout << std::endl;
// insert
    auto pr = std::make_pair("home", 3);
    auto return_value = map1.insert(pr);
    if (!pr.second) {
        std::cout << "insert pair to map1 failed." << std::endl;
    } else {
        std::cout << "insert pair to map1 success." << std::endl;    
    }
    auto ptr1 = map1.insert(std::make_pair(std::string("liuyii"), 4));
    std::cout << "insert after ============:" << std::endl;
    for (auto value : map1) {
        std::cout << "map1.first : " << value.first << " map1.second : " <<
            value.second << std::endl;    
    }
    std::cout << std::endl;
    //auto value_1 = std::pair(std::string("aaa"), 4);
    //ptr1 = map1.insert(ptr1.first,value_1);
    //if (!ptr1.second) {
    //    std::cout << "insert failed wwww" << std::endl;    
    //}
    std::cout << "home size : " << map1.count("home") << std::endl;
    map2.insert(std::begin(map3), std::end(map3));
    map2.insert({std::make_pair(std::string("sss"), 4)});
    map2.insert({{std::string("ssswww"), 4}});
//emplace
    std::cout << "emplace ====== : " << std::endl;
    auto map_ptr = map2.emplace(std::string("month"), 4);
    map2.emplace_hint(map_ptr.first, std::string("ww"), 4);
    for (auto value : map2) {
        std::cout << "map2.first : " << value.first << " map2.second : " <<
            value.second << std::endl;    
    }
    std::cout << std::endl;
// read 
    std::cout << "key : " << std::string("liuyi") << " value : " <<
        map1.at(std::string("liuyi")) << std::endl;
    std::cout << "key : " << std::string("liuyi") << " value : " <<
        map1[std::string("liuyi")] << std::endl;

// erase
    std::cout << "before map1 size : " << map1.size() << std::endl;
    map1.erase(std::string("liuyi"));
    std::cout << "after map1 size : " << map1.size() << std::endl;
    map1.erase(std::begin(map1), std::end(map1));
}

int main() {
    map_create_read_insert();
    return 0;
}
