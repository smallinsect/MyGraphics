
// 缓冲区View.h: C缓冲区View 类的接口
//

#pragma once


class C缓冲区View : public CView
{
protected: // 仅从序列化创建
	C缓冲区View() noexcept;
	DECLARE_DYNCREATE(C缓冲区View)

// 特性
public:
	C缓冲区Doc* GetDocument() const;

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
	virtual ~C缓冲区View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 缓冲区View.cpp 中的调试版本
inline C缓冲区Doc* C缓冲区View::GetDocument() const
   { return reinterpret_cast<C缓冲区Doc*>(m_pDocument); }
#endif

