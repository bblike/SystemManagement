// ChildDlg.cpp: 实现文件
//

#include "pch.h"
#include "MemorandumSystem.h"
#include "afxdialogex.h"
#include "ChildDlg.h"


// ChildDlg 对话框

IMPLEMENT_DYNAMIC(ChildDlg, CDialogEx)

ChildDlg::ChildDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChildDlg, pParent)
	, m_id(_T(""))
	, m_lastname(_T(""))
	, m_firstname(_T(""))
	, m_date(_T(""))
	, m_content(_T(""))
{

}

ChildDlg::~ChildDlg()
{
}

void ChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT2, m_lastname);
	DDX_Text(pDX, IDC_EDIT3, m_firstname);
	DDX_Text(pDX, IDC_EDIT5, m_date);
	DDX_Text(pDX, IDC_EDIT4, m_content);
}


BEGIN_MESSAGE_MAP(ChildDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ChildDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &ChildDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &ChildDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// ChildDlg 消息处理程序

//返回按钮
void ChildDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}


void ChildDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

//确定按钮
void ChildDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_id == TEXT("") || m_lastname == TEXT("") || m_firstname == TEXT("") || m_date == TEXT("") || m_content == TEXT(""))
	{
		MessageBox(TEXT("empty input!!"), TEXT("error"));

	}
	else 
	{
		OnOK();
		return;

	}
}
