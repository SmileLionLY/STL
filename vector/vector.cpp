#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>


void vector_define_size_read_iterator() {
//vector define
    std::cout << "========vector define :" << std::endl;
    std::vector<std::string> word_initializer {
        std::string("home"),
        std::string("where") };
    std::copy(
        std::begin(word_initializer),
        std::end(word_initializer),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    std::vector<std::string> words;
    words.reserve(10);
    std::cout << "input word sperated by space , enter ctrlz+Z to end." << std::endl;
    std::copy(
        std::istream_iterator<std::string>(std::cin),
        std::istream_iterator<std::string>(),
        std::back_inserter(words));

    std::cout << "starting sort : " << std::endl;


    bool out_of_order = false;
    auto last = std::end(words);
    std::cout << "vector size : " << words.size() << std::endl;
    while (true) {
        for (auto first = std::begin(words) + 1; first != last; ++first) {
            if (*(first - 1) > *first) {
                std::swap(*first, *(first - 1));
                out_of_order = true;
            }
        }
        if (!out_of_order)
            break;
        out_of_order = false;
    }

    std::cout << "your word in vector which have sorted." << std::endl;
    std::copy(
        std::begin(words),
        std::end(words),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    std::vector<std::string> words_move(std::make_move_iterator(std::begin(words)),
        std::make_move_iterator(std::end(words)));
    std::copy(
        std::begin(words_move),
        std::end(words_move),
        std::ostream_iterator<std::string>(std::cout, "--"));
    std::cout << std::endl;

}

void vector_emplaceorpush_insert_erase_remove_assign() {
// vector emplace or push
    std::cout << "========vector emplace or push : " << std::endl;
    std::vector<std::string> vec_emplace {
        std::string("aaaa") };
    vec_emplace.push_back(std::string("bbbbb"));
    vec_emplace.emplace_back(std::string("ccccc"));
    std::copy(
        std::begin(vec_emplace),
        std::end(vec_emplace),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

// vector insert
    std::cout << "========vector insert : " << std::endl;
    std::vector<std::string>
        vector_initialiazer_list {std::string("liuyi"), std::string("yating")};
    std::vector<std::string> temp {std::string("yiting"), std::string("and")};
    vector_initialiazer_list.insert(
        std::begin(vector_initialiazer_list), std::string("and"));
    std::copy(
        std::begin(vector_initialiazer_list),
        std::end(vector_initialiazer_list),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    vector_initialiazer_list.insert(
        std::begin(vector_initialiazer_list), 
        std::begin(temp),
        std::end(temp));
    std::copy(
        std::begin(vector_initialiazer_list),
        std::end(vector_initialiazer_list),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
// erase and remove
    std::cout << "========vector erase and remove : " << std::endl;
    vector_initialiazer_list.erase(
        std::begin(vector_initialiazer_list),
        std::begin(vector_initialiazer_list) + 3);
    std::copy(
        std::begin(vector_initialiazer_list),
        std::end(vector_initialiazer_list),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "vector_initialiazer_list size : " << 
        vector_initialiazer_list.size() << std::endl;

    auto iter = std::remove(
        std::begin(vector_initialiazer_list),
        std::end(vector_initialiazer_list),
        std::string("liuyi"));
    std::copy(
        std::begin(vector_initialiazer_list),
        iter,
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << "vector_initialiazer_list size : " << 
        vector_initialiazer_list.size() << std::endl;
//assign
    std::cout << "==========vector assign :" << std::endl;
    auto initiliazor_list = {std::string("cc"), std::string("bb")};
    std::vector<std::string> vec0;
    vec0.assign(initiliazor_list);
    std::copy(
        std::begin(vec0),
        std::end(vec0),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    std::vector<std::string> vec {
        std::string("work"),
        std::string("life")};
    std::vector<std::string> vec2 {
        std::string("aaa") };
    vec2.assign(
        std::begin(vec),
        std::end(vec));
    std::copy(
        std::begin(vec2),
        std::end(vec2),
        std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;


}


int main () {
//    vector_define_size_read_iterator();
    vector_emplaceorpush_insert_erase_remove_assign();
    return 0;
}
