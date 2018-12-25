#pragma once
#ifndef _GRAPH_H_
#define _GRAPH_H_
#include<string>
#include "headlist.h"
template <typename T>
class graph;
template <typename T>
class Linklist;


template <typename T>  //超类（抽象类）
class graph
{
public:
	virtual ~graph() {};
	virtual int numberofvertices()const = 0; //纯虚函数
	virtual int numberofedges()const = 0;
	virtual bool existedge(T, T) = 0;
	virtual void insertedge(T, T) = 0;


};
template<typename T>
class linkgraph : public graph<T>
{
private:
	int n;
	int e;
	Linklist<T>* alist;
public:
	linkgraph(int number = { 0 }) { n = number; e = 0; alist = new Linklist<T>[n]; }
	~linkgraph() override {  }
	int numberofvertices()const override;
	int numberofedges()const override;
	bool existedge(T c1, T c2);
	void insertedge(T c1, T c2);
	void mark(std::string str);
	Linklist<T>* getthenode(char c1);

};


template<typename T>
int linkgraph<T>::numberofedges()const
{
	return e;
}

template<typename T>
int linkgraph<T>:: numberofvertices()const
{
	return n;
}
template<typename T>
bool linkgraph<T>::existedge(T c1, T c2)
{
	for (int i = 0; i < n; ++i)
	{
		if (alist[i].get_elementptr()->element == c1)
			return alist[i].contains(c2);
	}
	return false;
}
template<typename T>
void linkgraph<T>::insertedge(T c1, T c2)
{
	if(this->existedge(c1,c2)==1&& this->existedge(c2, c1) == 1)
	return;
	else {
		for (int i = 0; i < n;++i)
			if (alist[i].get_elementptr()->element == c1)
			{
				alist[i].insert(c2);
				++e;
			}
		for (int i = 0; i < n; ++i)
			if (alist[i].get_elementptr()->element == c2)
			{
				alist[i].insert(c1);
			}
		
	}
}


template<typename T>
void linkgraph<T>::mark(std::string str)
{
	int i = 0;
	for( auto &s:str)
		{
			alist[i].get_elementptr()->element = s;
	++i;
		}
	return;
}


template<typename T>
inline Linklist<T>* linkgraph<T>::getthenode(char c1)
{
	for (int i = 0; i < n; ++i)
	{
		if (alist[i].get_elementptr()->element == c1)
			return &alist[i];

	}
}


#endif










