
// HW1_2View.cpp: CHW12View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HW1_2.h"
#endif

#include "HW1_2Doc.h"
#include "HW1_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHW12View

IMPLEMENT_DYNCREATE(CHW12View, CView)

BEGIN_MESSAGE_MAP(CHW12View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_COMMAND(ID_SpeedUp, &CHW12View::OnSpeedUp)
	ON_COMMAND(ID_SpeedDown, &CHW12View::OnSpeedDown)
	ON_COMMAND(ID_BUTTON32788, &CHW12View::OnButtonRestart)
	ON_COMMAND(ID_BUTTON32789, &CHW12View::OnButtonStop)
END_MESSAGE_MAP()

// CHW12View 构造/析构

CHW12View::CHW12View() noexcept
	: x(0)
	, y(0)
	, movex(0)
	, movey(0)
{
	// TODO: 在此处添加构造代码

	movex = movey = 15;
}

CHW12View::~CHW12View()
{
}

BOOL CHW12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHW12View 绘图

void CHW12View::OnDraw(CDC* pDC)
{
	CHW12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x, y, x + 15, y + 15);
	// TODO: 在此处为本机数据添加绘制代码
}


// CHW12View 打印

BOOL CHW12View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHW12View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHW12View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CHW12View 诊断

#ifdef _DEBUG
void CHW12View::AssertValid() const
{
	CView::AssertValid();
}

void CHW12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHW12Doc* CHW12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHW12Doc)));
	return (CHW12Doc*)m_pDocument;
}
#endif //_DEBUG


// CHW12View 消息处理程序


int CHW12View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(1, 100, NULL);
	return 0;
}


void CHW12View::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(1);
	// TODO: 在此处添加消息处理程序代码
}


void CHW12View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1) {
		CRect rect;
		GetClientRect(&rect);
		CDC* pDC = GetDC();
		pDC->SetROP2(R2_XORPEN);
		pDC->Ellipse(x, y, x + 15, y + 15);
		x += movex;
		y += movey;
		if (x<0 || x>rect.right - 15)
			movex = 0 - movex;
		if (y<0 || y>rect.bottom - 15)
			movey = 0 - movey;
		pDC->Ellipse(x, y, x + 15, y + 15);
	}
	CView::OnTimer(nIDEvent);
}




void CHW12View::OnSpeedUp()
{
	// TODO: 在此添加命令处理程序代码
	movex += 15;
	movey += 15;
}


void CHW12View::OnSpeedDown()
{
	// TODO: 在此添加命令处理程序代码
	if ((movex >= 15) && (movey >= 15))
	{
		movex -= 15;
		movey -= 15;
	}
}


void CHW12View::OnButtonRestart()
{
	// TODO: 在此添加命令处理程序代码
	SetTimer(1, 100, NULL);
}


void CHW12View::OnButtonStop()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
}
