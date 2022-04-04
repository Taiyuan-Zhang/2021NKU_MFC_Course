
// HW1_1View.h: CHW11View 类的接口
//

#pragma once


class CHW11View : public CView
{
protected: // 仅从序列化创建
	CHW11View() noexcept;
	DECLARE_DYNCREATE(CHW11View)

// 特性
public:
	CHW11Doc* GetDocument() const;

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
	virtual ~CHW11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
protected:
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
private:
	CPoint my_pos;
	CString my_str;
};

#ifndef _DEBUG  // HW1_1View.cpp 中的调试版本
inline CHW11Doc* CHW11View::GetDocument() const
   { return reinterpret_cast<CHW11Doc*>(m_pDocument); }
#endif

