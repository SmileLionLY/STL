#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>

class Name {
 public:
    size_t hash() const {
        return std::hash<std::string>() (first + second);
    }

    bool operator==(const Name &name) {
        return first == name.first;
    }

 public:
    std::string first;
    std::string second;
};
void unordered_map_create() {
    std::unordered_map<std::string, int> unmap1 {
        std::make_pair(std::string("liuyi"), 4)};
    std::unordered_map<std::string, int> unmap2 (
        {std::make_pair(std::string("liuyi"), 4)}, 4);
    std::vector<std::pair<std::string, int>> vec1 {
        {"jan", 4},
        {"asd", 5}};
    std::unordered_map<std::string, int> unmap3(
        std::begin(vec1),
        std::end(vec1),
        100);
}

void unordered_map_bucket() {
    std::unordered_map<std::string, int> unmap1 {
        std::make_pair(std::string("liuyi"), 4)};
    std::cout << "bucket count : " << unmap1.bucket_count() << std::endl;
    std::cout << "load factor : " << unmap1.load_factor() << std::endl;
    std::cout << "max load factor : " << unmap1.max_load_factor() << std::endl;
    unmap1.rehash(100);//分配的格子比指定大一些,这个是直接分配格子数目
    std::cout << "now bucket count : " << unmap1.bucket_count() << std::endl;
    std::cout << "now load factor : " << unmap1.load_factor() << std::endl;
    std::cout << "now max load factor : " << unmap1.max_load_factor() << std::endl;
    std::unordered_map<std::string, int> unmap2 {
        std::make_pair(std::string("liuyi"), 4)};
    unmap2.reserve(100);//这个是去询问unorderedmap容纳100个元素，需要分配多少空间，由map自己决定，而不是我们指定
    std::cout << "now bucket count(reserve) : " << unmap2.bucket_count() << std::endl;
}

void unordered_map_insert_read_erase() {
// insert and read
    std::vector<std::pair<std::string, int>> vec1 {
        {"jan", 4},
        {"asd", 5}};
    std::unordered_map<std::string, int> unmap(
        std::begin(vec1),
        std::end(vec1),
        100);
    std::cout << "unmap bucket_count : " << unmap.bucket_count() << std::endl;
    auto ptr = unmap.insert(std::make_pair(std::string("sad"), 4));//使用的是右值引用版本
    if (ptr.second) {
        std::cout << "insert success " << std::endl;    
    }
    std::cout << "now unmap bucket_count : " << unmap.bucket_count() << std::endl;
    unmap.insert(
        {std::make_pair(std::string("sad"), 4),
        std::make_pair(std::string("asd"), 5)});//使用的是右值引用版本
    std::vector<std::pair<std::string, int>> vec {
        {"aaaa", 4},
        {"cccc", 5}};
    unmap.insert(
        std::begin(vec),
        std::end(vec));
    for (auto pr : unmap) {
        std::cout << "first : " << pr.first << " second : " << pr.second << std::endl;    
    }

    std::cout << "unmap aaaa = " << unmap["aaaa"] << std::endl;
// erase
    auto num = unmap.erase(std::string("aaaa"));
    if (num != 0) {
        std::cout << "erase success " << std::endl;    
    }
    //auto ptr_end = std::end(unmap);
    //auto iter = unmap.erase(std::begin(unmap), --ptr_end);
// emplace
    std::cout << "===now unmap bucket_count : " << unmap.bucket_count() << std::endl;
    unmap.emplace(std::make_pair(std::string("asdasda"), 55));
    
    
}

int main() {
    unordered_map_create();
    unordered_map_bucket();
    unordered_map_insert_read_erase();
    return 0;
}
