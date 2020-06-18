
// Game3DMathView.h: CGame3DMathView 类的接口
//

#pragma once


class CGame3DMathView : public CView
{
protected: // 仅从序列化创建
	CGame3DMathView() noexcept;
	DECLARE_DYNCREATE(CGame3DMathView)

// 特性
public:
	CGame3DMathDoc* GetDocument() const;

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
	virtual ~CGame3DMathView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Game3DMathView.cpp 中的调试版本
inline CGame3DMathDoc* CGame3DMathView::GetDocument() const
   { return reinterpret_cast<CGame3DMathDoc*>(m_pDocument); }
#endif

