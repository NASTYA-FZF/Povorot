// MyDrawer.cpp: файл реализации
//

#include "stdafx.h"
#include "Povorot.h"
#include "MyDrawer.h"
using namespace Gdiplus;

// MyDrawer

IMPLEMENT_DYNAMIC(MyDrawer, CStatic)

MyDrawer::MyDrawer()
{
	GdiplusStartupInput input;
	Status s;
	s = GdiplusStartup(&token, &input, NULL);
	if (s != Ok)
	{
		MessageBox(L"s != OK", L"Error", NULL);
	}
	ugol_povorota = 0;
	my_point = PointF(0., 0.);
}

MyDrawer::~MyDrawer()
{
	GdiplusShutdown(token);
}


BEGIN_MESSAGE_MAP(MyDrawer, CStatic)
END_MESSAGE_MAP()



// обработчики сообщений MyDrawer




void MyDrawer::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO:  Добавьте исходный код для отображения указанного элемента
	Graphics g(lpDrawItemStruct->hDC);
	Bitmap buffer(lpDrawItemStruct->rcItem.right, lpDrawItemStruct->rcItem.bottom, &g);
	Graphics gr(&buffer);
	gr.SetSmoothingMode(SmoothingModeAntiAlias);
	gr.Clear(Color(255, 175, 238, 238));

	Matrix matr;
	matr.RotateAt(ugol_povorota, my_point);
	gr.SetTransform(&matr);

	Pen my_pen(Color(255, 255, 192, 203));
	auto rect_picture = lpDrawItemStruct->rcItem;

	RectF rect_ellipse(
		(rect_picture.right - rect_picture.left) / 4,
		(rect_picture.bottom - rect_picture.top) / 4,
		(rect_picture.right - rect_picture.left) / 2,
		(rect_picture.bottom - rect_picture.top) / 2);

	RectF rect_rectangle(
		(rect_picture.right - rect_picture.left) / 8,
		(rect_picture.bottom - rect_picture.top) / 8,
		(rect_picture.right - rect_picture.left) / 6,
		(rect_picture.bottom - rect_picture.top) / 6);

	gr.DrawEllipse(&my_pen, rect_ellipse);

	// Create a path that consists of a single ellipse.
	GraphicsPath path;
	path.AddEllipse(rect_ellipse);

	// Use the path to construct a brush.
	PathGradientBrush pthGrBrush(&path);

	// Set the color at the center of the path to blue.
	pthGrBrush.SetCenterColor(Color(255, 255, 84, 184));

	// Set the color along the entire boundary of the path to aqua.
	Color colors[] = { Color(255, 255, 192, 203) };
	int count = 1;
	pthGrBrush.SetSurroundColors(colors, &count);

	gr.FillEllipse(&pthGrBrush, rect_ellipse);

	Pen my_pen_rectangle(Color(255, 30, 89, 69));

	gr.DrawRectangle(&my_pen_rectangle, rect_rectangle);

	// Create a path that consists of a single ellipse.
	GraphicsPath path_rectangle;
	path_rectangle.AddRectangle(rect_rectangle);

	// Use the path to construct a brush.
	PathGradientBrush pthGrBrush_rectangle(&path_rectangle);

	// Set the color at the center of the path to blue.
	pthGrBrush_rectangle.SetCenterColor(Color(255, 189, 236, 182));

	// Set the color along the entire boundary of the path to aqua.
	Color colors_rectanglr[] = { Color(255, 30, 89, 69) };
	pthGrBrush_rectangle.SetSurroundColors(colors_rectanglr, &count);

	gr.FillRectangle(&pthGrBrush_rectangle, rect_rectangle);

	float radius = 5.;
	RectF rect_point(
		my_point.X - radius,
		my_point.Y - radius,
		2 * radius,
		2 * radius);

	Pen pen_point(Color(255, 255, 0, 0));
	gr.DrawEllipse(&pen_point, rect_point);
	SolidBrush brush_point(Color(255, 255, 0, 0));
	gr.FillEllipse(&brush_point, rect_point);

	g.DrawImage(&buffer, 0, 0, 0, 0, lpDrawItemStruct->rcItem.right, lpDrawItemStruct->rcItem.bottom, UnitPixel);
}
