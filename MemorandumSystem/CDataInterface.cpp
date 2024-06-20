#include "pch.h"
#include "CDataInterface.h"

bool CDataInterface::Open(CString FilePath)
{
    ifstream in(FilePath, ios::in);

    if (in.is_open());
    {
        int num;    //����
        in >> num;
        for (int i = 0; i < num; i++)
        {
            Cinfo MyInfo;
            MyInfo.Load(in);  //������
            Info.push_back(MyInfo);
            
        }
        return true;
    }
    return false;
}
//�����������ݷ���
void CDataInterface::Add(Cinfo MyInfo)
{
    Info.push_back(MyInfo);
}
//����ɾ�����ݷ���
void CDataInterface::Del(int index)
{
    Info.erase(Info.begin() + index);
}
//�����޸ļ�¼����
void CDataInterface::amend(int index, Cinfo MyInfo)
{
    Info[index] = MyInfo;
}

Cinfo CDataInterface::Find(int id)
{
    for (int i = 0; i < Info.size(); i++)//Ѱ��
    {
        if (Info[i].m_id == id) return Info[i];//�ҵ�����
    }
    return Cinfo(-1, TEXT(""), TEXT(""), TEXT(""), TEXT(""));   //û�ҵ����ؿ�
    
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
