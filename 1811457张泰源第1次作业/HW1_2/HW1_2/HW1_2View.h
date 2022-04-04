
// HW1_2View.h: CHW12View 类的接口
//

#pragma once


class CHW12View : public CView
{
protected: // 仅从序列化创建
	CHW12View() noexcept;
	DECLARE_DYNCREATE(CHW12View)

// 特性
public:
	CHW12Doc* GetDocument() const;

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
	virtual ~CHW12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	int X;
	int x;
	int y;
	int movex;
	int movey;
	afx_msg void OnSpeedUp();
	afx_msg void OnSpeedDown();
	afx_msg void OnButtonRestart();
	afx_msg void OnButtonStop();
};

#ifndef _DEBUG  // HW1_2View.cpp 中的调试版本
inline CHW12Doc* CHW12View::GetDocument() const
   { return reinterpret_cast<CHW12Doc*>(m_pDocument); }
#endif

