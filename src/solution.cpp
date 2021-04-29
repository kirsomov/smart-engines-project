#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>

void Read(std::vector<int>& arr) {
    assert(arr.empty());

    size_t array_size = 0;
    std::cout << "Enter size of array from [1, 10^6]" << std::endl;
    std::cin >> array_size;

    arr.reserve(array_size);

    std::cout << "Enter elements of array" << std::endl;
    for (size_t i = 0; i < array_size; i++) {
        int new_value = 0;
        std::cin >> new_value;
        arr.push_back(new_value);
    }
}

void CalculateModuloPrefixSums(const std::vector<int>& arr, std::vector<int>& modulo_prefix_sums) {
    assert(modulo_prefix_sums.empty());
    modulo_prefix_sums.reserve(arr.size());

    const int module = (int) arr.size();
    modulo_prefix_sums.push_back(arr[0] % module);
    for (size_t i = 1; i < arr.size(); i++) {
        modulo_prefix_sums.push_back((modulo_prefix_sums.back() + arr[i]) % module);
    }
}

const int NOT_EXISTED = -1;

auto GetRangeWithNullSum(const std::vector<int>& arr) {
    std::vector<int> modulo_prefix_sums;
    CalculateModuloPrefixSums(arr, modulo_prefix_sums);

    std::vector<int> positions(modulo_prefix_sums.size(), NOT_EXISTED);

    for (int i = 0; i < modulo_prefix_sums.size(); i++) {
        assert(0 <= modulo_prefix_sums[i] && modulo_prefix_sums[i] < modulo_prefix_sums.size());
        if (modulo_prefix_sums[i] == 0 ) {
            return std::make_tuple(0, i);
        }
        if (positions[modulo_prefix_sums[i]] == NOT_EXISTED) {
            positions[modulo_prefix_sums[i]] = i;
        } else {
            return std::make_tuple(positions[modulo_prefix_sums[i]] + 1 , i);
        }
    }
    return std::make_tuple(NOT_EXISTED, NOT_EXISTED);
}
