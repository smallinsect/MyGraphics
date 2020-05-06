#pragma once
class CSphere
{
public:
	CSphere();
	virtual ~CSphere();
	void SetParameter(int R, CPoint CenterPoint);//设置半径、球心
	void Draw(CDC* pDC);//绘制球体

public:
	int R;//球的半径
	CPoint CenterPoint;//中心点
};

