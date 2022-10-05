//
// Created by user on 9/27/22.
//

#ifndef UNTITLED_ARR_LIST_H
#define UNTITLED_ARR_LIST_H

template <class T>
class arr_list
{
private:
    static const int init_cap_ = 16;

    int size_ = 0;

    T *init_arr_ = new T[init_cap_];

    bool is_empty();
public:
    void insert_head(T);

    void insert_index(int, T);

    void insert_tail(T);

    void get(int index);

    void remove(int index);
};




#endif //UNTITLED_ARR_LIST_H
