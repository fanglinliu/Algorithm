//
//  combine.cpp
//  TestAlgorithm
//
//  Created by fanglliu on 3/23/16.
//  Copyright © 2016 fanglliu. All rights reserved.
//

#include "combine.hpp"
#include <vector>
#include <iostream>

#include "utils.hpp"

using namespace std;

void combine_sub(vector<int> vec, vector<int> result)
{
    if ( vec.size() <= 0 )
    {
        print(result);
        
        return;
    }
    
    int value = vec.back();
    vec.pop_back();
    combine_sub(vec, result);
    result.push_back(value);
    combine_sub(vec, result);
    
}

void combine(vector<int> vec)
{
    combine_sub(vec, vector<int>());
}

void run_combine_example()
{
    vector<int> vec = create_vector(5);
    combine(vec);
}
