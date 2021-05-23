/*
#include< iostream>
#include< array>
#include< algorithm>
using namespace	std	;

#define PRINT_HEADER(msg) cout << "--> " << msg << " <--\n"

bool divBy3(	const	int	& val) {
	return		val %		3		==		0		;
}

bool divBy2(	const	int	& val) {
	return		val %		2		==		0		;
}

int main()

{
	PRINT_HEADER("Start Program");

	bool		(*select)(const			double&) = nullptr;

	PRINT_HEADER("Create multidimensional array");

	int** pRagged = new		int* [3];

	for (auto row = 0; row < 3; ++row) {

		pRagged[row] = new				int[row + 10];

		for (auto col = 0; col < row + 10; ++col)

			pRagged[col][row] = row + col;

	}

	std::array <double, 10> arr{};

	select = (double)divBy2; 

	copy_if(pRagged[2], pRagged[2] + 10, arr.begin(), select);

	PRINT_HEADER("Cleanup");

	for (auto i = 2; i >= 0; --i) delete pRagged[i];

	delete[] pRagged;

	return 0;
}
*/

// main.cpp
2.
#
include
< iostream>
3.
#
include
< string>
4.
#
include
< string_view>
5.
#
include
< thread>
6.
#
include
< future>
7.
#
include
< numeric>
8.
#
include
< memory>
9.
#
include
"assign.h"
10.
using
namespace
	std
	;
11.
12.
thread_local
int
step =
0
;
13.
14.
void
task(promise<
	double
>&p)
15.
{
	16.
		vector
		VE;
	17.
		VE.push_back({
		"AAAAAAAA"
		,
		1.2
			});
	18.
		VE.push_back({
		"BBBBBBBB"
		,
		2.3
			});
	19.
		VE.push_back({
		"CCCCCCCC"
		,
		3.4
			});
	20.
		VE.push_back({
		"DDDDDDDD"
		,
		4.5
			});
	21.
		double
		s = accumulate(VE.begin(), VE.end(),
			0.0
			,
			22.
			[](
				const
				double
				& x,
				const
				Assign& e)
			23.
	{
		24.
			step = (step +
				1
				) %
			5
			;
		25.
			return
			x + e.getData(step);
		26.
	});
	27.
		p.set_value(s);
	28.
}
29.
30.
int
main()