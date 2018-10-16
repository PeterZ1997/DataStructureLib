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

	//���Ա����鱾��
	T *LTdata = NULL;

	//���Ա���
	size_t len = 0;

	//���Ա��ѷ���ռ��С
	size_t spaceSize = 0;
public:

	// ���Ա��캯����Ĭ�ϳ�ʼ��
	ZLinearTable();

	// ���Ա��캯��������vector��ʼ��
	ZLinearTable(std::vector<T> vec);

	// ����������
	~ZLinearTable();

	// ��ȡ���Ա�ָ��λ�õ�Ԫ��
	bool GetElem(size_t loc, T& elem);

	// ��ȡ���Ա�ָ��λ�õ�Ԫ��
	T At(size_t loc);

	// �����Ա�ָ��λ�ò���Ԫ��
	bool InsertElem(size_t loc, T elem);

	// �����Ա��ĩβ����Ԫ��
	bool AddElem(T elem);

	// ɾ�����Ա��е�ָ��Ԫ��
	bool DeleteElem(size_t loc);

	// �ж����Ա��Ƿ�Ϊ��
	bool IsEmpty();

	// ������Ա�
	bool ClearList();

	// ��ȡ���Ա���
	bool GetListLength(size_t& in_len);

	// ��ȡ���Ա��ѷ���ռ�
	bool GetListSize(size_t& in_len);

	// ��λ���Ա��е�һ������Ҫ���Ԫ�ص��±꣬��0��ʼ
	bool LocateFirstElem(T elem, size_t& in_loc);

	// ��λ���Ա������з���Ҫ���Ԫ�ص��±겢��˳����vector��ʽ���أ���0��ʼ��
	bool LocateAllElem(T elem, std::vector<size_t> vec);

	// ��vector��ʽ�������Ա���������
	bool GetAllListData(std::vector<T> vec);

	// ���ؼӺ��������������Ա���ӵ�����
	ZLinearTable<T> operator +(ZLinearTable<T>& zlt);

	// �������Ԫ��
	bool ShowAllElem();
};


// ���Ա��캯����Ĭ�ϳ�ʼ��
template<typename T>
ZLinearTable<T>::ZLinearTable()
{
	LTdata = (T*)malloc(sizeof(T)*DETAIL_SIZE);
	memset(LTdata, 0, DETAIL_SIZE);
	spaceSize += DETAIL_SIZE;
}

// ���Ա��캯��������vector��ʼ��
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

// ����������
template<typename T>
ZLinearTable<T>::~ZLinearTable()
{
	len = 0;
	spaceSize = 0;
	free(LTdata);
}

// ��ȡ���Ա�ָ��λ�õ�Ԫ��
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

// ��ȡ���Ա�ָ��λ�õ�Ԫ��
template<typename T>
T ZLinearTable<T>::At(size_t loc)
{
	return LTdata[loc];
}

// �����Ա�ָ��λ�ò���Ԫ��
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

// �����Ա��ĩβ����Ԫ��
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

// ɾ�����Ա��е�ָ��Ԫ��
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

// �ж����Ա��Ƿ�Ϊ��
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

// ������Ա�
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

// ��ȡ���Ա���
template<typename T>
bool ZLinearTable<T>::GetListLength(size_t& in_len)
{
	in_len = len;
	return true;
}

// ��ȡ���Ա��ѷ���ռ�
template<typename T>
bool ZLinearTable<T>::GetListSize(size_t& in_len)
{
	in_len = spaceSize;
	return true;
}

// ��λ���Ա��е�һ������Ҫ���Ԫ�ص��±�
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

// ��λ���Ա������з���Ҫ���Ԫ�ص��±겢��˳����vector��ʽ����
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

// ��vector��ʽ�������Ա���������
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

// ���ؼӺ��������������Ա���ӵ�����
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

// ������������
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