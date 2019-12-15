#include "Snake.h"

Snake::Snake()
{
	num_seg = 4;
	for (int k=0;k< num_seg-1;k++)
	{
		Segment seg_s;
		seg_s.x = 0;
		seg_s.y = 0;
		seg_s.value = 1;

		seg.push_back(seg_s);
	}
	Segment seg_null;
	seg_null.x = 0;
	seg_null.y = 0;
	seg_null.value = 0;
	seg.push_back(seg_null);
}

int Snake::PixelType(int(&mappull)[20][20], int i, int j)
{
	return mappull[i][j];
}

void Snake::Grow(int direct)
{
	Segment seg_s;
	num_seg++;

	switch (direct)
	{
	case 0:
		seg_s.x = seg.back().x;
		seg_s.y = seg.back().y - 1;
		break;
	case 1:
		seg_s.x = seg.back().x;
		seg_s.y = seg.back().y + 1;
		break;
	case 2:
		seg_s.x = seg.back().x - 1;
		seg_s.y = seg.back().y;
		break;
	case 3:
		seg_s.x = seg.back().x + 1;
		seg_s.y = seg.back().y;
		break;
	}
	seg_s.value = 1;
	seg.push_back(seg_s);
}

void Snake::Moving(int dir, int(&mappull)[20][20])
{
	for (int i = num_seg - 1; i > 0; --i)
	{
		seg[i].x = seg[i - 1].x;
		seg[i].y = seg[i - 1].y;
		seg[i].value = seg[i - 1].value;
		if (i == num_seg - 1)
			seg[i].value = 0;
	}

	switch (dir)
	{
	case 0:
		seg[0].y--;
		if (PixelType(mappull, seg[0].x, seg[0].y) == 3)
		{
			Grow(dir);
		}
		seg[0].value = 1;
		break;
	case 1:
		seg[0].y++;
		if (PixelType(mappull, seg[0].x, seg[0].y) == 3)
		{
			Grow(dir);
		}
		seg[0].value = 1;
		break;
	case 2:
		seg[0].x--;
		if (PixelType(mappull, seg[0].x, seg[0].y) == 3)
		{
			Grow(dir);
		}
		seg[0].value = 1;
		break;
	case 3:
		seg[0].x++;
		if (PixelType(mappull, seg[0].x, seg[0].y) == 3)
		{
			Grow(dir);
		}
		seg[0].value = 1;
		break;
	}

	if (seg[0].x > 19) seg[0].x = 0;  if (seg[0].x < 0) seg[0].x = 19;
	if (seg[0].y > 19) seg[0].y = 0;  if (seg[0].y < 0) seg[0].y = 19;

	for (auto p = seg.begin(); p != seg.end(); p++)
	{
		mappull[p->x][p->y] = p->value;
	}
}