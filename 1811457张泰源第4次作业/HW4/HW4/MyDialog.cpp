// MyDialog.cpp: 实现文件
//

#include "pch.h"
#include "HW4.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

	nation = _T("汉族");
	name = _T("张泰源");
	id = _T("1811457");
	age = 21;
	hometown = _T("宁夏银川");
	party = _T("计算机学院");
	birthday = COleDateTime(2000,8,5,0,0,0);
	gender = false;
}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, birthday);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT3, age);
	DDX_Text(pDX, IDC_EDIT4, nation);
	DDX_Text(pDX, IDC_EDIT5, hometown);
	DDX_Text(pDX, IDC_EDIT2, id);
	DDX_Text(pDX, IDC_EDIT6, party);
	DDX_Radio(pDX, IDC_RADIO1, gender);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
END_MESSAGE_MAP()


// MyDialog 消息处理程序
