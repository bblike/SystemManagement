
// MemorandumSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MemorandumSystem.h"
#include "MemorandumSystemDlg.h"
#include "afxdialogex.h"

#include "ChildDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMemorandumSystemDlg 对话框



CMemorandumSystemDlg::CMemorandumSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEMORANDUMSYSTEM_DIALOG, pParent)
	, m_find(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemorandumSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_find);
}

BEGIN_MESSAGE_MAP(CMemorandumSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMemorandumSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMemorandumSystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMemorandumSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMemorandumSystemDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMemorandumSystemDlg::OnBnClickedButton6)
	ON_EN_CHANGE(IDC_EDIT1, &CMemorandumSystemDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON7, &CMemorandumSystemDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON3, &CMemorandumSystemDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMemorandumSystemDlg 消息处理程序

BOOL CMemorandumSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list.SetExtendedStyle(dwStyle);


	m_list.InsertColumn(0, TEXT("No"), 0, 150);
	m_list.InsertColumn(1, TEXT("Last name"), 0, 150);
	m_list.InsertColumn(2, TEXT("First name"), 0, 150);
	m_list.InsertColumn(3, TEXT("Date"), 0, 150);
	m_list.InsertColumn(4, TEXT("Content"), 0, 300);

	IsOpen = false;
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMemorandumSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMemorandumSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMemorandumSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//文件打开
void CMemorandumSystemDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);

	if (IDOK == fileDlg.DoModal())
	{
		strFilePath = fileDlg.GetPathName();

		DataInterface.Open(strFilePath);

		IsOpen = true;

		UpdateList();
	}
}

//保存功能
void CMemorandumSystemDlg::OnBnClickedButton2()
{
	if (IsOpen) {
	// TODO: 在此添加控件通知处理程序代码
		if (DataInterface.Save(strFilePath))
			MessageBox(TEXT("Saved!"), TEXT("Hint"));
		else
			MessageBox(TEXT("Save failed!"), TEXT("Hint"));
	}
	else {
		MessageBox(TEXT("No Files Opened."), TEXT("Hint."));
	}

}
//文件刷新
void CMemorandumSystemDlg::UpdateList()
{
	m_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < DataInterface.Info.size(); i++)
	{
		str.Format(TEXT("%d"), DataInterface.Info[i].m_id);
		m_list.InsertItem(i, str);
		m_list.SetItemText(i, 1, DataInterface.Info[i].m_lastname.c_str());
		m_list.SetItemText(i, 2, DataInterface.Info[i].m_firstname.c_str());
		m_list.SetItemText(i, 3, DataInterface.Info[i].m_date.c_str());
		m_list.SetItemText(i, 4, DataInterface.Info[i].m_content.c_str());
	}

}

//添加记录
void CMemorandumSystemDlg::OnBnClickedButton4()
{
	if (IsOpen)
	{
		// TODO: 在此添加控件通知处理程序代码
		ChildDlg dlg;
		if (IDOK == dlg.DoModal())
		{
			Cinfo Info(atoi(dlg.m_id), dlg.m_lastname.GetBuffer(), dlg.m_firstname.GetBuffer(), dlg.m_date.GetBuffer(), dlg.m_content.GetBuffer());
			DataInterface.Add(Info);
			UpdateList();
		}
	}
	else {
		MessageBox(TEXT("Not Open Any Files."), TEXT("Hint."));
	}
}

//删除记录
void CMemorandumSystemDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_list.GetSelectionMark();	//获取所以列表
	if (index > -1)	//判断是否为空
	{
		UINT i;
		i = MessageBox(_T("Sure you want to delete this?"), _T("Hint"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			DataInterface.Del(index);
			UpdateList();
			MessageBox(TEXT("delete successful!"));
		}
	}
	else
	{
		MessageBox(TEXT("Select one line first."), TEXT("note!"));
	}

}

//修改记录
void CMemorandumSystemDlg::OnBnClickedButton6()
{
	
	// TODO: 在此添加控件通知处理程序代码
	int index = m_list.GetSelectionMark();
	
	if (index > -1)
	{
		//读取已有信息
		ChildDlg dlg;
		CString str;
		str.Format(TEXT("%d"), DataInterface.Info[index].m_id);
		dlg.m_id = str;


		str.Format(TEXT("%s"), DataInterface.Info[index].m_lastname.c_str());
		dlg.m_lastname = str;


		str.Format(TEXT("%s"), DataInterface.Info[index].m_firstname.c_str());
		dlg.m_firstname = str;


		str.Format(TEXT("%s"), DataInterface.Info[index].m_date.c_str());
		dlg.m_date = str;


		str.Format(TEXT("%s"), DataInterface.Info[index].m_content.c_str());
		dlg.m_content = str;

		//修改记录
		if (IDOK == dlg.DoModal())
		{
			Cinfo Info(atoi(dlg.m_id), dlg.m_lastname.GetBuffer(), dlg.m_firstname.GetBuffer(), dlg.m_date.GetBuffer(), dlg.m_content.GetBuffer());
			DataInterface.amend(index, Info);
			UpdateList();
		}
	}
	else
	{
		MessageBox(TEXT("Select one line first."), TEXT("note!"));
	}
}


void CMemorandumSystemDlg::OnEnChangeEdit1()
{
	
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

//查找按钮
void CMemorandumSystemDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	
	Cinfo FindInfo = DataInterface.Find(atoi(m_find));
	if (IsOpen) {
		if (FindInfo.m_id == -1)
		{
			MessageBox(TEXT("Not Found!"), TEXT("Hint"));
		}
		else
		{
			CString str;
			str.Format(TEXT("Found! \n\n id: %d\n Lastname: %s\n Firstname: %s \n Date: %s\n Content: %s\n"),
				FindInfo.m_id, FindInfo.m_lastname.c_str(), FindInfo.m_firstname.c_str(), FindInfo.m_date.c_str(), FindInfo.m_content.c_str());
			MessageBox(str, TEXT("HINT"));
		}
	}
	else {
		MessageBox(TEXT("Files not Open yet."), TEXT("Hint"));
	}
}

//退出按钮
void CMemorandumSystemDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i;
	i = MessageBox(TEXT("Sure you wanna quit?"), _T("Hint"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES)
		exit(0);
	else
		return;
}
