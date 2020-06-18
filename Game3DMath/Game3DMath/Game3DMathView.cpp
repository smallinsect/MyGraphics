
// Game3DMathView.cpp: CGame3DMathView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Game3DMath.h"
#endif

#include "Game3DMathDoc.h"
#include "Game3DMathView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGame3DMathView

IMPLEMENT_DYNCREATE(CGame3DMathView, CView)

BEGIN_MESSAGE_MAP(CGame3DMathView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CGame3DMathView 构造/析构

CGame3DMathView::CGame3DMathView() noexcept
{
	// TODO: 在此处添加构造代码

}

CGame3DMathView::~CGame3DMathView()
{
}

BOOL CGame3DMathView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGame3DMathView 绘图

void CGame3DMathView::OnDraw(CDC* /*pDC*/)
{
	CGame3DMathDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CGame3DMathView 打印

BOOL CGame3DMathView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGame3DMathView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CGame3DMathView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CGame3DMathView 诊断

#ifdef _DEBUG
void CGame3DMathView::AssertValid() const
{
	CView::AssertValid();
}

void CGame3DMathView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGame3DMathDoc* CGame3DMathView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGame3DMathDoc)));
	return (CGame3DMathDoc*)m_pDocument;
}
#endif //_DEBUG


// CGame3DMathView 消息处理程序
