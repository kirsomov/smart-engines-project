#include "solution.cpp"

int main() {
    std::vector<int> arr;
    Read(arr);

    auto [left, right] = GetRangeWithNullSum(arr);

    if (left == NOT_EXISTED || right == NOT_EXISTED) {

        std::cout << "Something is broken" << std::endl;
        std::abort();
    }
    std::cout << "L = " << left << ", R = " << right << std::endl;
    return 0;
}
