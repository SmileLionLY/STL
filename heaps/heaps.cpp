#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

void heap_create_add_remove() {
//create 只要序列容器支持随机迭代器就能支持heap
    std::cout << "create max heap : " << std::endl;
    std::vector<float> vec {2.5f, 10, 5};
    std::make_heap(std::begin(vec), std::end(vec));
    std::copy(
        std::begin(vec),
        std::end(vec),
        std::ostream_iterator<float>(std::cout, " "));
    std::cout << "create min heap : " << std::endl;
    std::vector<float> vec1 {2.5f, 10, 5};
    std::make_heap(std::begin(vec1), std::end(vec1), std::greater<float>());
    std::copy(
        std::begin(vec1),
        std::end(vec1),
        std::ostream_iterator<float>(std::cout, " "));
    std::cout << std::endl;

// add
    std::cout << "add elements to heap " << std::endl;
    std::vector<float> vec2 {2.5f, 10.0f, 5.0f};
    std::make_heap(std::begin(vec2), std::end(vec2), std::greater<float>());
    vec.emplace_back(4.9f);
    std::push_heap(std::begin(vec2), std::end(vec2), std::greater<float>());
    std::copy(
        std::begin(vec2),
        std::end(vec2),
        std::ostream_iterator<float>(std::cout, " "));
    std::cout << std::endl;
// remove 不管是大顶堆还是小顶堆删除的都是顶端的元素
    std::pop_heap(std::begin(vec2), std::end(vec2), std::greater<float>());
    vec2.pop_back();
    std::copy(
        std::begin(vec2),
        std::end(vec2),
        std::ostream_iterator<float>(std::cout, " "));
    std::cout << std::endl;
// is a heap
    if (std::is_heap(std::begin(vec2), std::end(vec2), std::greater<float>())){
        std::cout << "is a big heap " << std::endl;
    }
    
}

int main() {
    heap_create_add_remove();
    return 0;
}
