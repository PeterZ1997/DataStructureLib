#pragma once
#ifndef _LINKTABLE_H
#define _LINKTABLE_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <assert.h>
#include <vector>

#endif

template<typename T>
struct ZLinkTableNode {
	T data;
	ZLinkTableNode* next;
};

typedef struct ZLinkTableNode ZLinkTableNode;

template<typename T>
class ZLinkTable
{
private:
	ZLinkTableNode *ZLTNode = NULL;
	size_t len = 0;
public:
	ZLinkTable();
	ZLinkTable(std::vector<T> v);
	~ZLinkTable();
	ZLinkTable(const ZLinkTable& zlt);
	bool AddElem(T elem);
	bool InsertElem(int loc, T elem);
	bool IsEmpty();
	bool Clear();
	bool GetElem(int loc, T& elem);
	bool DeleteElem(int loc);
	bool ShowAllElem(std::vector<T>& vec);
	ZLinkTable<T> operator +(ZLinkTable& zlt);
};

template<typename T>
ZLinkTable<T>::ZLinkTable()
{
	ZLTNode = (ZLinkTableNode*)malloc(sizeof(ZLinkTableNode));
	ZLTNode->next = NULL;
}

template<typename T>
ZLinkTable<T>::ZLinkTable(std::vector<T> v)
{
	assert(v == NULL || v.size() == 0);
	len = v.size();
	ZLTNode = (ZLinkTableNode*)malloc(sizeof(ZLinkTableNode));
	ZLinkTableNode *prevNode = ZLTNode;
	ZLinkTableNode *newNode = NULL;
	for (size_t i = 0; i <= len; i++)
	{
		if (i < len)
		{
			newNode = (ZLinkTableNode*)malloc(sizeof(ZLinkTableNode));
			newNode->data = v[i];
			prevNode->next = newNode;
			prevNode = newNode;
		}
		else
		{
			prevNode->next = NULL;
		}
	}
}

template<typename T>
ZLinkTable<T>::~ZLinkTable()
{
	this->Clear();
	free(ZLTNode);
}

template<typename T>
ZLinkTable<T>::ZLinkTable(const ZLinkTable& z)
{
	ZLTNode = z.ZLTNode;
	len = z.len;
}

template<typename T>
bool ZLinkTable<T>::AddElem(T elem)
{
	if (ZLTNode == NULL)
	{
		return false;
	}
	ZLinkTableNode *newNode = (*ZLinkTableNode)malloc(sizeof(ZLinkTableNode));
	ZLinkTableNode *searchNode = ZLTNode;
	while (searchNode->next != NULL)
	{
		searchNode = searchNode->next;
	}
	searchNode->next = newNode;
	newNode->data = elem;
	newNode->next = NULL;
	len++;
	return true;
}

template<typename T>
bool ZLinkTable<T>::InsertElem(int loc, T elem)
{
	if (ZLTNode == NULL || loc < 0)
	{
		return false;
	}
	ZLinkTableNode *newNode = (*ZLinkTableNode)malloc(sizeof(ZLinkTableNode));
	ZLinkTableNode *searchNode = ZLTNode;
	for (size_t i = 0; i <= (size_t)loc; i++)
	{
		searchNode = searchNode->next;
	}
	newNode->data = elem;
	newNode->next = searchNode->next;
	searchNode->next = newNode;
	len++;
	return true;
}

template<typename T>
bool ZLinkTable<T>::IsEmpty()
{
	if (len == 0)
	{
		return true;
	}
	return false;
}

template<typename T>
bool ZLinkTable<T>::Clear()
{
	ZLinkTable p = NULL, q = NULL;
	p = ZLTNode->next;
	while (p == NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	ZLTNode->next = NULL;
	len = 0;
	return true;
}

template<typename T>
bool ZLinkTable<T>::GetElem(int loc, T& elem)
{
	if (loc < 0 || ZLTNode == NULL)
	{
		return false;
	}
	ZLinkTableNode *searchNode = ZLTNode->next;
	for (size_t i = 0; i < (size_t)loc; i++)
	{
		searchNode = searchNode->next;
	}
	elem = searchNode->data;
	return true;
}

template<typename T>
bool ZLinkTable<T>::DeleteElem(int loc)
{
	if (ZLTNode == NULL || loc < 0)
	{
		return false;
	}
	ZLinkTableNode *searchNode = ZLTNode;
	for (size_t i = 0; i < (size_t)loc; i++)
	{
		searchNode = searchNode->next;
	}
	ZLinkTableNode *temp = searchNode->next;
	searchNode->next = searchNode->next->next;
	free(temp);
	len--;
	return true;
}

template<typename T>
bool ZLinkTable<T>::ShowAllElem(std::vector<T>& vec)
{
	if (vec == NULL)
	{
		return false;
	}
	if (vec, size() != 0)
	{
		vec.clear();
	}
	ZLinkTableNode *searchNode = ZLTNode->next;
	while (searchNode != NULL)
	{
		vec.push_back(searchNode->data);
		searchNode = searchNode->next;
	}
	return true;
}

template<typename T>
ZLinkTable<T> ZLinkTable<T>::operator +(ZLinkTable<T>& zlt)
{
	ZLinkTable zlt(this);
	//....
	return zlt;
}
