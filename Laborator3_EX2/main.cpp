#include <iostream>
#include "Canvas.h"
#include <stdio.h>
#include <time.h>
#include <dos.h>
#include <stdlib.h>
#include <windows.h> 
using namespace std;

int main()
{
	Canvas canvas(64, 64);
	canvas.DrawRect(2, 5, 5, 2, '1');
	canvas.FillRect(8, 5, 10, 2, '1');
	canvas.DrawCircle(21, 21, 4, '1');
	canvas.FillCircle(11, 11, 2, '1');
	canvas.Print();
	Sleep(3000);
	system("CLS");
	canvas.Clear();
	//canvas.DrawLine(1, 1, 32, 32, '*');
	//canvas.DrawLine(0, 14, 23, 25, '*');
	//canvas.DrawLine(32, 1, 3, 25, '*');

	canvas.DrawLine(5, 25, 25, 25, '*');
	canvas.DrawLine(25, 25, 15, 5, '*');
	canvas.DrawLine(15, 5, 5, 25, '*');
	///canvas.DrawLine(-3, 3, 3, 3, '*');
	//canvas.DrawLine(-3, 3, 3, 3, '*');

	
	canvas.Print();
}