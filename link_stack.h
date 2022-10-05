//
// Created by user on 9/27/22.
//

#ifndef UNTITLED_LINK_STACK_H
#define UNTITLED_LINK_STACK_H

#include "link_list.h"

template<class T>
class link_stack : private link_list<T>
{
public:
    void push(T);

    T pop();
};

template<class T>
void link_stack<T>::push(T value)
{
    this->push_back(value);
}

//TODO: replace this deletion to link_list tail deletion
template<class T>
T link_stack<T>::pop()
{
    auto val = this->p_tail_ ? this->p_tail_->get_value() : nullptr;
    auto p_temp = this->p_tail_->get_ptr_prev();

    delete this->p_tail_;
    this->p_tail_ = p_temp;

    return val;
}


#endif //UNTITLED_LINK_STACK_H
