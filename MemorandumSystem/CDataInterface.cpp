#include "pch.h"
#include "CDataInterface.h"

bool CDataInterface::Open(CString FilePath)
{
    ifstream in(FilePath, ios::in);

    if (in.is_open());
    {
        int num;    //行数
        in >> num;
        for (int i = 0; i < num; i++)
        {
            Cinfo MyInfo;
            MyInfo.Load(in);  //读数据
            Info.push_back(MyInfo);
            
        }
        return true;
    }
    return false;
}
//定义增加数据方法
void CDataInterface::Add(Cinfo MyInfo)
{
    Info.push_back(MyInfo);
}
//定义删除数据方法
void CDataInterface::Del(int index)
{
    Info.erase(Info.begin() + index);
}
//定义修改记录方法
void CDataInterface::amend(int index, Cinfo MyInfo)
{
    Info[index] = MyInfo;
}

Cinfo CDataInterface::Find(int id)
{
    for (int i = 0; i < Info.size(); i++)//寻找
    {
        if (Info[i].m_id == id) return Info[i];//找到返回
    }
    return Cinfo(-1, TEXT(""), TEXT(""), TEXT(""), TEXT(""));   //没找到返回空
    
}

bool CDataInterface::Save(CString Filepath)
{
    ofstream out(Filepath, ios::out);
    bool flag = out.is_open();
    if (out.is_open())
    {
        out << Info.size() << endl;
        for (int i = 0; i < Info.size(); i++)
        {
            Info[i].Save(out);
        }
        out.close();
        return true;
    }
    return false;
}
