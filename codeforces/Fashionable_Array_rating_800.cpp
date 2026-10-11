#include <algorithm>
#include <functional>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    for (int i{0}; i < n; i++) {
        // initialise the array and populate it with the elements.
        int arr_size; std::cin >> arr_size;

        // this array now has the elements.
        std::vector<int> new_arr;

        for (int j{0}; j < arr_size; j++) {
            int el; std::cin >> el;
            new_arr.push_back(el);
        }

        // sort the array
        std::sort(new_arr.begin(), new_arr.end(), std::greater<int>());

        int all_modes[arr_size];
        int curr_mode = new_arr[0];
        all_modes[0] = new_arr[0];

        for (int count{1}; count < arr_size; count++) {
            int next_mode = std::max(curr_mode, new_arr[count]);
            curr_mode = next_mode;
            all_modes[count] = next_mode;
        }

        for (int index = 0; index < arr_size; index++) {
            std::cout << all_modes[index] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}