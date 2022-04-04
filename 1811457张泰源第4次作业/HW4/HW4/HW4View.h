
// HW4View.h: CHW4View 类的接口
//

#pragma once


class CHW4View : public CView
{
protected: // 仅从序列化创建
	CHW4View() noexcept;
	DECLARE_DYNCREATE(CHW4View)

// 特性
public:
	CHW4Doc* GetDocument() const;

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
	virtual ~CHW4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnButton32774();
	CHW4Doc* pMDoc;
	CString my_name;
	CString my_id;
	CString my_age;
	CString my_gender;
	CString my_nation;
	CString home;
	CString my_party;
	CString my_birthday;
	bool ok;
};

#ifndef _DEBUG  // HW4View.cpp 中的调试版本
inline CHW4Doc* CHW4View::GetDocument() const
   { return reinterpret_cast<CHW4Doc*>(m_pDocument); }
#endif

