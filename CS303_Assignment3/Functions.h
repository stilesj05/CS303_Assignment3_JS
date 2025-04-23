#pragma once
#include <vector>
#include <list>
using namespace std;

// Q2: Recursive linear search for last occurrence
template <typename Item_Type>
int linear_search(const vector<Item_Type>& items, const Item_Type& target, int index) {
    if (index < 0)
        return -1;

    if (items[index] == target)
        return index;

    return linear_search(items, target, index - 1);
}
// Q3: Insertion sort for list of integers (or queue)
void insertion_sort(list<int>& lst) {
    if (lst.empty()) return;

    auto it = lst.begin();
    ++it; //start from the second element

    while (it != lst.end()) {
        int key = *it;
        auto j = it;
        --j;

        //find the correct spot for key
        while (j != lst.begin() && *j > key) {
            auto prev = j;
            --prev;
            --j;
        }

        //adjust for the first element
        if (*j > key && j == lst.begin()) {
            lst.insert(j, key);
            it = lst.erase(it);
        }
        else {
            auto insert_pos = j;
            ++insert_pos;
            lst.insert(insert_pos, key);
            it = lst.erase(it);
        }
    }
}

