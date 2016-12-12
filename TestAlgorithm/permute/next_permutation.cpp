//
//  next_permutation.cpp
//  TestAlgorithm
//
//  Created by fanglliu on 07/12/2016.
//  Copyright © 2016 fanglliu. All rights reserved.
//

#include "next_permutation.hpp"

#include <vector>
#include <iostream>
#include "utils.hpp"
using namespace std;

/*
 Possile C++ standard templeate library implementation
 http://en.cppreference.com/w/cpp/algorithm/next_permutation
 **/

size_t index_of_pivot_from_end(const vector<int>& vec) {
    for (size_t i = vec.size() - 1; i > 0; i--) {
        if (vec[i - 1] <  vec[i]) {
            return i;
        }
    }
    
    return 0;
}

size_t index_of_first_greater_than_pre_pivot_from_end(size_t pivotIndex, const vector<int>& vec) {
    auto it = find_if(vec.rbegin(), vec.rend(), [&](int elem) -> bool { return elem > vec[pivotIndex - 1];});
   return it.base() -1 - vec.begin();
}

void next_permutation(vector<int>& vec) {
    size_t pivotIndex = index_of_pivot_from_end(vec);
    if (pivotIndex > 0) {
        size_t index = index_of_first_greater_than_pre_pivot_from_end(pivotIndex, vec);
        swap(vec[index], vec[pivotIndex - 1]);
        reverse(vec.begin() + pivotIndex, vec.end());
    } else {
        reverse(vec.begin(), vec.end());
    }
}
//
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    vector<int> vec = {1, 2, 3, 4, 5, 6};
//    ::next_permutation(vec);
//    print(vec);
//
//    vec = {6, 5, 4, 3, 2, 1};
//    ::next_permutation(vec);
//    print(vec);
//    
//    
//    vec = {1, 2, 3, 5, 6, 4};
//    ::next_permutation(vec);
//    print(vec);
//
//    return 0;
//}
