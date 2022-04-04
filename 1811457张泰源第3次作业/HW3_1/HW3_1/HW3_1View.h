
// HW3_1View.h: CHW31View 类的接口
//

#pragma once


class CHW31View : public CView
{
protected: // 仅从序列化创建
	CHW31View() noexcept;
	DECLARE_DYNCREATE(CHW31View)

// 特性
public:
	CHW31Doc* GetDocument() const;

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
	virtual ~CHW31View();
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
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRect();
	afx_msg void OnPolygun();
	CPoint bmp_pos;
	CRect bmp_rect;
	int type;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	long move = 10;
};

#ifndef _DEBUG  // HW3_1View.cpp 中的调试版本
inline CHW31Doc* CHW31View::GetDocument() const
   { return reinterpret_cast<CHW31Doc*>(m_pDocument); }
#endif

