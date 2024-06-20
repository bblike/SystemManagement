#pragma once
#include "Cinfo.h"
class CDataInterface
{
public:
	bool Open(CString Filepath);
	void Add(Cinfo MyInfo);
	void Del(int index);
	void amend(int index, Cinfo MyInfo);
	Cinfo Find(int id);
	bool Save(CString Filepath);

	vector<Cinfo> Info;
};

