#ifndef MY_ITERATOR_H
#define MY_ITERATOR_H

#include <iostream>

template<class T>
class my_iterator
{
public:

    my_iterator(T *ptr_data = nullptr);
    my_iterator(const my_iterator &it);
    my_iterator operator =(const my_iterator &it);
    ~my_iterator();

    T value();

    bool operator !=(const T *comp_data);
    bool operator !=(const my_iterator &it);

    bool operator ==(const T *comp_data);
    bool operator ==(const my_iterator &it);

    my_iterator operator ++();
    my_iterator operator ++(int);

    bool operator <(const my_iterator &it);
    long int operator -(const my_iterator &it);

    bool is_null();

private:

    T *data;
};

template<class T>
my_iterator<T>::my_iterator(T *ptr_data):data(ptr_data)
{}

template<class T>
my_iterator<T>::my_iterator(const my_iterator &it)
{
    data = it.data;
}

template<class T>
my_iterator<T> my_iterator<T>::operator =(const my_iterator<T> &it)
{
    if(*this != it){
        data = it.data;
    }

    return *this;
}

template<class T>
my_iterator<T>::~my_iterator()
{}

template<class T>
T my_iterator<T>::value()
{
    if(data == nullptr){

        throw std::runtime_error("nullptr in my_iterator<T>::value()");
    }

    return *data;
}

template<class T>
bool my_iterator<T>::operator !=(const T *comp_data){

    if(comp_data != nullptr){

        if(data != comp_data){
            return true;
        }

        return false;
    }
    else{

        throw std::runtime_error("nullptr in my_iterator::operator!=(const T *comp_data)");
    }
}

template<class T>
bool my_iterator<T>::operator !=(const my_iterator &it)
{
    if(data != it.data){
        return true;
    }

    return false;
}

template<class T>
bool my_iterator<T>::operator ==(const T *comp_data)
{
    if(comp_data != nullptr){

        if(data == comp_data){
            return true;
        }

        return false;
    }
    else{

        throw std::runtime_error("nullptr in my_iterator::operator ==(const T *comp_data)");
    }
}

template<class T>
bool my_iterator<T>::operator ==(const my_iterator &it)
{
    if(data == it.data){
        return true;
    }

    return false;
}

template<class T>
my_iterator<T> my_iterator<T>::operator ++()
{
    if(data == nullptr){

        throw std::runtime_error("nullptr in my_iterator<T>::operator ++()");
    }

    ++data;

    return *this;
}

template<class T>
my_iterator<T> my_iterator<T>::operator ++(int)
{
    if(data == nullptr){

        throw std::runtime_error("nullptr in my_iterator<T>::operator ++()");
    }

    my_iterator<T> tmp(data);

    ++data;

    return tmp;
}

template<class T>
bool my_iterator<T>::operator <(const my_iterator &it)
{
    return data < it.data;
}

template<class T>
long int my_iterator<T>::operator -(const my_iterator &it)
{
    return data - it.data;
}

template<class T>
bool my_iterator<T>::is_null()
{
    if(data != nullptr){
        return false;
    }

    return true;
}

#endif // MY_ITERATOR_H
