//
//  reverse_list.cpp
//  TestAlgorithm
//
//  Created by fanglliu on 3/19/16.
//  Copyright © 2016 fanglliu. All rights reserved.
//

#include "reverse_list.hpp"


#import <iostream>

typedef struct tagNode
{
    int value;
    struct tagNode* next;
} Node;




Node* create_list()
{
    Node* head = NULL;
    Node* tail = NULL;
    for ( int i = 0; i < 5; i++) {
        Node* tmp = new Node;
        tmp->value = i;
        tmp->next = NULL;
        
        if ( tail != NULL )
        {
            tail->next = tmp;
        }
        
        tail = tmp;
        
        if ( i == 0 )
        {
            head = tmp;
        }
        
    }
    
    return head;
}

void print_list(Node* list)
{
    std::cout << __func__  << " begin" << std::endl;
    Node* p = list;
    while (p) {
        int value = p->value;
        std::cout << value << std::endl;
        
        p = p->next;
    }
    
    std::cout << __func__  << " end" << std::endl;

}


Node* reverse_list(Node* list)
{
    Node* orginHead = list;
    Node* reverseHead = NULL;
    while ( orginHead )
    {
        Node* tmp = orginHead;
        orginHead = orginHead->next;
        
        tmp->next = reverseHead;
        reverseHead = tmp;
    }
    
    return reverseHead;
}

Node* recursive_reverse_list(Node* list)
{
    Node* head = list;
    if ( head == NULL || head->next == NULL)
    {
        return head;
    }
    
    Node* next = head->next;
    
    Node* reversed_list = recursive_reverse_list(next);
    next->next = head;

    head->next = NULL;

    return reversed_list;
}

void run_non_recursive_reverse_list()
{
    std::cout<<"run_non_recursive_reverse_list begin" << std::endl;
    Node* p = create_list();
    print_list(p);
    
    Node* reversed_list = reverse_list(p);
    print_list(reversed_list);
    
    std::cout<<"run_non_recursive_reverse_list end" << std::endl;

    
}

void run_recursive_reverse_list()
{
    std::cout<<"run_recursive_reverse_list begin" << std::endl;
    Node* p = create_list();
    print_list(p);
    
    Node* reversed_list = recursive_reverse_list(p);
    print_list(reversed_list);
    std::cout<<"run_recursive_reverse_list end" << std::endl;

}

void run_reverse_list()
{
 
    run_non_recursive_reverse_list();
    
    run_recursive_reverse_list();
    
}



