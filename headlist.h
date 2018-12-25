#pragma once
template <typename T>
class Linklist;
template<typename T>
class it;
template<typename T>
struct Node
{
	T  element;
	Node *next;
	Node(T t = T{}, Node* n = { nullptr }) :element{ t }, next{ n } {}


};

template<typename T>
class Linklist
{
	friend class it<T>;
public:
	Linklist( ) { init(); }
	~Linklist() { }
	int size() { return thesize; }
	bool contains(const T& d);
	void insert(const T& x);
	Node<T>* get_elementptr() { return elementnode; }
	void printf();
	bool empty() { return !thesize; };
	Node<T>* get_talinode() { return tail; }
	it<T> begin() { return{ elementnode->next }; }
	it<T> end() { return{ tail }; }

	



private:
	Node<T>* elementnode;
	Node<T>* tail;
	int thesize;
	void init();

};

template<typename T>
class it {
public:
	friend class Linklist<T>;
	it() :current{ nullptr } {}
	it(Node<T>* d) :current{ d } {}
	const T& operator*()const { return this->current->element; }
	it &operator++() {
		current = current->next;
		return *this;
	}
	bool operator==(const it& rhs)const
	{
		return current == rhs.current;
	}

	bool operator!=(const it& rhs)const
	{
		return !(*this == rhs);
	}
protected:
	Node<T>* current;

};

template<typename T>
bool Linklist<T>::contains(const T& d )
{
	for (it<T> begin1 = this->begin(); begin1 != this->end(); ++begin1)
	{
		if (*begin1== d)
			return true;
	}
	return false;

}

template<typename T>
void Linklist<T>::insert(const T& x)
{
	if (contains(x))
		return;
	Node<T>* newnode = new Node<T>{ x,this->elementnode->next };
		newnode->next = elementnode->next;
		elementnode->next = newnode;
		++thesize;
		return;

}


template<typename T>
void Linklist<T>::init()
{
	thesize = 0;
	tail = new Node<T>;
	elementnode = new Node<T>;
	elementnode->next = tail;
	return;
}
