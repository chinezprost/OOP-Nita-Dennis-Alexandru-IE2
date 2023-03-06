#include <iostream>
#include "Math.h"
using namespace std;

Math math;

int main()
{
	cout << math.Add(1, 2) << " == 3" << '\n';
	cout << math.Add(1, 2, 3) << " == 6" << '\n';
	cout << math.Add(1.2, 2.2) << " == 3" << '\n';
	cout << math.Add(1.2, 2.2, 3.2) << " == 6" << "\n";
	cout << math.Mul(4, 3) << " == 12" << '\n';
	cout << math.Mul(2, 3, 4) << " == 24" << '\n';
	cout << math.Mul(2.5, 3.5) << " == 8" << '\n';
	cout << math.Mul(2.5, 3.5, 4.5) << " == 39" << '\n';
	cout << math.Add(5, 1, 2, 3, 4, 5) << " == 15" << '\n';
	cout << math.Add("1231231231231121223", "1212223") << " == 1231231231232333446" << '\n';
}