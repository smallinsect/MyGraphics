
// 直线算法View.h: C直线算法View 类的接口
//

#pragma once


class C直线算法View : public CView
{
protected: // 仅从序列化创建
	C直线算法View() noexcept;
	DECLARE_DYNCREATE(C直线算法View)

// 特性
public:
	C直线算法Doc* GetDocument() const;

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
	virtual ~C直线算法View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 直线算法View.cpp 中的调试版本
inline C直线算法Doc* C直线算法View::GetDocument() const
   { return reinterpret_cast<C直线算法Doc*>(m_pDocument); }
#endif

