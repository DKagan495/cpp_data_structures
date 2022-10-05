//

#include "link_list.h"

using namespace std;

template<class T>
link_list<T>::node_::node_() = default;

template<class T>
link_list<T>::node_::node_(T value)
{
    value_ = value;
}

template<class T>
typename link_list<T>::node_ *link_list<T>::node_::get_ptr_prev() const
{
    return ptr_prev_;
}

template<class T>
void link_list<T>::node_::set_ptr_prev(link_list::node_ *ptr_prev)
{
    ptr_prev_ = ptr_prev;
}

template<class T>
typename link_list<T>::node_ *link_list<T>::node_::get_ptr_next() const
{
    return ptr_next_;
}

template<class T>
void link_list<T>::node_::set_ptr_next(link_list::node_ *ptr_next)
{
    ptr_next_ = ptr_next;
}

template<class T>
T link_list<T>::node_::get_value() const
{
    return value_;
}

template<class T>
void link_list<T>::node_::set_value(T value)
{
    node_::value_ = value;
}

template<class T>
link_list<T>::~link_list()
{
    delete p_head_;
}

template<class T>
typename link_list<T>::node_ *link_list<T>::find(int index)
{
    auto temp = p_head_;

    for(unsigned int i = 0; i < index; i++)
    {
        temp = temp->get_ptr_next();
    }

    return temp;
}

template<class T>
T link_list<T>::get(int index)
{
    auto elem = find(index);

    return elem ? elem->get_value() : nullptr;
}

template<class T>
void link_list<T>::insert(int index, T value)
{
    if(!p_head_ && index == 0)
    {
        push_head(value);
        size_++;

        return;
    }

    auto insertion_around_left = find(index - 1);

    auto insertion_around_right = insertion_around_left->get_ptr_next();

    auto ins = new node_(value);

    ins->set_ptr_prev(insertion_around_left);
    ins->set_ptr_next(insertion_around_right);

    insertion_around_left->set_ptr_next(ins);
    insertion_around_right->set_ptr_prev(ins);

    size_++;
}

template<class T>
void link_list<T>::push_back(T value)
{
    auto ins = new node_(value);

    if(!p_head_)
    {
        init(value);

        return;
    }

    ins->set_ptr_prev(p_tail_);
    p_tail_->set_ptr_next(ins);

    p_tail_ = ins;

    size_++;
}

template<class T>
void link_list<T>::push_head(T value)
{
    auto ins = new node_(value);

    if(!p_head_)
    {
        init(value);

        return;
    }

    ins->set_ptr_next(p_head_);
    p_head_->set_ptr_prev(ins);

    p_head_ = ins;

    size_++;
}

template<class T>
void link_list<T>::remove(int index)
{

}

template<class T>
int link_list<T>::get_size()
{
    return size_;
}

template<class T>
bool link_list<T>::is_empty()
{
    return !p_head_;
}

template<class T>
void link_list<T>::init(T value)
{
    p_head_ = new node_(value);
    p_tail_ = p_head_;

    size_++;
}

template<class T>
link_list<T>::link_list(link_list const &source)
{
    p_head_ = source.p_head_;
}

template<class T>
void link_list<T>::push_back_node(link_list::node_ *node)
{

    if(!p_head_)
    {
        init(node->get_value());

        return;
    }

    node->set_ptr_prev(p_tail_);
    p_tail_->set_ptr_next(node);

    p_tail_ = node;
}

template<class T>
link_list<T>::link_list()
= default;
