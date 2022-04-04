
// HW3_2View.cpp: CHW32View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HW3_2.h"
#endif

#include "HW3_2Doc.h"
#include "HW3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHW32View

IMPLEMENT_DYNCREATE(CHW32View, CScrollView)

BEGIN_MESSAGE_MAP(CHW32View, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CHW32View::On32771)
	ON_COMMAND(ID_32772, &CHW32View::On32772)
	ON_COMMAND(ID_32773, &CHW32View::On32773)
END_MESSAGE_MAP()

// CHW32View 构造/析构

CHW32View::CHW32View() noexcept
{
	// TODO: 在此处添加构造代码

}

CHW32View::~CHW32View()
{
}

BOOL CHW32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CHW32View 绘图

void CHW32View::OnDraw(CDC* pDC)
{
	CHW32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (!image.IsNull())
	{
		CRect rectClient;
		GetClientRect(rectClient);

		//获取图片的宽、高
		int nWidthOrigin = image.GetWidth();
		int nHeightOrigin = image.GetHeight();
		//定义拉伸后图片的宽、高
		int nWidthStrectch = nWidthOrigin * scale;
		int nHeightStrectch = nHeightOrigin * scale;
		image.StretchBlt(pDC->m_hDC, 0, 0, nWidthStrectch, nHeightStrectch, 0, 0, nWidthOrigin, nHeightOrigin, SRCCOPY);
	}
	// TODO: 在此处为本机数据添加绘制代码
}

void CHW32View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	image.Load(_T("res/bitmap1.bmp"));
	sizeTotal.cx = 1600;
	sizeTotal.cy = 1200;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CHW32View 打印

BOOL CHW32View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHW32View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHW32View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CHW32View 诊断

#ifdef _DEBUG
void CHW32View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CHW32View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CHW32Doc* CHW32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHW32Doc)));
	return (CHW32Doc*)m_pDocument;
}
#endif //_DEBUG


// CHW32View 消息处理程序


void CHW32View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	scale = 1.0;
	Invalidate();
}


void CHW32View::On32772()
{
	// TODO: 在此添加命令处理程序代码

	scale = 4.0;
	Invalidate();
}


void CHW32View::On32773()
{
	// TODO: 在此添加命令处理程序代码
	scale = 0.25;
	Invalidate();
}
