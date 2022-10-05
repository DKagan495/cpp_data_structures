//
// Created by user on 9/26/22.
//

#ifndef UNTITLED_LINK_LIST_H
#define UNTITLED_LINK_LIST_H

template<class T>
class link_list
{
private:
    class node_
    {
    private:
        node_ *ptr_prev_, *ptr_next_;

        T value_;

    public:
        node_();

        explicit node_(T value);

        node_ *get_ptr_prev() const;

        void set_ptr_prev(node_ *ptr_prev);

        node_ *get_ptr_next() const;

        void set_ptr_next(node_ *ptr_next);

        T get_value() const;

        void set_value(T value);
    };

    int size_ = 0;

    node_ *find(int index);

    void init(T value);

    void push_back_node(node_ *);

protected:
    node_ *p_head_{nullptr}, *p_tail_{nullptr};

public:
    link_list();

    link_list(link_list const&);

    ~link_list();

    T get(int index);

    void insert(int index, T value);

    void push_back(T value);

    void push_head(T value);

    void remove(int index);

    int get_size();

    bool is_empty();
};


#endif //UNTITLED_LINK_LIST_H
