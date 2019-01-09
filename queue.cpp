#include "queue.h"

template <class T>
void queue<T>::insertAfter(const T&e)
{
    if (!cur)
    {
        elem<T> *p = new elem<T>();
        p->val = e;
        cur->next = p;
        p->next = cur->next;
    }
    else
        throw -1;
}

template <class T>
void queue<T>::push(const T& e)
{
    if (_size > 0)
    {
        elem<T> *Q = new elem<T>;
        Q->val_ = e;
        _tail->_next = Q;
        _tail = Q;
        Q = NULL;
        delete Q;
    }
    else
    {
        elem<T> *L = new elem<T>;
        L-> = e;
        _head = _tail = L;
        L = NULL;
        delete L;
    }
    ++_size;
}

template <class T>
void queue<T>::pop()
{
    if (size_ == 1)
    {
        delete tail_;
        head_ = NULL;
        tail_ = head_;
    }
    if (size_ > 1)
    {
            elem<T> *FIRST = head_;
        head_ = head_->next_;
        delete FIRST;
    }
    if (_size <= 0)
        throw 1;
    else
        --_size;
}
