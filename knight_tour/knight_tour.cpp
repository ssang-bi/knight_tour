#include <iostream>
#include <cstring>
#define TRACE 1
#define KNIGHT 2
#define WIDTH 8
#define HEIGHT 8
using namespace std;

int board[WIDTH][HEIGHT];
int width_move[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int height_move[8] = {2, 1, -1, -2, -2, -1, 1, 2};


void print(int x, int y);
void move_knight(int count, int x, int y);
int move_case(int x, int y);

int main(void){
	int x, y, run = 1;

	cout << "Start the \"Knight's Tour\" Simulator\n"
		 << " The size of the chessboard is 8x8  \n"
		 << "   0 <= x <= 7       0 <= y <= 7   \n";
	while (run == 1) {
		for (int i = 0; i < WIDTH; i++) memset(board[i], 0, sizeof(board[i]));
		cout << "\nEnter the knight's location(example -> x y) : ";
		cin >> x >> y;
		if (x < 0 || x > 7 || y < 0 || y > 7) {
			cout << "\nerror: insert wrong location\n"
				 << "  0 <= x <= 7, 0 <= y <= 7 \n";
			continue;
		}
		board[x][y] = KNIGHT;
		cout << "----- Start Simulation -----\n";
		print(x, y);
		move_knight(1, x, y);
		cout << "-----  End Simulation  -----\n";

		cout << "\nDo you want to check other cases?\n" << "1 : yes        2 : no\n";
		cin >> run;
	}
	cout << "\nShut down the \"Knight's Tour\" Simulator\n";
	return 0;
}

void print(int x, int y) {
	cout << "------------- (" << x << ", " << y << ")\n";
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) cout << board[y][x] << " ";  // 
		cout << endl;
	}
}

void move_knight(int count, int x, int y) {
	if (count == WIDTH * HEIGHT) return;
	int tmp_x = x + width_move[move_case(x, y)], tmp_y = y + height_move[move_case(x, y)];
	board[x][y] = TRACE;
	board[tmp_x][tmp_y] = KNIGHT;
	print(tmp_x, tmp_y);
	move_knight(count + 1, tmp_x, tmp_y);
}

int move_case(int x, int y) {
	int min = 8, count, way;
	for (int i = 0; i < 8; i++) {
		count = 0;
		int tmp_x = x + width_move[i], tmp_y = y + height_move[i];

		if (tmp_x < 0 || tmp_x > 7 || tmp_y < 0 || tmp_y > 7 || board[tmp_x][tmp_y] != 0) continue;

		for (int i = 0; i < 8; i++) {
			int ntmp_x = tmp_x + width_move[i], ntmp_y = tmp_y + height_move[i];
			if (ntmp_x < 0 || ntmp_x > 7 || ntmp_y < 0 || ntmp_y > 7 || board[ntmp_x][ntmp_y] != 0) continue;
			else count++;
		}
		if (count < min) {
			min = count;
			way = i;
		}
	}
	return way;
}