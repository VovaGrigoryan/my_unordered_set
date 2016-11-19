#ifndef MY_UNORDERED_SET_H
#define MY_UNORDERED_SET_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <chrono>
#include <random>

#include "my_iterator.h"

template<class T>
class my_unordered_set
{
public:

    my_unordered_set();
    my_unordered_set(my_iterator<T> &first, my_iterator<T> &last);
    ~my_unordered_set();

    bool empty();
    size_t size();
    bool to_check_for(const T &value) const;
    void insert(const T &value);
    my_iterator<T> find(const T &value);

    void show();

    T* begin();
    T* end();

private:

    unsigned seed;
    std::default_random_engine generator;

    size_t size_memb;
    size_t capacity;

    T* data;

    void resize();
};

template<class T>
my_unordered_set<T>::my_unordered_set():
    seed(std::chrono::system_clock::now().time_since_epoch().count()),
    generator(seed),
    size_memb(0),
    capacity(8)
{
    try{

        data = new T[capacity];
    }
    catch(const std::bad_alloc &err){

        std::cout << "bad alloc in constructor" << std::endl;
        throw;
    }
}

template<class T>
my_unordered_set<T>::my_unordered_set(my_iterator<T> &first, my_iterator<T> &last):
    seed(std::chrono::system_clock::now().time_since_epoch().count()),
    generator(seed)
{
    if(!(first < last)){

        throw std::runtime_error("Bad range in my_unordered_set(my_iterator first, my_iterator last)");
    }

    if(first.is_null() || last.is_null()){

        throw std::runtime_error("input iterators have nullptr in constructor");
    }

    size_memb = last - first;
    capacity = size_memb * 2 + 1;

    try{

        data = new T[capacity];
    }
    catch(const std::bad_alloc &err){

        std::cout << "bad alloc in constructor" << std::endl;
        throw;
    }

    for(size_t i = 0; i < size_memb; ++i, ++first){

        data[i] = first.value();
    }
}

template<class T>
my_unordered_set<T>::~my_unordered_set()
{
    delete[] data;
    size_memb = 0;
    capacity = 0;
}

template<class T>
bool my_unordered_set<T>::empty()
{
    if(size_memb != 0){

        return false;
    }

    return true;
}

template<class T>
size_t my_unordered_set<T>::size()
{
    return size_memb;
}

template<class T>
bool my_unordered_set<T>::to_check_for(const T &value) const
{
    for(size_t i = 0; i < size_memb; ++i){

        if(data[i] == value){

            return true;
        }
    }

    return false;
}

template<class T>
void my_unordered_set<T>::insert(const T &value)
{

    if(empty()){

        ++size_memb;
        data[0] = value;
    }

    else if(to_check_for(value) == false){

        if(size_memb == capacity){

            try{

                resize();
            }
            catch(const std::bad_alloc &err){

                std::cout << "Bad resize in insert(const T &value)" << std::endl;
                throw;
            }
        }

        ++size_memb;

        std::uniform_int_distribution<int> distribution_insert_index(0, size_memb - 1);
        int insert_index = distribution_insert_index(generator);

        for(int i = size_memb - 1; i > insert_index; --i){

            data[i] = data[i - 1];
        }

        data[insert_index] = value;
    }
}

template<class T>
my_iterator<T> my_unordered_set<T>::find(const T &value)
{
    my_iterator<T> null_iterator(nullptr);
    my_iterator<T> iterator = this->begin();

    for(; iterator != this->end(); ++iterator){

        if(iterator.value() == value){

            return iterator;
        }
    }

    return null_iterator;
}

template<class T>
void my_unordered_set<T>::show()
{
    for(size_t i = 0; i < size_memb; ++i){
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
T *my_unordered_set<T>::begin()
{
    if(data == nullptr){

        throw std::runtime_error("nullptr in my_unordered_set<T>::begin()");
    }

    return data;
}

template<class T>
T *my_unordered_set<T>::end()
{
    if(data == nullptr){

        throw std::runtime_error("nullptr in my_unordered_set<T>::end()");
    }

    return data + size_memb;
}

template<class T>
void my_unordered_set<T>::resize()
{
    size_t new_capacity = capacity * 2 + 1;
    size_t old_size = size_memb;

    T *tmp_data = new T[new_capacity];

    for(size_t i = 0; i < old_size; ++i){

        tmp_data[i] = data[i];
    }

    this->~my_unordered_set();

    data = tmp_data;
    size_memb = old_size;
    capacity = new_capacity;
}


#endif // MY_UNORDERED_SET_H
