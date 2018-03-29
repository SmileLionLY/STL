#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

void multimap_create_read_insert() {
// create multimap
    std::multimap<std::string, int> multimap1 {
        {std::string("liuyi"), 1},
        {std::string("yating"), 2}};
    std::multimap<std::string, int> multimap2 {
        std::make_pair("rose", 2),
        std::make_pair("rosea", 2)};
    std::multimap<std::string, int> multimap3(
        std::begin(multimap1),
        std::end(multimap1));
    std::multimap<std::string, int> multimap4(multimap1);
    for (auto value : multimap1) {
        std::cout << "multimap1.first : " << value.first << " multimap1.second : " <<
            value.second << std::endl;    
    }
    std::cout << std::endl;
    for (auto value : multimap2) {
        std::cout << "multimap2.first : " << value.first << " multimap2.second : " <<
            value.second << std::endl;    
    }
    std::cout << std::endl;
    for (auto value : multimap3) {
        std::cout << "multimap3.first : " << value.first << " multimap3.second : " <<
            value.second << std::endl;    
    }
    std::cout << std::endl;
// insert
    std::cout << "==================insert" << std::endl;
    auto ptr = multimap1.insert(std::make_pair(std::string("liuyi"), 3));
    multimap1.insert(ptr, std::make_pair(std::string("ziuyi"), 3));
    std::cout << "insert value : " << ptr->second << std::endl;
    multimap1.insert(std::begin(multimap2), std::end(multimap2));
    for (auto value : multimap1) {
        std::cout << "multimap1.first : " << value.first << " multimap1.second : " <<
            value.second << std::endl;    
    }
    std::cout << std::endl;
    multimap1.insert({
        std::make_pair(std::string("liuyi"), 3),
        std::make_pair(std::string("sd"), 3)});
// emplace
    std::cout << "==================emplace" << std::endl;
    auto eptr = multimap3.emplace(std::string("homhe"), 4);
    std::cout << "emplace : " << eptr->first << std::endl;
    auto eptr1 = multimap3.emplace_hint(eptr, std::string("jll"),4);
    std::cout << "emplace : " << eptr1->first << std::endl;
// find 
    std::multimap<std::string, int> multimap7 {
        {std::string("liuyi"), 44},
        {std::string("liuyi"), 44},
        {std::string("l23"), 44},
        {std::string("liuyi"), 44},
        {std::string("yating"), 2}};

    auto ptr_1 = multimap7.equal_range("liuyi");
    for (auto i = ptr_1.first; i != ptr_1.second; i++) {
        std::cout << "key : " << i->first << " value : " << i->second << 
            std::endl;    
    }
    std::cout << std::endl;
    

}

int main() {
    multimap_create_read_insert();
    return 0;
}
