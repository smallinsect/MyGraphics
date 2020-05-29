
// 直线算法View.cpp: C直线算法View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "直线算法.h"
#endif

#include "直线算法Doc.h"
#include "直线算法View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C直线算法View

IMPLEMENT_DYNCREATE(C直线算法View, CView)

BEGIN_MESSAGE_MAP(C直线算法View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C直线算法View 构造/析构

C直线算法View::C直线算法View() noexcept
{
	// TODO: 在此处添加构造代码

}

C直线算法View::~C直线算法View()
{
}

BOOL C直线算法View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C直线算法View 绘图

void C直线算法View::OnDraw(CDC* /*pDC*/)
{
	C直线算法Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C直线算法View 打印

BOOL C直线算法View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C直线算法View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C直线算法View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C直线算法View 诊断

#ifdef _DEBUG
void C直线算法View::AssertValid() const
{
	CView::AssertValid();
}

void C直线算法View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C直线算法Doc* C直线算法View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C直线算法Doc)));
	return (C直线算法Doc*)m_pDocument;
}
#endif //_DEBUG


// C直线算法View 消息处理程序


void C直线算法View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnTimer(nIDEvent);
}
