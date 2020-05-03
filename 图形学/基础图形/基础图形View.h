
// 基础图形View.h: C基础图形View 类的接口
//

#pragma once


class C基础图形View : public CView
{
protected: // 仅从序列化创建
	C基础图形View() noexcept;
	DECLARE_DYNCREATE(C基础图形View)

// 特性
public:
	C基础图形Doc* GetDocument() const;

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
	virtual ~C基础图形View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint p0, p1;

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 基础图形View.cpp 中的调试版本
inline C基础图形Doc* C基础图形View::GetDocument() const
   { return reinterpret_cast<C基础图形Doc*>(m_pDocument); }
#endif

