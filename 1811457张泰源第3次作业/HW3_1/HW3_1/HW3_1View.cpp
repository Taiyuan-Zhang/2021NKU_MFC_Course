
// HW3_1View.cpp: CHW31View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HW3_1.h"
#endif

#include "HW3_1Doc.h"
#include "HW3_1View.h"
#include<iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHW31View

IMPLEMENT_DYNCREATE(CHW31View, CView)

BEGIN_MESSAGE_MAP(CHW31View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_32771, &CHW31View::OnDrawLine)
	ON_COMMAND(ID_32772, &CHW31View::OnDrawRect)
	ON_COMMAND(ID_32773, &CHW31View::OnPolygun)
	ON_WM_CHAR()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CHW31View 构造/析构

CHW31View::CHW31View() noexcept
{
	// TODO: 在此处添加构造代码

	type = 0;
}

CHW31View::~CHW31View()
{
}

BOOL CHW31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHW31View 绘图

void CHW31View::OnDraw(CDC* /*pDC*/)
{
	CHW31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CHW31View 打印

BOOL CHW31View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHW31View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHW31View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CHW31View 诊断

#ifdef _DEBUG
void CHW31View::AssertValid() const
{
	CView::AssertValid();
}

void CHW31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHW31Doc* CHW31View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHW31Doc)));
	return (CHW31Doc*)m_pDocument;
}
#endif //_DEBUG


// CHW31View 消息处理程序


void CHW31View::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: 在此处添加消息处理程序代码
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	CMenu* pMenu = menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
}


void CHW31View::OnDrawLine()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
	UpdateWindow();
	CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	pDC->MoveTo(rect.right / 2 - 200, rect.bottom / 2 - 200);
	pDC->LineTo(rect.right / 2 + 200, rect.bottom / 2 + 200);
	ReleaseDC(pDC);

	bmp_pos.x = rect.right / 2 - 200;
	bmp_pos.y = rect.bottom / 2 - 200;
	bmp_rect.right = bmp_pos.x + 16;
	bmp_rect.left = bmp_pos.x - 16;
	bmp_rect.bottom = bmp_pos.y + 16;
	bmp_rect.top = bmp_pos.y + 16;

	type = 0;
	KillTimer(1);
}


void CHW31View::OnDrawRect()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
	UpdateWindow();
	CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);

	CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	pDC->SelectObject(pBrush);
	pDC->Rectangle(rect.right / 2 - 200, rect.bottom / 2 - 200, rect.right / 2 + 200, rect.bottom / 2 + 200);
	ReleaseDC(pDC);

	bmp_pos.x = rect.right / 2 - 200;
	bmp_pos.y = rect.bottom / 2 - 200;
	bmp_rect.right = bmp_pos.x + 16;
	bmp_rect.left = bmp_pos.x - 16;
	bmp_rect.bottom = bmp_pos.y + 16;
	bmp_rect.top = bmp_pos.y + 16;

	type = 1;
	KillTimer(1);
}


void CHW31View::OnPolygun()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
	UpdateWindow();
	CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	pDC->SelectObject(pBrush);
	CPoint pts[6];
	pts[0] = CPoint(rect.right / 2 - 100, rect.bottom / 2 - (int)sqrt(3) * 100);
	pts[1] = CPoint(rect.right / 2 - 200, rect.bottom / 2);
	pts[2] = CPoint(rect.right / 2 - 100, rect.bottom / 2 + (int)sqrt(3) * 100);
	pts[3] = CPoint(rect.right / 2 + 100, rect.bottom / 2 + (int)sqrt(3) * 100);
	pts[4] = CPoint(rect.right / 2 + 200, rect.bottom / 2);
	pts[5] = CPoint(rect.right / 2 + 100, rect.bottom / 2 - (int)sqrt(3) * 100);
	pDC->Polygon(pts, 6);
	ReleaseDC(pDC);

	bmp_pos.x = rect.right / 2 - 100;
	bmp_pos.y = rect.bottom / 2 - (int)sqrt(3) * 100;
	bmp_rect.right = bmp_pos.x + 16;
	bmp_rect.left = bmp_pos.x - 16;
	bmp_rect.bottom = bmp_pos.y + 16;
	bmp_rect.top = bmp_pos.y + 16;

	type = 2;
	KillTimer(1);
}


void CHW31View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetClientRect(&rect);
	if (nChar == 'V' || nChar == 'v') {
		move = 10;
		switch (type) {
			case 0:
				bmp_pos.x = rect.right / 2 - 200;
				bmp_pos.y = rect.bottom / 2 - 200;
				bmp_rect.right = bmp_pos.x + 16;
				bmp_rect.left = bmp_pos.x - 16;
				bmp_rect.bottom = bmp_pos.y + 16;
				bmp_rect.top = bmp_pos.y + 16;
				break;
			case 1:
				bmp_pos.x = rect.right / 2 - 200;
				bmp_pos.y = rect.bottom / 2 - 200;
				bmp_rect.right = bmp_pos.x + 16;
				bmp_rect.left = bmp_pos.x - 16;
				bmp_rect.bottom = bmp_pos.y + 16;
				bmp_rect.top = bmp_pos.y + 16;
				break;
			case 2:
				bmp_pos.x = rect.right / 2 - 100;
				bmp_pos.y = rect.bottom / 2 - (int)sqrt(3) * 100;
				bmp_rect.right = bmp_pos.x + 16;
				bmp_rect.left = bmp_pos.x - 16;
				bmp_rect.bottom = bmp_pos.y + 16;
				bmp_rect.top = bmp_pos.y + 16;
				break;
			default:break;
		}
		SetTimer(1, 80, NULL);
	}

		
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CHW31View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (type == 0){
		Invalidate();
		UpdateWindow();
		CDC* pDC = GetDC();
		CRect rect;
		GetClientRect(&rect);
		pDC->MoveTo(rect.right / 2 - 200, rect.bottom / 2 - 200);
		pDC->LineTo(rect.right / 2 + 200, rect.bottom / 2 + 200);
		HICON bmp;
		bmp = AfxGetApp()->LoadIconW(IDR_MAINFRAME);
		pDC->DrawIcon(bmp_pos, bmp);
		CRect newRect;
		newRect = bmp_rect;
		newRect.right += move;
		newRect.left += move;
		newRect.bottom += move;
		newRect.top += move;

		if ((bmp_pos.x <= rect.right / 2 - 210) || (bmp_pos.y >= rect.bottom / 2 + 170))
			move = -move;
		bmp_rect = newRect;
		bmp_pos.x += move;
		bmp_pos.y += move;
	}
	if (type == 1) {
		Invalidate();
		UpdateWindow();
		CDC* pDC = GetDC();
		CRect rect;
		GetClientRect(&rect);
		CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		pDC->SelectObject(pBrush);
		pDC->Rectangle(rect.right / 2 - 200, rect.bottom / 2 - 200, rect.right / 2 + 200, rect.bottom / 2 + 200);
		HICON bmp;
		bmp = AfxGetApp()->LoadIconW(IDR_MAINFRAME);
		pDC->DrawIcon(bmp_pos, bmp);
		CRect newRect;
		newRect = bmp_rect;
		if (bmp_pos.x >= rect.right / 2 - 200 &&
			bmp_pos.x < rect.right / 2 + 200 &&
			bmp_pos.y == rect.bottom / 2 - 200) {
			newRect.right += move;
			newRect.left += move;
			bmp_pos.x += move;
			bmp_rect = newRect;
		}
		else if (bmp_pos.y >= rect.bottom / 2 - 200 &&
				 bmp_pos.y < rect.bottom / 2 + 200 &&
				 bmp_pos.x == rect.right / 2 + 200) {
			newRect.top += move;
			newRect.bottom += move;
			bmp_pos.y += move;
			bmp_rect = newRect;
		}
		else if (bmp_pos.x > rect.right / 2 - 200 &&
			bmp_pos.x <= rect.right / 2 + 200 &&
			bmp_pos.y == rect.bottom / 2 + 200) {
			newRect.right -= move;
			newRect.left += move;
			bmp_pos.x -= move;
			bmp_rect = newRect;
		}
		else if (bmp_pos.y > rect.bottom / 2 - 200 &&
			bmp_pos.y <= rect.bottom / 2 + 200 &&
			bmp_pos.x == rect.right / 2 - 200) {
			newRect.top -= move;
			newRect.bottom -= move;
			bmp_pos.y -= move;
			bmp_rect = newRect;
		}
	}
	if (type == 2) {
		Invalidate();
		UpdateWindow();
		CDC* pDC = GetDC();
		CRect rect;
		GetClientRect(&rect);
		CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		pDC->SelectObject(pBrush);
		CPoint pts[6];
		pts[0] = CPoint(rect.right / 2 - 100, rect.bottom / 2 - (int)sqrt(3) * 100);
		pts[1] = CPoint(rect.right / 2 - 200, rect.bottom / 2);
		pts[2] = CPoint(rect.right / 2 - 100, rect.bottom / 2 + (int)sqrt(3) * 100);
		pts[3] = CPoint(rect.right / 2 + 100, rect.bottom / 2 + (int)sqrt(3) * 100);
		pts[4] = CPoint(rect.right / 2 + 200, rect.bottom / 2);
		pts[5] = CPoint(rect.right / 2 + 100, rect.bottom / 2 - (int)sqrt(3) * 100);
		pDC->Polygon(pts, 6);
		HICON bmp;
		bmp = AfxGetApp()->LoadIconW(IDR_MAINFRAME);
		pDC->DrawIcon(bmp_pos, bmp);
		CRect newRect;
		newRect = bmp_rect;
		if (bmp_pos.x >= rect.right / 2 - 100&&
			bmp_pos.x < rect.right / 2 + 100&&
			bmp_pos.y == rect.bottom / 2 - (int)sqrt(3) * 100) {
			newRect.right += move;
			newRect.left += move;
			bmp_pos.x += move;
			bmp_rect = newRect;
		}
		else if (bmp_pos.x >= rect.right / 2 + 100 &&
			bmp_pos.x < rect.right / 2 + 200 &&
			bmp_pos.y >= rect.bottom / 2 - (int)sqrt(3) * 100&&
			bmp_pos.y < rect.bottom / 2) {
			newRect.right += move/2;
			newRect.left += move/2;
			newRect.bottom += (int)sqrt(3) * move / 2;
			newRect.top += (int)sqrt(3) * move / 2;
			bmp_pos.x += move/2;
			bmp_pos.y += (int)sqrt(3) * move / 2;
			bmp_rect = newRect;
		}
		else if (bmp_pos.x<= rect.right / 2 + 200&&
				 bmp_pos.x > rect.right / 2 + 100&&
				 bmp_pos.y >= rect.bottom / 2 &&
				 bmp_pos.y < rect.bottom / 2+ (int)sqrt(3) * 100) {
			newRect.right -= move / 2;
			newRect.left -= move / 2;
			newRect.bottom += (int)sqrt(3) * move / 2;
			newRect.top += (int)sqrt(3) * move / 2;
			bmp_pos.x -= move / 2;
			bmp_pos.y += (int)sqrt(3) * move / 2;
			bmp_rect = newRect;
		}
		else if (bmp_pos.x <= rect.right / 2 + 100 &&
			bmp_pos.x > rect.right / 2 - 100 &&
			bmp_pos.y == rect.bottom / 2 + (int)sqrt(3) * 100) {
			newRect.right -= move;
			newRect.left -= move;
			bmp_pos.x -= move;
			bmp_rect = newRect;
		}
		else if (bmp_pos.x <= rect.right / 2 - 100 &&
			bmp_pos.x > rect.right / 2 - 200 &&
			bmp_pos.y <= rect.bottom / 2 + (int)sqrt(3) * 100 &&
			bmp_pos.y > rect.bottom / 2) {
			newRect.right -= move / 2;
			newRect.left -= move / 2;
			newRect.bottom -= (int)sqrt(3) * move / 2;
			newRect.top -= (int)sqrt(3) * move / 2;
			bmp_pos.x -= move / 2;
			bmp_pos.y -= (int)sqrt(3) * move / 2;
			bmp_rect = newRect;
		}
		else if (bmp_pos.x >= rect.right / 2 - 200 &&
			bmp_pos.x < rect.right / 2 - 100 &&
			bmp_pos.y <= rect.bottom / 2 &&
			bmp_pos.y > rect.bottom / 2 - (int)sqrt(3) * 100) {
			newRect.right += move / 2;
			newRect.left += move / 2;
			newRect.bottom -= (int)sqrt(3) * move / 2;
			newRect.top -= (int)sqrt(3) * move / 2;
			bmp_pos.x += move / 2;
			bmp_pos.y -= (int)sqrt(3) * move / 2;
			bmp_rect = newRect;
		}
	}
	CView::OnTimer(nIDEvent);
}
