#pragma once

template<class T>
class TStack {
	T* pMem;
	int maxSize, num;
public:
	TStack(int);
	TStack& operator=(const TStack& t);
	bool empty() const;
	bool full() const;
	void push(T elem);
	T pop();
	T peek();
};

template<class T>
TStack<T>::TStack(int _maxSize) {
	maxSize = _maxSize;
	num = -1;
	pMem = new T[maxSize];
}

template<class T>
TStack<T>& TStack<T>::operator=(const TStack& ts) {
	if (this == &t) {
		return *this;
	}
	if (maxSize != ts.maxSize) {
		delete[] pMem;
		maxSize = ts.maxSize;
		pMem = new T[maxSize];
	}
	num = ts.num;
	for (int i = 0; i <= num; i++) {
		pMem[i] = ts.pMem[i];
	}

	return *this;
}

template<class T>
bool TStack<T>::empty() const {
	return num == -1;
}

template<class T>
bool TStack<T>::full() const {
	return num == maxSize - 1;
}

template<class T>
T TStack<T>::pop() {
	if (empty()) throw - 1;
	return pMem[num--];
}

template<class T>
void TStack<T>::push(T elem) {
	if (full()) throw - 1;
	pMem[++num] = elem;
}

template<class T>
T TStack<T>::peek() {
	if (empty()) throw - 1;
	return pMem[num];
}