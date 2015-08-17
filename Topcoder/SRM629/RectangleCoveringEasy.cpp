#include <string>
#include <vector>
#include <iostream>
using namespace std;
class RectangleCoveringEasy {
	public:
	int solve(int holeH, int holeW, int boardH, int boardW) {
		if (holeH < holeW)
			swap(holeH, holeW);
		if (boardH < boardW)
			swap(boardH, boardW);
		
		if (boardH < holeH || boardW < holeW || (boardH == holeH && boardW == holeW))
			return -1;
		return 1;
	}
};
