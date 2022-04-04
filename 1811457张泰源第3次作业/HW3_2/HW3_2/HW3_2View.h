
// HW3_2View.h: CHW32View 类的接口
//

#pragma once


class CHW32View : public CScrollView
{
protected: // 仅从序列化创建
	CHW32View() noexcept;
	DECLARE_DYNCREATE(CHW32View)

// 特性
public:
	CHW32Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CHW32View();
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
	afx_msg void On32772();
	afx_msg void On32773();
	CImage image;
	float scale;
};

#ifndef _DEBUG  // HW3_2View.cpp 中的调试版本
inline CHW32Doc* CHW32View::GetDocument() const
   { return reinterpret_cast<CHW32Doc*>(m_pDocument); }
#endif

