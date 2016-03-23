//
//  permute.cpp
//  TestAlgorithm
//
//  Created by fanglliu on 3/20/16.
//  Copyright © 2016 fanglliu. All rights reserved.
//

#include "permute.hpp"
#include <vector>
#include <iostream>
#include "utils.hpp"

using namespace std;


static int cnt = 0;

void permute_sub(vector<int> vec, int permute_size)
{
    if ( permute_size <= 1 )
    {
        ++cnt;
        
        print(vec);
        return;
    }
    
    for ( int i = 0 ; i < permute_size; i++ )
    {
        swap( vec[ permute_size - 1 - i ], vec[permute_size -1]); // mehtod 1
        permute_sub(vec, permute_size -1 );
//        swap(vec[i], vec[ permute_size - 1 ] );  // method 2
    }
    
}

void permute_sub_swap_before(vector<int>& vec, int permute_size)
{
    if ( permute_size <= 1 )
    {
        ++cnt;
        print(vec);
        
        return;
    }
    
    for ( int i = 0 ; i < permute_size; i++ )
    {
        vector<int> tmpVec = vec;
        swap(tmpVec[i], tmpVec[ permute_size - 1 ] );
        
        permute_sub_swap_before(tmpVec, permute_size -1 );
    }
    
}

void permute(vector<int> vec)
{
    cnt = 0;
    
    permute_sub(vec, (int)vec.size());
    
    std::cout << "permutation size: " << cnt << std::endl;
}


void permute_swap_before(vector<int> vec)
{
    cnt = 0;
    permute_sub_swap_before(vec, (int)vec.size());
    std::cout << "permute_swap_before permutation size: " << cnt << std::endl;
}

void permute_example()
{
    vector<int> vec = create_vector(3);
//    print(vec);
    
    permute( vec );
    
//    permute_swap_before(vec);
}



