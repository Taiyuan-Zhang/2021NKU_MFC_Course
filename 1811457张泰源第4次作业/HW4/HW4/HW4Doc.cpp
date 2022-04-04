
// HW4Doc.cpp: CHW4Doc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HW4.h"
#endif

#include "HW4Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHW4Doc

IMPLEMENT_DYNCREATE(CHW4Doc, CDocument)

BEGIN_MESSAGE_MAP(CHW4Doc, CDocument)
END_MESSAGE_MAP()


// CHW4Doc 构造/析构

CHW4Doc::CHW4Doc() noexcept
{
	// TODO: 在此添加一次性构造代码

	Name = _T("");
	Id = _T("");
	//  home = _T("");
	Home = _T("");
	Party = _T("");
	Gender = _T("");
	Age = _T("");
	Birthday = _T("");
	Nation = _T("");
	Save = false;
}

CHW4Doc::~CHW4Doc()
{
}

BOOL CHW4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CHW4Doc 序列化

void CHW4Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		Save = true;
		ar << Name << Id << Gender << Age << Nation << Party << Birthday << Home;
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
		Save = true;
		ar >> Name >> Id >> Gender >> Age >> Nation >> Party >> Birthday >> Home;

	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CHW4Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CHW4Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CHW4Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CHW4Doc 诊断

#ifdef _DEBUG
void CHW4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHW4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHW4Doc 命令


void CHW4Doc::Set(CString name, CString id, CString gender, CString home, CString nation, CString party, CString birthday, CString age)
{
	// TODO: 在此处添加实现代码.
	Name = name; Id = id; Gender = gender; Home = home; Nation = nation; Party = party; Birthday = birthday; Age = age;
}


void CHW4Doc::Get(CString name, CString id, CString age, CString gender, CString party, CString nation, CString birthday, CString home)
{
	// TODO: 在此处添加实现代码.
	name = Name; id = Id; age = Age; gender = Gender; party = Party; nation = Nation; birthday = Birthday; home = Home;
}
