#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_
#include <iostream>
#include "MyList.h"

template<class T>
class queue
{
public:
	queue() : _first(NULL), _last(_first), _size(0) {}
	queue(const queue<T> &other);
	~queue();
	T& front();
	T& back();
	bool empty();
	size_t size();
	void clear();
	void push(const T& element);
	void pop();
	template<typename U>
	friend queue<U> operator+(const queue<U> &lhs, const queue<U> &rhs);
	bool operator==(const queue<T>& other);
	bool operator!=(const queue<T>& other);
	queue<T>& operator=(const queue<T>& other);
	template<typename U>
	friend std::ostream& operator<<(std::ostream& os,const queue<U> &_queue);
       	void QueueSort();

private:
	list<T> *_first;
	list<T> *_last;
	size_t _size;
};

template<typename T>
std::ostream& operator<<(std::ostream& os,const queue<T> &_queue){
  		if (_queue._size > 0) {
			list<T> *_FIRST = _queue._first;
        		while (_FIRST != 0) {
                		os << _FIRST->_x << std::endl;
               			_FIRST = _FIRST->_next;
       			}
		}
		else
			throw 3;
        	return os;
}
template<typename T>
queue<T> operator+(const queue<T> &lhs, const queue<T> &rhs) {
        	queue<T> Q = lhsa
		list<T> *RFirst = rhs._first;
		while(RFirst != NULL)  {
                        Q.push(RFirst->_x);
                        RFirst = RFirst->_next;
                }
        	return Q;
}
template<class T>
queue<T>::queue(const queue<T> &other) {
//  	list<T> *FIRST = other._first;
//	while (FIRST != NULL) {
//		std::cout <<"FIRST = " << FIRST << std::endl;
//		(*this).push(FIRST->_x);
//		FIRST = FIRST->_next;
//	}
	std::cout << "COPY" << std::endl;
	_size = 0;
	_first = new list<T>;
	*this = other;
}

template<class T>
queue<T>::~queue() {
	std::cout << "DESTRUCTION" << std::endl;
	(*this).clear();
	std::cout << _first << " " << _last << std::endl;
}
template<class T>
T& queue<T>::front()
{
	if (_size != 0)
		return _first->_x;
	throw 2;
}
template<class T>
void queue<T>::clear() {
	std::cout << "CLEAR" << std::endl;
	std::cout << "_first = " << _first << std::endl;
	std::cout << "_first after clear = " << _first << std::endl;
	if (_size > 0){
		list<T> *FIRSTN = _first->_next;
       		 delete _first;
		list<T> *cur = FIRSTN;
		while (cur != NULL) {
			std::cout <<"cur = " <<  cur << std::endl;
			std::cout <<"cur x = " <<  cur->_x << std::endl;
			list<T> *CURN = cur->_next;
 	      	        delete cur;
			cur = CURN;
		}
	_size = 0;
	_first = NULL;
	_last = _first;
	}
}
template<class T>
T& queue<T>::back()
{
	if (_size != 0)
		return _last->_x;
	throw 2;
}
template<class T>
bool queue<T>::empty()
{
	return _size == 0;
}
template<class T>
size_t queue<T>::size()
{
	return _size;
}
template<class T>
void queue<T>::push(const T& element)
{

	std::cout <<"PUSH" << std::endl;
	if (_size > 0)
	{
		list<T> *Q = new list<T>;
		std::cout <<"Q = " << Q << std::endl;
		Q->_x = element;
		_last->_next = Q;
		_last = Q;
		std::cout << "_first = " << _first << std::endl;
		Q = NULL;
		delete Q;
	}
	else
	{
		list<T> *L = new list<T>;
		std::cout <<"L = " << L << std::endl;
		L->_x = element;
		_first = _last = L;
		std::cout << "_first = " << _first << std::endl;
		L = NULL;
		delete L;
	}
	std::cout << "_first after push = " << _first << std::endl;
	++_size;
}
template<class T>
void queue<T>::pop()
{
	if (_size == 1)
	{
		delete _last;
		_first = NULL;
		_last = _first;
	}
	if (_size > 1)
	{
     		list<T> *FIRST = _first;
		_first = _first->_next;
		delete FIRST;
	}
	if (_size <= 0)
		throw 1;
	else
		--_size;
}
template<class T>
bool queue<T>::operator==(const queue<T> &other)
{
	if (_size != other._size)
		return false;
	list<T> *FIRST = _first;
	list<T> *OTHERFIRST = other._first;
	while (FIRST != _last)
	{
		if (FIRST->_x != OTHERFIRST->_x)
			return false;
		FIRST = FIRST->_next;
		OTHERFIRST = OTHERFIRST->_next;
	}
	if (_last->_x != other._last->_x)
		return false;
	return true;
}
template<class T>
bool queue<T>::operator!=(const queue<T> &other)
{
	return !((*this) == other);
}
template<class T>
queue<T>& queue<T>::operator=(const queue<T>& other) {
	std::cout << "FUNCTION  = " << std::endl;
	list<T> *FIRST = other._first;
	std::cout << "_first = " << _first << std::endl;
	std::cout << "other._first = " << other._first << std::endl;
	std::cout << "_size = " << _size << std::endl;
	if (_size == 0)
		delete _first;
	if (_size > 0)
		(*this).clear();
	while (FIRST != NULL){
		(*this).push(FIRST->_x);
		FIRST = FIRST->_next;
		std::cout << "FIRST = " << FIRST << std::endl;
	}
	return *this;
}
template<class T>
void queue<T>::QueueSort() {
	list<T> *FIRST = _first;
	while (_first != 0) {
		T min = _first->_x;
		list<T> *Qmin = _first;
		list<T> *_FIRST = _first;
		while (_FIRST != 0) {
			if (_FIRST->_x < min) {
				min = _FIRST->_x;
				Qmin = _FIRST;
			}
			_FIRST = _FIRST->_next;
		}
		T tmp = _first->_x;
		_first->_x = min;
		Qmin->_x = tmp;
		_first = _first->_next;
	}
	_first = FIRST;
}


#endif
