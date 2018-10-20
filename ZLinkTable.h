/******************************
*
* FileName : ZLinkTable.h
* Author : PeterZ
* Date : 2018.10.20
* Comment : 链表操作库
*
******************************/

#pragma once
#ifndef _ZLINKTABLE_H
#define _ZLINKTABLE_H

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

	// 头指针，无data项
	ZLinkTableNode *ZLTNode = NULL;

	// 链表长度
	size_t len = 0;

public:

	ZLinkTable();
	ZLinkTable(std::vector<T> v);
	~ZLinkTable();
	ZLinkTable(const ZLinkTable& zlt);

	// 添加元素
	bool AddElem(T elem);

	// 插入元素
	bool InsertElem(const int loc, T elem);

	// 判断链表是否为空
	bool IsEmpty();

	// 链表清空
	bool Clear();

	// 取得元素
	bool GetElem(const int loc, T& elem);

	// 删除元素
	bool DeleteElem(const int loc);

	// 查看所有元素
	bool ShowAllElem(std::vector<T>& vec);

	// 返回链表长度
	bool GetLength(size_t& in_len);

	// 返回指定下标位置的值
	T At(const int loc);

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

// 添加元素
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

// 插入元素
template<typename T>
bool ZLinkTable<T>::InsertElem(const int loc, T elem)
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

// 判断链表是否为空
template<typename T>
bool ZLinkTable<T>::IsEmpty()
{
	if (len == 0)
	{
		return true;
	}
	return false;
}

// 链表清空
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

// 取得元素
template<typename T>
bool ZLinkTable<T>::GetElem(const int loc, T& elem)
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

// 删除元素
template<typename T>
bool ZLinkTable<T>::DeleteElem(const int loc)
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

// 查看所有元素
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

// 返回链表长度
template<typename T>
bool ZLinkTable<T>::GetLength(size_t& in_len)
{
	in_len = len;
	return true;
}

// 返回指定下标位置的值
template<typename T>
T ZLinkTable<T>::At(const int loc)
{
	assert(ZLTNode == NULL || loc < 0);
	ZLinkTableNode *searchNode = ZLTNode->next;
	for (size_t i == 0; i < (size_t)loc; i++)
	{
		searchNode = searchNode->next;
	}
	return searchNode->data;
}

template<typename T>
ZLinkTable<T> ZLinkTable<T>::operator +(ZLinkTable<T>& zlt)
{
	size_t _in_zlt_len = 0;
	zlt.GetLength(_in_zlt_len);
	ZLinkTable this_zlt(this);
	for (size_t i = 0; i < _in_zlt_len; i++)
	{
		this_zlt.AddElem(zlt.At(i));
	}
	return this_zlt;
}

template<typename T>
std::ostream& operator <<(std::ostream& os, ZLinkTable<T>& zlt)
{
	size_t _in_zlt_len = 0;
	zlt.GetLength(_in_zlt_len);
	os << "<ZLinkTable Object>( ";
	for (size_t i = 0; i < _in_zlt_len; i++)
	{
		if (i < _in_zlt_len - 1)
		{
			os << zlt.At(i) << ", ";
		}
		else
		{
			os << zlt.At(i) << " )";
		}
	}
}
