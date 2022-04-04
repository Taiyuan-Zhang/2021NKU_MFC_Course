
// HW4View.cpp: CHW4View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HW4.h"
#endif

#include "HW4Doc.h"
#include "HW4View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHW4View

IMPLEMENT_DYNCREATE(CHW4View, CView)

BEGIN_MESSAGE_MAP(CHW4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_BUTTON32774, &CHW4View::OnButton32774)
END_MESSAGE_MAP()

// CHW4View 构造/析构

CHW4View::CHW4View() noexcept
{
	// TODO: 在此处添加构造代码

	my_name = _T("");
	my_id = _T("");
	my_age = _T("");
	my_gender = _T("");
	my_nation = _T("");
	home = _T("");
	my_party = _T("");
	my_birthday = _T("");
	ok = false;
}

CHW4View::~CHW4View()
{
}

BOOL CHW4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHW4View 绘图

void CHW4View::OnDraw(CDC* pDC)
{
	CHW4Doc* pDoc = GetDocument();
	pMDoc = GetDocument();
	pMDoc->Get(my_name, my_id, my_age, my_gender, my_party, home, my_nation, my_birthday);

	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (ok|pMDoc->Save) {
		pDC->SetBkMode(OPAQUE);
		pDC->SetBkColor(RGB(125, 125, 125));
		pDC->SetTextCharacterExtra(4);
		pDC->TextOutW(60, 10, pMDoc->Name);
		pDC->TextOutW(60, 40, pMDoc->Id);
		pDC->TextOutW(60, 70, pMDoc->Gender);
		pDC->TextOutW(60, 100, pMDoc->Age);
		pDC->TextOutW(60, 130, pMDoc->Nation);
		pDC->TextOutW(60, 160, pMDoc->Birthday);
		pDC->TextOutW(60, 190, pMDoc->Party);
		pDC->TextOutW(60, 220, pMDoc->Home);
		pDC->TextOutW(80, 270, _T("照片"));
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP1);
		CDC memDC;
		memDC.CreateCompatibleDC(pDC);
		memDC.SelectObject(&bm);
		BITMAP info;
		bm.GetBitmap(&info);
		pDC->BitBlt(50, 270, info.bmWidth, info.bmHeight, &memDC, 0, 0, SRCCOPY);
		bm.DeleteObject();
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CHW4View 打印

BOOL CHW4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHW4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHW4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CHW4View 诊断

#ifdef _DEBUG
void CHW4View::AssertValid() const
{
	CView::AssertValid();
}

void CHW4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHW4Doc* CHW4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHW4Doc)));
	return (CHW4Doc*)m_pDocument;
}
#endif //_DEBUG


// CHW4View 消息处理程序


void CHW4View::OnButton32774()
{
	// TODO: 在此添加命令处理程序代码
	MyDialog dlg;
	pMDoc = GetDocument();
	if (dlg.DoModal() == IDOK) {
		my_name = _T("姓名： ") + dlg.name;
		my_id = _T("学号： ") + dlg.id;
		my_age.Format(_T("%d"), dlg.age);
		my_age = _T("年龄： ") + my_age;
		if (dlg.gender)
			my_gender = "性别： 女";
		else
			my_gender = "性别： 男";
		my_party = _T("学院： ") + dlg.party;
		home = _T("籍贯： ") + dlg.hometown;
		my_birthday = dlg.birthday.Format(L"出生日期： %Y-%m-%d");
		my_nation = _T("民族： ") + dlg.nation;
		ok = true;
		pMDoc->Set(my_name, my_id, my_age, my_gender, my_party, home, my_nation, my_birthday);
		Invalidate();
	}
}
