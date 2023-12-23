#pragma once

#include <gdiplus.h>
// MyDrawer

class MyDrawer : public CStatic
{
	DECLARE_DYNAMIC(MyDrawer)

public:
	MyDrawer();
	virtual ~MyDrawer();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	ULONG_PTR token;
	int ugol_povorota;
	Gdiplus::PointF my_point;
};


