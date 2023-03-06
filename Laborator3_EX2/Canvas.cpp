#include "Canvas.h"
#include <iostream>
#include <math.h>


Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	for (int i = 1; i <= width; i++)
		for (int j = 1; j <= height; j++)
			this->canvasMatrix[i][j] = 32;
}

void Canvas::Clear()
{
	for (int i = 1; i <= width; i++)
		for (int j = 1; j <= height; j++)
			this->canvasMatrix[i][j] = 32;
}

void Canvas::Print()
{
	for (int i = 1; i <= width; i++)
	{
		for (int j = 1; j <= height; j++)
			std::cout << this->canvasMatrix[i][j];

		std::cout << '\n';
	}
}



void Canvas::SetPoint(int x, int y, char ch)
{
	this->canvasMatrix[x][y] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{

	for (int i = left; i <= right; i++)
		this->canvasMatrix[i][bottom] = ch;

	for (int i = left; i <= right; i++)
		this->canvasMatrix[i][top] = ch;

	for (int i = bottom; i <= top; i++)
		this->canvasMatrix[left][i] = ch;

	for (int i = bottom; i <= top; i++)
		this->canvasMatrix[right][i] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
		for (int j = bottom; j <= top; j++)
			this->canvasMatrix[i][j] = ch;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 1; i <= this->height; i++)
		for (int j = 1; j <= this->width; j++)
		{
			int newX = x - i;
			int newY = y - j;
			if (newX * newX + newY * newY <= ray * (ray + 1) && newX * newX + newY * newY >= ray * (ray - 1))
				this->canvasMatrix[i][j] = ch;
		}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 1; i <= this->height; i++)
		for (int j = 1; j <= this->width; j++)
		{
			int newX = x - i;
			int newY = y - j;
			if (newX * newX + newY * newY <= ray * ray)
				this->canvasMatrix[i][j] = ch;
		}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	/*
	int dx = abs(x2 - x1);
	int normal_x = x1 < x2 ? 1 : -1;

	int dy = -abs(y2 - y1);
	int normal_y = y1 < y2 ? 1 : -1;

	int margin = dx + dy;
	while (true) {
		if (x1 == x2 && y1 == y2)
			break;

		if (2 * margin >= dy)
			margin += dy, x1 += normal_x;

		if (2 * margin <= dx)
			margin += dx, y1 += normal_y;
	}
	*/
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	if (dx > dy)
	{
		int pk = 2 * dy - dx;
		for (int i = 0; i <= dx; i++) {
			x1 < x2 ? x1++ : x1--;
			if (pk < 0) {
				this->canvasMatrix[x1][y1] = ch;
				pk = pk + 2 * dy;
			}
			else {
				y1 < y2 ? y1++ : y1--;
				this->canvasMatrix[x1][y1] = ch;
				pk = pk + 2 * dy - 2 * dx;
			}
		}
	}
	else {
		int auxiliary = -1;
		auxiliary = dx;
		dx = dy;
		dy = auxiliary;
		auxiliary = x1;
		x1 = y1;
		y1 = auxiliary;
		auxiliary = x2;
		x2 = y2;
		y2 = auxiliary;

		int pk = 2 * dy - dx;
		for (int i = 0; i <= dx; i++) {
			x1 < x2 ? x1++ : x1--;
			if (pk < 0) {
				this->canvasMatrix[y1][x1] = ch;
				pk = pk + 2 * dy;
			}
			else {
				y1 < y2 ? y1++ : y1--;
				this->canvasMatrix[y1][x1] = ch;
				pk = pk + 2 * dy - 2 * dx;
			}
		}
	}
	
	/*
	
		int dx, dy, p, x, y;
		dx = x2 - x1;
		dy = y2 - y1;
		x = x1;
		y = y1;
		p = 2 * dy - dx;
		while (x < x1)
		{
			if (p >= 0)
			{
				this->SetPoint(x, y, 'x');
				y = y + 1;
				p = p + 2 * dy - 2 * dx;
			}
			else
			{
				this->SetPoint(x, y, 'y');
				p = p + 2 * dy;
			}
			x = x + 1;
		}
	*/
	
}