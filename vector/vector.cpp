#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>


void vector_define_size_read_iterator() {
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
int main () {
    vector_define_size_read_iterator();
    return 0;
}
