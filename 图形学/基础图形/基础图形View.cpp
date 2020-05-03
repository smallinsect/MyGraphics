﻿
// 基础图形View.cpp: C基础图形View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "基础图形.h"
#endif

#include "基础图形Doc.h"
#include "基础图形View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C基础图形View

IMPLEMENT_DYNCREATE(C基础图形View, CView)

BEGIN_MESSAGE_MAP(C基础图形View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C基础图形View 构造/析构

C基础图形View::C基础图形View() noexcept
{
	// TODO: 在此处添加构造代码

}

C基础图形View::~C基础图形View()
{
}

BOOL C基础图形View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C基础图形View 绘图

void C基础图形View::OnDraw(CDC* /*pDC*/)
{
	C基础图形Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C基础图形View 打印

BOOL C基础图形View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C基础图形View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C基础图形View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C基础图形View 诊断

#ifdef _DEBUG
void C基础图形View::AssertValid() const
{
	CView::AssertValid();
}

void C基础图形View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C基础图形Doc* C基础图形View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C基础图形Doc)));
	return (C基础图形Doc*)m_pDocument;
}
#endif //_DEBUG


// C基础图形View 消息处理程序


void C基础图形View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	p0 = point;

	CView::OnLButtonDown(nFlags, point);
}


void C基础图形View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	p1 = point;
	CDC* pDC = GetDC();
	pDC->MoveTo(p0);
	pDC->LineTo(p1);

	ReleaseDC(pDC);
	CView::OnLButtonUp(nFlags, point);
}
