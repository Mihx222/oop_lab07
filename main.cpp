#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> read_file(const char* filename) {
    ifstream file;
    file.exceptions(ifstream::badbit);
    vector<int> nums;
    int num;
    try {
        file.open(filename);
        while (file >> num)
            nums.push_back(num);
    }
    catch (const ifstream::failure& ex) {
        cerr << "Error opening/reading file: " << ex.what() << endl;
        exit(1);
    }
    return nums;
}

template<typename T>
void print_vector(const vector<T>& vec) {
    for (auto element : vec)
        cout << element << ", ";
}

int main() {
    vector<int> nums = read_file("text.txt");
    vector<int> sorted_subsequence;

    cout << "Secventa initiala:" << endl;
    print_vector(nums);

    auto max = max_element(nums.begin(), nums.end());
    auto max_index = distance(nums.begin(), max);
    auto min = min_element(nums.begin(), nums.end());
    auto min_index = distance(nums.begin(), min);

    cout << "\n\nElementul maximal: " << *max << ", pe pozitia: " << max_index << endl;
    cout << "Elementul minimal: " << *min << ", pe pozitia: " << min_index << endl;

    if (min_index <= max_index) {
        partial_sort(min, max + 1, max, greater<>());
        for (auto it = min; it != max + 1; it++)
            sorted_subsequence.push_back(*it);
    }
    else {
        partial_sort(max, min + 1, min, greater<>());
        for (auto it = max; it != min + 1; it++)
            sorted_subsequence.push_back(*it);
    }

    cout << "\nSubsecventa sortata descendent intre min si max:" << endl;
    print_vector(nums);
    cout << "\nSubsecventa sortata descendent:" << endl;;
    print_vector(sorted_subsequence);
}
