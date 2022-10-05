#include <iostream>
#include "b_tree.cpp"
#include "link_list.cpp"
#include "link_stack.h"

using namespace std;

class example
{
private:
    int ex_int_;

public:
    void set_ex_int(int ex_int)
    {
        ex_int_ = ex_int;
    }

    int get_ex_int()
    {
        return ex_int_;
    }

    example operator + (example ex) const
    {
        example exam{};

        exam.set_ex_int(this->ex_int_ + ex.ex_int_);
        return exam;
    }
};

int main()
{
    auto test = new b_tree<int, char>();

    test->insert(8, 't');
    test->insert(2, 's');
    test->insert(7, 'v');
    test->insert(3, 't');
    test->insert(15, 's');
    test->insert(1, 'v');
    test->insert(6, 't');
    test->insert(5, 's');
    test->insert(12, 'v');

    cout << "this is b_tree elem: " << test->get(5) << endl;

    b_tree<int, char> from_test(test);

    cout << "Copy constructor is working: " << from_test.get(7) << endl;

    auto l_test = new link_list<string>;

    l_test->push_head("gang or bang");
    l_test->push_head("ququu");

    l_test->insert(1, "kigun");

    l_test->push_back("backelem");
    l_test->push_back("backelem2");
    l_test->push_back("backelem3");

    l_test->push_head("new_head_elem");

    l_test->insert(3, "kigun3");

    cout << l_test->get_size() << endl;

    auto l_stack_test = new link_stack<string>;

    l_stack_test->push("kigan");
    l_stack_test->push("nagak");
    l_stack_test->push("boo");
    l_stack_test->push("foo");
    l_stack_test->push("brown");

    l_stack_test->pop();
    l_stack_test->pop();
    l_stack_test->pop();






}



