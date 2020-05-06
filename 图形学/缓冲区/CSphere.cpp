#include "pch.h"
#include "CSphere.h"

CSphere::CSphere() {
}

CSphere::~CSphere() {
}

void CSphere::SetParameter(int R, CPoint CenterPoint) {//���ð뾶������
	this->R = R;
	this->CenterPoint = CenterPoint;
}

void CSphere::Draw(CDC* pDC) {//��������
	CPoint TopLet(CenterPoint.x - R, CenterPoint.y - R);
	CPoint BottomRight(CenterPoint.x + R, CenterPoint.y + R);
	CRect Square(TopLet, BottomRight);
	pDC->Ellipse(Square);
}