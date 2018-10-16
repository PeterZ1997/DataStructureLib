#pragma once
#ifndef _LINEARTABLE_H
#define _LINEARTABLE_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <assert.h>
#include <vector>

#endif

const size_t DETAIL_SIZE = 255;

template<typename T>
class ZLinearTable {
private:

	//线性表数组本体
	T *LTdata = NULL;

	//线性表长度
	size_t len = 0;

	//线性表已分配空间大小
	size_t spaceSize = 0;
public:

	// 线性表构造函数，默认初始化
	ZLinearTable();

	// 线性表构造函数，根据vector初始化
	ZLinearTable(std::vector<T> vec);

	//拷贝构造函数
	ZLinearTable(const ZLinearTable& z);

	// 类析构函数
	~ZLinearTable();

	// 获取线性表指定位置的元素
	bool GetElem(size_t loc, T& elem);

	// 获取线性表指定位置的元素
	T At(size_t loc);

	// 往线性表指定位置插入元素
	bool InsertElem(size_t loc, T elem);

	// 往线性表的末尾增加元素
	bool AddElem(T elem);

	// 删除线性表中的指定元素
	bool DeleteElem(size_t loc);

	// 判断线性表是否为空
	bool IsEmpty();

	// 清空线性表
	bool ClearList();

	// 获取线性表长度
	bool GetListLength(size_t& in_len);

	// 获取线性表已分配空间
	bool GetListSize(size_t& in_len);

	// 定位线性表中第一个符合要求的元素的下标，从0开始
	bool LocateFirstElem(T elem, size_t& in_loc);

	// 定位线性表中所有符合要求的元素的下标并按顺序以vector形式返回，从0开始！
	bool LocateAllElem(T elem, std::vector<size_t> vec);

	// 以vector形式返回线性表所有内容
	bool GetAllListData(std::vector<T> vec);

	// 重载加号运算符，解决线性表相加的问题
	ZLinearTable<T> operator +(ZLinearTable<T>& zlt);

	// 输出所有元素
	bool ShowAllElem();
};


// 线性表构造函数，默认初始化
template<typename T>
ZLinearTable<T>::ZLinearTable()
{
	LTdata = (T*)malloc(sizeof(T)*DETAIL_SIZE);
	memset(LTdata, 0, DETAIL_SIZE);
	spaceSize += DETAIL_SIZE;
}

// 线性表构造函数，根据vector初始化
template<typename T>
ZLinearTable<T>::ZLinearTable(std::vector<T> vec) :len(vec.size())
{
	assert(vec.empty());
	LTdata = (T*)malloc(sizeof(T)*DETAIL_SIZE);
	memset(LTdata, 0, DETAIL_SIZE);
	spaceSize += DETAIL_SIZE;
	for (size_t i = 0; i < vec.size(); i++)
	{
		LTdata[i] = vec[i];
	}
}

template<typename T>
ZLinearTable<T>::ZLinearTable(const ZLinearTable& z)
{
	size_t unSize = 0;
	size_t unLen = 0;
	GetListSize(unSize);
	LTdata = (T*)malloc(sizeof(T)*unSize);
	memset(LTdata, 0, unSize);
	for (size_t i = 0; i < unLen; i++)
	{
		LTdata[i] = z.At(i);
	}
	len = unLen;
	spaceSize = unSize;
}

// 类析构函数
template<typename T>
ZLinearTable<T>::~ZLinearTable()
{
	len = 0;
	spaceSize = 0;
	free(LTdata);
}

// 获取线性表指定位置的元素
template<typename T>
bool ZLinearTable<T>::GetElem(size_t loc, T& elem)
{
	if (len == 0 || loc < 0 || loc >= len)
	{
		return false;
	}
	elem = LTdata[loc];
	return true;
}

// 获取线性表指定位置的元素
template<typename T>
T ZLinearTable<T>::At(size_t loc)
{
	return LTdata[loc];
}

// 往线性表指定位置插入元素
template<typename T>
bool ZLinearTable<T>::InsertElem(size_t loc, T elem)
{
	if (loc > len || loc < 0)
	{
		return false;
	}
	if (len == spaceSize)
	{
		try
		{
			LTdata = (T*)realloc(LTdata, len + DETAIL_SIZE);
			memset(LTdata + len, 0, DETAIL_SIZE);
		}
		catch (...)
		{
			return false;
		}
		spaceSize += DETAIL_SIZE;
	}
	for (size_t i = len; i > loc; i--)
	{
		LTdata[i] = LTdata[i - 1];
	}
	LTdata[loc] = elem;
	len += 1;
	return true;
}

// 往线性表的末尾增加元素
template<typename T>
bool ZLinearTable<T>::AddElem(T elem)
{
	if (len == spaceSize)
	{
		try
		{
			LTdata = (T*)realloc(LTdata, len + DETAIL_SIZE);
			memset(LTdata + len, 0, DETAIL_SIZE);
		}
		catch (...)
		{
			return false;
		}
		spaceSize += DETAIL_SIZE;
	}
	LTdata[len] = elem;
	len++;
	return true;
}

// 删除线性表中的指定元素
template<typename T>
bool ZLinearTable<T>::DeleteElem(size_t loc)
{
	if (len == 0 || loc < 0 || loc >= len)
	{
		return false;
	}
	for (size_t i = loc + 1; i < len; i++)
	{
		LTdata[i - 1] = LTdata[i];
	}
	LTdata[len - 1] = 0;
	len -= 1;
	return true;
}

// 判断线性表是否为空
template<typename T>
bool ZLinearTable<T>::IsEmpty()
{
	if (len == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 清空线性表
template<typename T>
bool ZLinearTable<T>::ClearList()
{
	if (len == 0)
	{
		return false;
	}
	for (size_t i = 0; i < len; i++)
	{
		LTdata[i] = 0;
		len = 0;
	}
	return true;
}

// 获取线性表长度
template<typename T>
bool ZLinearTable<T>::GetListLength(size_t& in_len)
{
	in_len = len;
	return true;
}

// 获取线性表已分配空间
template<typename T>
bool ZLinearTable<T>::GetListSize(size_t& in_len)
{
	in_len = spaceSize;
	return true;
}

// 定位线性表中第一个符合要求的元素的下标
template<typename T>
bool ZLinearTable<T>::LocateFirstElem(T elem, size_t& in_loc)
{
	for (size_t i = 0; i < len; i++)
	{
		if (LTdata[i] == elem)
		{
			in_loc = i;
			break;
		}
		if (i == len - 1)
		{
			return false;
		}
	}
	return true;
}

// 定位线性表中所有符合要求的元素的下标并按顺序以vector形式返回
template<typename T>
bool ZLinearTable<T>::LocateAllElem(T elem, std::vector<size_t> vec)
{
	if (!vec.empty())
	{
		vec.clear();
	}
	for (size_t i = 0; i < len; i++)
	{
		if (LTdata[i] == elem)
		{
			vec.push_back(i);
		}
		if (i == len - 1 && vec.empty())
		{
			return false;
		}
	}
	return true;
}

// 以vector形式返回线性表所有内容
template<typename T>
bool ZLinearTable<T>::GetAllListData(std::vector<T> vec)
{
	if (!vec.empty())
	{
		vec.clear();
	}
	for (size_t i = 0; i < len; i++)
	{
		vec.push_back(LTdata[i]);
	}
	return true;
}

// 重载加号运算符，解决线性表相加的问题
template<typename T>
ZLinearTable<T> ZLinearTable<T>::operator +(ZLinearTable<T>& zlt)
{
	ZLinearTable this_zlt(this);
	size_t in_len = 0;
	zlt.GetListLength(in_len);
	for (size_t i = 0; i < in_len; i++)
	{
		this_zlt.AddElem(zlt.At(i));
	}
	return this_zlt;
}

// 重载输出运算符
template<typename T>
std::ostream& operator <<(std::ostream& os, ZLinearTable<T>& zlb)
{
	size_t in_len = 0;
	zlb.GetListLength(in_len);
	os << "<ZLinearTable Object>( ";
	for (size_t i = 0; i < in_len; i++)
	{
		os << zlb.At(i);
		if (i != in_len - 1)
		{
			os << ", ";
		}
	}
	os << " )" << std::endl;
	return os;
}

template<typename T>
bool ZLinearTable<T>::ShowAllElem()
{
	size_t in_len = 0;
	GetListLength(in_len);
	std::cout << "<ZLinearTable Object>( ";
	for (size_t i = 0; i < in_len; i++)
	{
		std::cout << At(i);
		if (i != in_len - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << " )" << std::endl;
	return true;
}
