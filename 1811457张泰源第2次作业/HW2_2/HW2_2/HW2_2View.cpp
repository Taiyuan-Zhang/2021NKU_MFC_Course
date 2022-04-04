
// HW2_2View.cpp: CHW22View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HW2_2.h"
#endif

#include "HW2_2Doc.h"
#include "HW2_2View.h"
#include "MyDialog.h"
#include <locale.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHW22View

IMPLEMENT_DYNCREATE(CHW22View, CView)

BEGIN_MESSAGE_MAP(CHW22View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CHW22View::On32771)
	ON_COMMAND(ID_FILE_SAVE, &CHW22View::OnFileSave)
END_MESSAGE_MAP()

// CHW22View 构造/析构

CHW22View::CHW22View() noexcept
{
	// TODO: 在此处添加构造代码

	saveStr = _T("");
}

CHW22View::~CHW22View()
{
}

BOOL CHW22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHW22View 绘图

void CHW22View::OnDraw(CDC* /*pDC*/)
{
	CHW22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CHW22View 打印

BOOL CHW22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHW22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHW22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CHW22View 诊断

#ifdef _DEBUG
void CHW22View::AssertValid() const
{
	CView::AssertValid();
}

void CHW22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHW22Doc* CHW22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHW22Doc)));
	return (CHW22Doc*)m_pDocument;
}
#endif //_DEBUG


// CHW22View 消息处理程序


void CHW22View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	MyDialog dialog;
	dialog.DoModal();
	CRect rect;
	GetClientRect(rect);
	InvalidateRect(rect);
	UpdateWindow();
	CDC* pDC;
	pDC = GetDC();
	pDC->SetBkMode(OPAQUE);
	pDC->SetBkColor(RGB(255, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 255));
	pDC->SetTextAlign(TA_LEFT | TA_BOTTOM);
	pDC->SetTextCharacterExtra(5);
	saveStr = dialog.mystr;
	pDC->TextOut(10, 30, saveStr);

}


void CHW22View::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码
	setlocale(LC_CTYPE, "chs");
	CStdioFile file;
	file.Open(_T("save.txt"), CFile::modeCreate | CFile::modeWrite | CFile::typeText);
	file.WriteString(saveStr);
	file.Close();
}
