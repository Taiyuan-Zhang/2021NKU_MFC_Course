
// HW2_1View.cpp: CHW21View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HW2_1.h"
#endif

#include "HW2_1Doc.h"
#include "HW2_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHW21View

IMPLEMENT_DYNCREATE(CHW21View, CView)

BEGIN_MESSAGE_MAP(CHW21View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_DrawLine, &CHW21View::OnDrawline)
	ON_COMMAND(ID_DrawEllipse, &CHW21View::OnDrawellipse)
	ON_COMMAND(ID_DrawRectangle, &CHW21View::OnDrawrectangle)
	ON_COMMAND(ID_DrawRectangle, &CHW21View::OnDrawrectangle)
END_MESSAGE_MAP()

// CHW21View 构造/析构

CHW21View::CHW21View() noexcept
{
	// TODO: 在此处添加构造代码

}

CHW21View::~CHW21View()
{
}

BOOL CHW21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHW21View 绘图

void CHW21View::OnDraw(CDC* pDC)
{
	CHW21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	Invalidate(false);
	CString type = pDoc->GetType();
	CPoint point = pDoc->GetPoint();
	if (type == "Line") {
		CDC* pDC = GetDC();
		CPen newPen;
		newPen.CreatePen(PS_SOLID, 8, RGB(255, 0, 0));
		pDC->SelectObject(newPen);
		pDC->MoveTo(point.x, point.y);
		pDC->LineTo(point.x, point.y + 300);
		ReleaseDC(pDC);
	}
	else if (type == "Ellipse") {
		CDC* pDC = GetDC();
		CBrush newBrush;
		newBrush.CreateSolidBrush(RGB(0, 255, 0));
		pDC->SelectObject(newBrush);
		CPen newPen;
		newPen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
		pDC->SelectObject(newPen);
		pDC->Ellipse(point.x, point.y, point.x + 200, point.y + 300);
		ReleaseDC(pDC);
	}
	else if (type == "Rectangle") {
		CDC* pDC = GetDC();
		CBrush newBrush;
		newBrush.CreateSolidBrush(RGB(0, 0, 255));
		pDC->SelectObject(newBrush);
		CPen newPen;
		newPen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
		pDC->SelectObject(newPen);
		pDC->Rectangle(point.x, point.y, point.x + 200, point.y + 300);
		ReleaseDC(pDC);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CHW21View 打印

BOOL CHW21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHW21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHW21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CHW21View 诊断

#ifdef _DEBUG
void CHW21View::AssertValid() const
{
	CView::AssertValid();
}

void CHW21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHW21Doc* CHW21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHW21Doc)));
	return (CHW21Doc*)m_pDocument;
}
#endif //_DEBUG


// CHW21View 消息处理程序


void CHW21View::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: 在此处添加消息处理程序代码
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pMenu = menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
	mousePoint = point;
}


void CHW21View::OnDrawline()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
	CDC* pDC = GetDC();
	CPen newPen;
	newPen.CreatePen(PS_SOLID, 8, RGB(255, 0, 0));
	pDC->SelectObject(newPen);
	pDC->MoveTo(mousePoint.x, mousePoint.y);
	pDC->LineTo(mousePoint.x, mousePoint.y+300);
	CHW21Doc* pDoc = GetDocument();
	CString str = _T("Line");
	CPoint point = mousePoint;
	pDoc->SetData(str, point);
	ReleaseDC(pDC);
}


void CHW21View::OnDrawellipse()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
	CDC* pDC = GetDC();
	CBrush newBrush;
	newBrush.CreateSolidBrush(RGB(0, 255, 0));
	pDC->SelectObject(newBrush);
	CPen newPen;
	newPen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	pDC->SelectObject(newPen);
	pDC->Ellipse(mousePoint.x, mousePoint.y, mousePoint.x+200, mousePoint.y+300);
	CHW21Doc* pDoc = GetDocument();
	CString str = _T("Ellipse");
	CPoint point = mousePoint;
	pDoc->SetData(str, point);
	ReleaseDC(pDC);
}


void CHW21View::OnDrawrectangle()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
	CDC* pDC = GetDC();
	CBrush newBrush;
	newBrush.CreateSolidBrush(RGB(0, 0, 255));
	pDC->SelectObject(newBrush);
	CPen newPen;
	newPen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	pDC->SelectObject(newPen);
	pDC->Rectangle(mousePoint.x, mousePoint.y, mousePoint.x + 200, mousePoint.y + 300);
	CHW21Doc* pDoc = GetDocument();
	CString str = _T("Rectangle");
	CPoint point = mousePoint;
	pDoc->SetData(str, point);
	ReleaseDC(pDC);
}
