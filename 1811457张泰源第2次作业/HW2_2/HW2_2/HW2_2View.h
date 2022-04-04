
// HW2_2View.h: CHW22View 类的接口
//

#pragma once


class CHW22View : public CView
{
protected: // 仅从序列化创建
	CHW22View() noexcept;
	DECLARE_DYNCREATE(CHW22View)

// 特性
public:
	CHW22Doc* GetDocument() const;

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
	virtual ~CHW22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void OnFileSave();
	CString saveStr;
};

#ifndef _DEBUG  // HW2_2View.cpp 中的调试版本
inline CHW22Doc* CHW22View::GetDocument() const
   { return reinterpret_cast<CHW22Doc*>(m_pDocument); }
#endif

