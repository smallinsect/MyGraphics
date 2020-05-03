
// 基础图形.h: 基础图形 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// C基础图形App:
// 有关此类的实现，请参阅 基础图形.cpp
//

class C基础图形App : public CWinApp
{
public:
	C基础图形App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C基础图形App theApp;
