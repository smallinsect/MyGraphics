
// 缓冲区View.cpp: C缓冲区View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "缓冲区.h"
#endif

#include "缓冲区Doc.h"
#include "缓冲区View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C缓冲区View

IMPLEMENT_DYNCREATE(C缓冲区View, CView)

BEGIN_MESSAGE_MAP(C缓冲区View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &C缓冲区View::OnGraphAnimation)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C缓冲区View 构造/析构

C缓冲区View::C缓冲区View() noexcept
{
	// TODO: 在此处添加构造代码
	bPlay = FALSE;
	sphere.R = GetSystemMetrics(SM_CXFULLSCREEN) / 20;
	sphere.CenterPoint.x = 200;
	sphere.CenterPoint.y = 200;
	direction.x = 1;
	direction.y = 1;
}

C缓冲区View::~C缓冲区View()
{
}

BOOL C缓冲区View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C缓冲区View 绘图

void C缓冲区View::OnDraw(CDC* pDC)
{
	C缓冲区Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	DoubleBuffer(pDC);
}

void C缓冲区View::DoubleBuffer(CDC* pDC) {
	CRect rect;
	//获取当前窗口大小
	GetClientRect(&rect);
	nWidth = rect.Width();
	nHeight = rect.Height();

	//定义内存DC
	CDC memDC;
	//创建一个显示DC兼容的内存DC
	memDC.CreateCompatibleDC(pDC);

	CBitmap NewBitmap, *pOldBitmap;
	//创建兼容内存位图
	NewBitmap.CreateCompatibleBitmap(pDC, nWidth, nHeight);
	//兼容位图选入内存DC
	pOldBitmap = memDC.SelectObject(&NewBitmap);
	//在兼容DC上绘制小球
	DrawObject(&memDC);
	//碰撞检测
	CollisionDetection();
	//把内存DC上的位图显示到显示器上
	pDC->BitBlt(0, 0, nWidth, nHeight, &memDC, 0, 0, SRCCOPY);
	//选回旧的位图
	memDC.SelectObject(pOldBitmap);
	//删除新的位图
	NewBitmap.DeleteObject();
	//删除内存DC
	memDC.DeleteDC();
}

void C缓冲区View::DrawObject(CDC* pDC) {
	sphere.Draw(pDC);
}

void C缓冲区View::CollisionDetection() {
	if (sphere.CenterPoint.x - sphere.R < 0) {//左边界检测
		direction.x = 1;
	}
	if (sphere.CenterPoint.x + sphere.R > nWidth) {//右边界检测
		direction.x = -1;
	}
	if (sphere.CenterPoint.y - sphere.R < 0) {//上边界检测
		direction.y = 1;
	}
	if (sphere.CenterPoint.y + sphere.R > nHeight) {//下边界检测
		direction.y = -1;
	}
}


// C缓冲区View 打印

BOOL C缓冲区View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C缓冲区View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C缓冲区View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C缓冲区View 诊断

#ifdef _DEBUG
void C缓冲区View::AssertValid() const
{
	CView::AssertValid();
}

void C缓冲区View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C缓冲区Doc* C缓冲区View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C缓冲区Doc)));
	return (C缓冲区Doc*)m_pDocument;
}
#endif //_DEBUG


// C缓冲区View 消息处理程序


void C缓冲区View::OnGraphAnimation()
{
	// TODO: 在此添加命令处理程序代码
	bPlay = !bPlay;
	if (bPlay) {
		SetTimer( 1, 1, NULL);
	}
	else {
		KillTimer(1);
	}
}


void C缓冲区View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	sphere.CenterPoint += direction;
	Invalidate(FALSE);
	CView::OnTimer(nIDEvent);
}
