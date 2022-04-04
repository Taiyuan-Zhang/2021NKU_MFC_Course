
// HW1_1View.cpp: CHW11View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HW1_1.h"
#endif

#include "HW1_1Doc.h"
#include "HW1_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_MY_MESSAGE WM_USER+1
// CHW11View

IMPLEMENT_DYNCREATE(CHW11View, CView)

BEGIN_MESSAGE_MAP(CHW11View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_MESSAGE(WM_MY_MESSAGE, &CHW11View::OnMyMessage)
END_MESSAGE_MAP()

// CHW11View 构造/析构

CHW11View::CHW11View() noexcept
{
	// TODO: 在此处添加构造代码
	my_pos = CPoint(0, 0);
	my_str = _T("");
}

CHW11View::~CHW11View()
{
}

BOOL CHW11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHW11View 绘图

void CHW11View::OnDraw(CDC* pDC)
{
	CHW11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(0, 0, L"识别的功能键为Delete，End");
	pDC->TextOutW(my_pos.x, my_pos.y, my_str);
	// TODO: 在此处为本机数据添加绘制代码
}


// CHW11View 打印

BOOL CHW11View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHW11View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHW11View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CHW11View 诊断

#ifdef _DEBUG
void CHW11View::AssertValid() const
{
	CView::AssertValid();
}

void CHW11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHW11Doc* CHW11View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHW11Doc)));
	return (CHW11Doc*)m_pDocument;
}
#endif //_DEBUG


// CHW11View 消息处理程序


void CHW11View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar == '#')
		SendMessage(WM_MY_MESSAGE, 10, 100);
	else{
		CString str;
		str.Format(L"Key Information: %c", nChar);
		MessageBox(str);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CHW11View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	my_pos = point;
	if (MK_CONTROL & nFlags)
		my_str.Format(L"Right Mouse Button (%d, %d)", point.x, point.y);
	else
		my_str.Format(L"Left Mouse Button (%d, %d)", point.x, point.y);
	Invalidate(true);
	CView::OnLButtonDown(nFlags, point);
}


afx_msg LRESULT CHW11View::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	CString str;
	str.Format(L"自定义消息 (%d, %d)", wParam, lParam);
	MessageBox(str);
	return 0;
}


BOOL CHW11View::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN){
		if (pMsg->wParam == VK_DELETE)
			MessageBox(L"Key Information: Delete");
		else if (pMsg->wParam == VK_END)
			MessageBox(L"Key Information: End");
	}
	return CView::PreTranslateMessage(pMsg);
}
