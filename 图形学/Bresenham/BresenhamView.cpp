
// BresenhamView.cpp: CBresenhamView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Bresenham.h"
#endif

#include "BresenhamDoc.h"
#include "BresenhamView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBresenhamView

IMPLEMENT_DYNCREATE(CBresenhamView, CView)

BEGIN_MESSAGE_MAP(CBresenhamView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CBresenhamView 构造/析构

CBresenhamView::CBresenhamView() noexcept
{
	// TODO: 在此处添加构造代码

}

CBresenhamView::~CBresenhamView()
{
}

BOOL CBresenhamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CBresenhamView 绘图

void CBresenhamView::OnDraw(CDC* /*pDC*/)
{
	CBresenhamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CBresenhamView 打印

BOOL CBresenhamView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CBresenhamView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CBresenhamView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CBresenhamView 诊断

#ifdef _DEBUG
void CBresenhamView::AssertValid() const
{
	CView::AssertValid();
}

void CBresenhamView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBresenhamDoc* CBresenhamView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBresenhamDoc)));
	return (CBresenhamDoc*)m_pDocument;
}
#endif //_DEBUG


// CBresenhamView 消息处理程序
