//
// Created by user on 9/21/22.
//

#ifndef UNTITLED_B_TREE_H
#define UNTITLED_B_TREE_H

template<class K, class V>
class b_tree
{
private:
    class node_
    {
    private:
        node_ *l_ptr_, *r_ptr_;

        K key_;
        V value_;
    public:
        node_();

        node_(K key, V value);

        node_ *get_l_ptr() const;

        void set_l_ptr(node_*);

        node_ *get_r_ptr() const;

        void set_r_ptr(node_*);

        K get_key() const;

        void set_key(K);

        V get_value() const;

        void set_value(V);
    };

    node_* root_ = nullptr;

    node_* find_(K, node_*);

public:
    b_tree();

    b_tree(b_tree*);

    bool is_empty();

    V get(K);

    void insert(K, V);

    void drop(K);
};

#endif //UNTITLED_B_TREE_H
