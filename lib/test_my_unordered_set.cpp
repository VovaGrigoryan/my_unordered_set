#include "test_my_unordered_set.h"
#include "my_unordered_set.h"
#include "my_iterator.h"

#include <iostream>

void test_my_unordered_set()
{
    //test constructors
    {
        std::cout<< "==========TEST CONSTRUCTORS==========" << std::endl;

        my_unordered_set<char> c;
        my_unordered_set<int> i;
        my_unordered_set<double> d;

        int max_numb = 7;

        my_unordered_set<int> i_set;

        for(int i = 0; i < max_numb; ++i){
            i_set.insert(i);
        }

        std::cout << "Set BEFORE        : ";
        i_set.show();

        my_iterator<int> it_beg = i_set.begin();
        my_iterator<int> it_end = i_set.end();

        for(int i = 0; i < max_numb / 2; ++i){
            ++it_beg;
        }

        my_unordered_set<int> from_range_it(it_beg, it_end);

        std::cout << "Set from range it : ";
        for(my_iterator<int> it_range = from_range_it.begin(); it_range != from_range_it.end(); it_range++){
            std::cout << it_range.value() << " ";
        }
        std::cout << std::endl;



        std::cout << "==========END  CONSTRUCTORS==========" << std::endl << std::endl;
    }
    //test insert
    {
        std::cout<< "==============TEST INSERT=============" << std::endl;

        my_unordered_set<int> i_set;

        for(int i = 0; i < 36; ++i){
            i_set.insert(i);
        }

        i_set.show();

        std::cout<< "==============END  INSERT=============" << std::endl << std::endl;
    }
    //test iterators
    {
        std::cout<< "=============TEST ITERATOR============" << std::endl;

        my_unordered_set<int> i_set;

        for(int i = 0; i < 32; ++i){
            i_set.insert(i);
        }

        std::cout << "show()     : ";
        i_set.show();

        std::cout << "Prefix it  : ";
        for(my_iterator<int> it = i_set.begin(); it != i_set.end(); ++it){
            std::cout << it.value() << " ";
        }
        std::cout << std::endl;

        std::cout << "Postfix it : ";
        for(my_iterator<int> it = i_set.begin(); it != i_set.end(); it++){
            std::cout << it.value() << " ";
        }
        std::cout << std::endl;

        my_iterator<int> beg = i_set.begin();
        my_iterator<int> end = i_set.end();
        my_iterator<int> it1 = beg;

        std::cout << "it1 = beg  : ";
        for(; it1 != end; ++it1){
            std::cout << it1.value() << " ";
        }
        std::cout << std::endl;

        std::cout<< "=============END  ITERATOR============" << std::endl << std::endl;
    }
    //test find
    {
        std::cout<< "===============TEST FIND==============" << std::endl;

        int max_numb = 7;
        int f_good_value = 4;
        int f_bad_value = 8;

        my_unordered_set<int> i_set;

        for(int i = 0; i < max_numb; ++i){
            i_set.insert(i);
        }

        my_iterator<int> good_it = i_set.find(f_good_value);
        my_iterator<int> bad_it = i_set.find(f_bad_value);

        std::cout << "find f_good_value. good_it.value = "  << good_it.value() << std::endl;

        std::cout << "find f_bad_value!!! Now exception!!!" << std::endl;

        try{

            std::cout << bad_it.value() << std::endl;
        }
        catch(const std::runtime_error &err){

            std::cout << err.what() << std::endl;
        }

        std::cout<< "===============END  FIND==============" << std::endl;
    }
}

