#pragma once
#include <vector>
#include <iostream>

using namespace std;

struct Segment
{
	int x, y;
	int value;
};

class Snake
{
public:
	int num_seg;
	vector<Segment> seg;
	Snake();
	void Moving(int dir, int(&mappull)[20][20]);
	void Grow(int direct);
	int PixelType(int(&mappull)[20][20], int i, int j);
};

