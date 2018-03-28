#include <tuple>
#include <utility>
#include <string>
#include <iostream>

void pair_create_read() {
//create
    std::string str1("liuyi");
    std::string str2("play");
    std::pair<std::string, std::string> p1(str1, str2);
    std::pair<std::string, std::string> p2(
        std::string("guangzhou"), std::string("shenzhen"));
    std::pair<std::string, std::string> p3(
        "guangzhou", "shenzhen");
    std::pair<std::string, std::string> p4(p1);
    
    auto p5 = std::make_pair(str1, str2);
    auto p6 = std::make_pair(std::string("aple"), std::string("banena"));
    
    std::cout << "p1.first : " << p1.first << "   p1.second : " << p1.second <<
        std::endl;
    
//compare
    std::pair<int, int> pi_1(1, 2);
    std::pair<int, int> pi_2(1, 3);
    std::pair<int, int> pi_3(3, 3);

    if (pi_1 < pi_2) {
        std::cout << "pi_1 < pi_2" << std::endl;   
    } else {
        std::cout << "pi_1 >= pi_2" << std::endl;   
    }
}

void tuple_create_read() {
    std::tuple<std::string, int, std::string> t1(
        std::string("liuyi"),
        1,
        std::string("aaaa"));
    std::tuple<std::string, int, std::string> t2(t1);
    std::tuple<std::string, std::string>
        t3(std::pair<std::string,std::string>(std::string("a"), std::string("asd")));
    std::cout << "t1 0 : " << std::get<0>(t1) << std::endl;
    std::cout << "t2 0 : " << std::get<0>(t2) << std::endl;
    auto t4 = std::make_tuple(std::string("asdasd"), 33);
    std::cout << "t4 0 : " << std::get<0>(t4) <<
        " t4 1 : " << std::get<1>(t4) << std::endl;
    std::string name, other;
    int a;
    std::tie(name, a, other) = t1;
    std::cout << "name : " << name << std::endl;
}


int main() {
    pair_create_read();
    tuple_create_read();
    return 0;
}

