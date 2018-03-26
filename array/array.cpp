#include <array>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>

void array_create_read_compare() {
//crate
    std::array<std::string, 10> array_initialiazer_list {"liuyi", "yating"};
    std::array<std::string, 10> array_init {"yating", "liuyi"};
    // not have function below
    //std::array<std::string, 10> array_init_iter(
    //    std::begin(array_initialiazer_list),
    //    std::end(array_initialiazer_list));
    std::cout << "array_initialiazer_list size : " <<
        array_initialiazer_list.size() << std::endl;
//read
    std::cout << "index 0 : " << array_initialiazer_list.front() << std::endl;
    std::cout << "index 9 : " << array_initialiazer_list.back() << std::endl;
    std::cout << "index 1 : " << array_initialiazer_list[1] << std::endl;
    std::cout << "index 1 : " << array_initialiazer_list.at(1) << std::endl;
    std::cout << "index 2 : " << std::get<2>(array_initialiazer_list) <<
        std::endl;
    // have check index in compiler complie
    //std::cout << "index 11 : " << std::get<11>(array_initialiazer_list) <<
    //    std::endl;
    std::copy(
        std::begin(array_initialiazer_list),
        std::begin(array_initialiazer_list) + 2,
        std::ostream_iterator<std::string>(std::cout, " "));
// size
    std::cout << "array_initialiazer_list size : " <<
        array_initialiazer_list.size() << std::endl;
//compare
    if (array_initialiazer_list < array_init) {
        std::cout << "array_initialiazer_list < array_init" << std::endl;    
    } else {
        std::cout << "array_initialiazer_list >= array_init" << std::endl;    
    }

}

int main() {
    array_create_read_compare();
    return 0;
    
}
