//
// Created by user on 9/21/22.
//

#include "b_tree.h"

template<class K, class V>
b_tree<K, V>::node_::node_()
= default;

template<class K, class V>
b_tree<K, V>::node_::node_(K key, V value)
{
    key_ = key;
    value_ = value;
}

template<class K, class V>
typename b_tree<K, V>::node_ *b_tree<K, V>::node_::get_l_ptr() const
{
    return l_ptr_;
}

template<class K, class V>
void b_tree<K, V>::node_::set_l_ptr(b_tree::node_ *l_ptr)
{
    l_ptr_ = l_ptr;
}

template<class K, class V>
typename b_tree<K, V>::node_ *b_tree<K, V>::node_::get_r_ptr() const
{
    return r_ptr_;
}

template<class K, class V>
void b_tree<K, V>::node_::set_r_ptr(b_tree::node_ *r_ptr)
{
    r_ptr_ = r_ptr;
}

template<class K, class V>
K b_tree<K, V>::node_::get_key() const
{
    return key_;
}

template<class K, class V>
void b_tree<K, V>::node_::set_key(K key)
{
    key_ = key;
}

template<class K, class V>
V b_tree<K, V>::node_::get_value() const
{
    return value_;
}

template<class K, class V>
void b_tree<K, V>::node_::set_value(V value)
{
    value_ = value;
}

template<class K, class V>
typename b_tree<K, V>::node_ *b_tree<K, V>::find_(K key, b_tree::node_ *node)
{
    if(!node)
    {
        return nullptr;
    }

    if(key == node->get_key())
    {
        return node;
    }

    auto target = find_(key, node->get_key() > key ? node->get_l_ptr() : node->get_r_ptr());

    return target ? target : node;
}

template<class K, class V>
b_tree<K, V>::b_tree()
= default;

template<class K, class V>
b_tree<K, V>::b_tree(b_tree *source)
{
    root_ = source->root_;
}

template<class K, class V>
bool b_tree<K, V>::is_empty()
{
    return !root_;
}

template<class K, class V>
V b_tree<K, V>::get(K key)
{
    return find_(key, root_)->get_value();
}

template<class K, class V>
void b_tree<K, V>::insert(K key, V value)
{
    auto to_ins = new node_(key, value);

    if(is_empty())
    {
        root_ = to_ins;

        return;
    }

    auto find_res = find_(key, root_);

    if(find_res->get_key() < key)
    {
        find_res->set_r_ptr(to_ins);
    }
    else if(find_res->get_key() > key)
    {
        find_res->set_l_ptr(to_ins);
    }
    else
    {
        find_res->set_value(to_ins->get_value());
    }
}

template<class K, class V>
void b_tree<K, V>::drop(K key)
{
    delete find_(key, root_);
}


