#pragma once
class CSphere
{
public:
	CSphere();
	virtual ~CSphere();
	void SetParameter(int R, CPoint CenterPoint);//���ð뾶������
	void Draw(CDC* pDC);//��������

public:
	int R;//��İ뾶
	CPoint CenterPoint;//���ĵ�
};

