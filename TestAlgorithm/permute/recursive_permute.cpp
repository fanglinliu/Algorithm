//
//  recursive_permute.cpp
//  TestAlgorithm
//
//  Created by fanglliu on 07/12/2016.
//  Copyright © 2016 fanglliu. All rights reserved.
//

#include "recursive_permute.hpp"
//
//  main.cpp
//  TestC++
//
//  Created by fanglliu on 9/8/16.
//  Copyright © 2016 fanglliu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

static int cnt = 0;

void printVector(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    ++cnt;
    cout << std::endl;
}

void permute(const vector<int>& vec, size_t len) {
    if (len == 1) {
        printVector(vec);
        return;
    }
    
    for (int i = 0; i < len; i++) {
        vector<int> vecCopy(vec);
        swap(vecCopy[i], vecCopy[len -1]);
        permute(vecCopy, len - 1);
    }
}
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    vector<int> vec = {1, 2, 3};
//    permute(vec, vec.size());
//    
//    std::cout << "Hello, World!\n" << "cnt: " << cnt << endl;
//    return 0;
//}
