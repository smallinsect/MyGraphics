# 绘图工具与绘图函数

|                  |                                  |
| :--------------- | -------------------------------- |
| CreatePen        | 创建画笔，属性：线型、宽度、颜色 |
| CreateSolidBrush | 创建画刷，填充封闭图形           |
| SetPixel         | 绘制像素点，返回RGB值            |
| SetPixelV        | 绘制像素点，返回“0”或“非0”       |
| MoveTo           | 移动当前位置                     |
| LineTo           | 绘制直线段                       |
| Rectangle        | 绘制矩形                         |
| Ellipse          | 绘制椭圆                         |
| FillSolidRect    | 填充矩形颜色                     |



# 消息响应函数

```
WM_LBUTTONDOWN 鼠标按下左键时的消息
WM_LBUTTONUP   鼠标左键弹起时的消息
```

添加方法：在类向导中添加

画直线

```c++
p0 = point;

p1 = point;
CDC* pDC = GetDC();
pDC->MoveTo(p0);
pDC->LineTo(p1);

ReleaseDC(pDC);
```

创建新的画笔

```
p1 = point;
CDC* pDC = GetDC();
CPen NewPen, *pOldPen;
NewPen.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
pOldPen = pDC->SelectObject(&NewPen);

pDC->MoveTo(p0);
pDC->LineTo(p1);

pDC->SelectObject(pOldPen);
ReleaseDC(pDC);
NewPen.DeleteObject();
```

绘制矩形

```
pDC->Rectangle(CRect(p0, p1));
```

绘制椭圆

```
pDC->Ellipse(CRect(p0, p1));
```

创建画刷

```
CBrush NewBrush, * pOldBrush;
NewBrush.CreateSolidBrush(RGB(0,255,0));
pOldBrush = pDC->SelectObject(&NewBrush);

pDC->SelectObject(pOldBrush);
NewBrush.DeleteObject();
```

单刷冲，直接将图形绘制到界面。

双缓冲区，图形绘制到内存缓冲区，再将内存缓冲区复制到界面。

```
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
```



定时器

```

```







