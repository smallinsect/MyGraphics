#include "pch.h"
#include "CSphere.h"

CSphere::CSphere() {
}

CSphere::~CSphere() {
}

void CSphere::SetParameter(int R, CPoint CenterPoint) {//设置半径、球心
	this->R = R;
	this->CenterPoint = CenterPoint;
}

void CSphere::Draw(CDC* pDC) {//绘制球体
	CPoint TopLet(CenterPoint.x - R, CenterPoint.y - R);
	CPoint BottomRight(CenterPoint.x + R, CenterPoint.y + R);
	CRect Square(TopLet, BottomRight);
	pDC->Ellipse(Square);
}