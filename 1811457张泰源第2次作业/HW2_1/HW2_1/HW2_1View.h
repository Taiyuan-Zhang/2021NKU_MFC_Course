
// HW2_1View.h: CHW21View 类的接口
//

#pragma once


class CHW21View : public CView
{
protected: // 仅从序列化创建
	CHW21View() noexcept;
	DECLARE_DYNCREATE(CHW21View)

// 特性
public:
	CHW21Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CHW21View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnDrawline();
	afx_msg void OnDrawellipse();
	CPoint mousePoint;
	afx_msg void OnDrawrectangle();
};

#ifndef _DEBUG  // HW2_1View.cpp 中的调试版本
inline CHW21Doc* CHW21View::GetDocument() const
   { return reinterpret_cast<CHW21Doc*>(m_pDocument); }
#endif

