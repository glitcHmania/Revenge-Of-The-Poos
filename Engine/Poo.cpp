#include "Poo.h"

void Poo::Init(Vector2D& in_pos, Vector2D& in_vel)
{
	pos = in_pos;
	vel = in_vel;
	initialized = true;
}

void Poo::Draw(Graphics& gfx)
{
	int x_int = int(pos.x);
	int y_int = int(pos.y);
	gfx.PutPixel(14 + x_int, 0 + y_int, 138, 77, 0);
	gfx.PutPixel(7 + x_int, 1 + y_int, 138, 77, 0);
	gfx.PutPixel(13 + x_int, 1 + y_int, 138, 77, 0);
	gfx.PutPixel(20 + x_int, 1 + y_int, 138, 77, 0);
	gfx.PutPixel(6 + x_int, 2 + y_int, 138, 77, 0);
	gfx.PutPixel(13 + x_int, 2 + y_int, 138, 77, 0);
	gfx.PutPixel(20 + x_int, 2 + y_int, 138, 77, 0);
	gfx.PutPixel(6 + x_int, 3 + y_int, 138, 77, 0);
	gfx.PutPixel(6 + x_int, 4 + y_int, 138, 77, 0);
	gfx.PutPixel(14 + x_int, 4 + y_int, 138, 77, 0);
	gfx.PutPixel(21 + x_int, 4 + y_int, 138, 77, 0);
	gfx.PutPixel(7 + x_int, 5 + y_int, 138, 77, 0);
	gfx.PutPixel(13 + x_int, 5 + y_int, 138, 77, 0);
	gfx.PutPixel(21 + x_int, 5 + y_int, 138, 77, 0);
	gfx.PutPixel(7 + x_int, 6 + y_int, 138, 77, 0);
	gfx.PutPixel(20 + x_int, 6 + y_int, 138, 77, 0);
	gfx.PutPixel(6 + x_int, 7 + y_int, 138, 77, 0);
	gfx.PutPixel(14 + x_int, 7 + y_int, 51, 28, 0);
	gfx.PutPixel(15 + x_int, 7 + y_int, 51, 28, 0);
	gfx.PutPixel(20 + x_int, 7 + y_int, 138, 77, 0);
	gfx.PutPixel(12 + x_int, 8 + y_int, 51, 28, 0);
	gfx.PutPixel(13 + x_int, 8 + y_int, 51, 28, 0);
	gfx.PutPixel(14 + x_int, 8 + y_int, 51, 28, 0);
	gfx.PutPixel(7 + x_int, 9 + y_int, 138, 77, 0);
	gfx.PutPixel(11 + x_int, 9 + y_int, 51, 28, 0);
	gfx.PutPixel(12 + x_int, 9 + y_int, 102, 57, 0);
	gfx.PutPixel(13 + x_int, 9 + y_int, 138, 77, 0);
	gfx.PutPixel(14 + x_int, 9 + y_int, 138, 77, 0);
	gfx.PutPixel(15 + x_int, 9 + y_int, 51, 28, 0);
	gfx.PutPixel(21 + x_int, 9 + y_int, 138, 77, 0);
	gfx.PutPixel(10 + x_int, 10 + y_int, 51, 28, 0);
	gfx.PutPixel(11 + x_int, 10 + y_int, 51, 28, 0);
	gfx.PutPixel(12 + x_int, 10 + y_int, 102, 57, 0);
	gfx.PutPixel(13 + x_int, 10 + y_int, 138, 77, 0);
	gfx.PutPixel(14 + x_int, 10 + y_int, 138, 77, 0);
	gfx.PutPixel(15 + x_int, 10 + y_int, 51, 28, 0);
	gfx.PutPixel(20 + x_int, 10 + y_int, 138, 77, 0);
	gfx.PutPixel(9 + x_int, 11 + y_int, 51, 28, 0);
	gfx.PutPixel(10 + x_int, 11 + y_int, 138, 77, 0);
	gfx.PutPixel(11 + x_int, 11 + y_int, 138, 77, 0);
	gfx.PutPixel(12 + x_int, 11 + y_int, 51, 28, 0);
	gfx.PutPixel(13 + x_int, 11 + y_int, 51, 28, 0);
	gfx.PutPixel(14 + x_int, 11 + y_int, 51, 28, 0);
	gfx.PutPixel(15 + x_int, 11 + y_int, 51, 28, 0);
	gfx.PutPixel(16 + x_int, 11 + y_int, 51, 28, 0);
	gfx.PutPixel(9 + x_int, 12 + y_int, 51, 28, 0);
	gfx.PutPixel(10 + x_int, 12 + y_int, 138, 77, 0);
	gfx.PutPixel(11 + x_int, 12 + y_int, 138, 77, 0);
	gfx.PutPixel(12 + x_int, 12 + y_int, 111, 62, 0);
	gfx.PutPixel(13 + x_int, 12 + y_int, 102, 57, 0);
	gfx.PutPixel(14 + x_int, 12 + y_int, 102, 57, 0);
	gfx.PutPixel(15 + x_int, 12 + y_int, 102, 57, 0);
	gfx.PutPixel(16 + x_int, 12 + y_int, 51, 28, 0);
	gfx.PutPixel(9 + x_int, 13 + y_int, 51, 28, 0);
	gfx.PutPixel(10 + x_int, 13 + y_int, 109, 61, 0);
	gfx.PutPixel(11 + x_int, 13 + y_int, 138, 77, 0);
	gfx.PutPixel(12 + x_int, 13 + y_int, 138, 77, 0);
	gfx.PutPixel(13 + x_int, 13 + y_int, 138, 77, 0);
	gfx.PutPixel(14 + x_int, 13 + y_int, 138, 77, 0);
	gfx.PutPixel(15 + x_int, 13 + y_int, 138, 77, 0);
	gfx.PutPixel(16 + x_int, 13 + y_int, 51, 28, 0);
	gfx.PutPixel(5 + x_int, 14 + y_int, 51, 28, 0);
	gfx.PutPixel(7 + x_int, 14 + y_int, 51, 28, 0);
	gfx.PutPixel(8 + x_int, 14 + y_int, 51, 28, 0);
	gfx.PutPixel(9 + x_int, 14 + y_int, 51, 28, 0);
	gfx.PutPixel(10 + x_int, 14 + y_int, 51, 28, 0);
	gfx.PutPixel(11 + x_int, 14 + y_int, 138, 77, 0);
	gfx.PutPixel(12 + x_int, 14 + y_int, 138, 77, 0);
	gfx.PutPixel(13 + x_int, 14 + y_int, 138, 77, 0);
	gfx.PutPixel(14 + x_int, 14 + y_int, 138, 77, 0);
	gfx.PutPixel(15 + x_int, 14 + y_int, 138, 77, 0);
	gfx.PutPixel(16 + x_int, 14 + y_int, 51, 28, 0);
	gfx.PutPixel(4 + x_int, 15 + y_int, 51, 28, 0);
	gfx.PutPixel(5 + x_int, 15 + y_int, 138, 77, 0);
	gfx.PutPixel(6 + x_int, 15 + y_int, 51, 28, 0);
	gfx.PutPixel(7 + x_int, 15 + y_int, 116, 65, 0);
	gfx.PutPixel(8 + x_int, 15 + y_int, 138, 77, 0);
	gfx.PutPixel(9 + x_int, 15 + y_int, 138, 77, 0);
	gfx.PutPixel(10 + x_int, 15 + y_int, 138, 77, 0);
	gfx.PutPixel(11 + x_int, 15 + y_int, 51, 28, 0);
	gfx.PutPixel(12 + x_int, 15 + y_int, 51, 28, 0);
	gfx.PutPixel(13 + x_int, 15 + y_int, 51, 28, 0);
	gfx.PutPixel(14 + x_int, 15 + y_int, 51, 28, 0);
	gfx.PutPixel(15 + x_int, 15 + y_int, 51, 28, 0);
	gfx.PutPixel(16 + x_int, 15 + y_int, 51, 28, 0);
	gfx.PutPixel(17 + x_int, 15 + y_int, 51, 28, 0);
	gfx.PutPixel(18 + x_int, 15 + y_int, 51, 28, 0);
	gfx.PutPixel(1 + x_int, 16 + y_int, 51, 28, 0);
	gfx.PutPixel(2 + x_int, 16 + y_int, 51, 28, 0);
	gfx.PutPixel(3 + x_int, 16 + y_int, 51, 28, 0);
	gfx.PutPixel(4 + x_int, 16 + y_int, 51, 28, 0);
	gfx.PutPixel(5 + x_int, 16 + y_int, 138, 77, 0);
	gfx.PutPixel(6 + x_int, 16 + y_int, 51, 28, 0);
	gfx.PutPixel(7 + x_int, 16 + y_int, 116, 65, 0);
	gfx.PutPixel(8 + x_int, 16 + y_int, 138, 77, 0);
	gfx.PutPixel(9 + x_int, 16 + y_int, 138, 77, 0);
	gfx.PutPixel(10 + x_int, 16 + y_int, 138, 77, 0);
	gfx.PutPixel(11 + x_int, 16 + y_int, 138, 77, 0);
	gfx.PutPixel(12 + x_int, 16 + y_int, 138, 77, 0);
	gfx.PutPixel(13 + x_int, 16 + y_int, 109, 61, 0);
	gfx.PutPixel(14 + x_int, 16 + y_int, 51, 28, 0);
	gfx.PutPixel(15 + x_int, 16 + y_int, 138, 77, 0);
	gfx.PutPixel(16 + x_int, 16 + y_int, 138, 77, 0);
	gfx.PutPixel(17 + x_int, 16 + y_int, 138, 77, 0);
	gfx.PutPixel(18 + x_int, 16 + y_int, 123, 69, 0);
	gfx.PutPixel(19 + x_int, 16 + y_int, 51, 28, 0);
	gfx.PutPixel(0 + x_int, 17 + y_int, 51, 28, 0);
	gfx.PutPixel(1 + x_int, 17 + y_int, 87, 49, 0);
	gfx.PutPixel(2 + x_int, 17 + y_int, 87, 49, 0);
	gfx.PutPixel(3 + x_int, 17 + y_int, 87, 49, 0);
	gfx.PutPixel(4 + x_int, 17 + y_int, 87, 49, 0);
	gfx.PutPixel(5 + x_int, 17 + y_int, 51, 28, 0);
	gfx.PutPixel(6 + x_int, 17 + y_int, 51, 28, 0);
	gfx.PutPixel(7 + x_int, 17 + y_int, 43, 24, 0);
	gfx.PutPixel(8 + x_int, 17 + y_int, 51, 28, 0);
	gfx.PutPixel(9 + x_int, 17 + y_int, 51, 28, 0);
	gfx.PutPixel(10 + x_int, 17 + y_int, 51, 28, 0);
	gfx.PutPixel(11 + x_int, 17 + y_int, 51, 28, 0);
	gfx.PutPixel(12 + x_int, 17 + y_int, 51, 28, 0);
	gfx.PutPixel(13 + x_int, 17 + y_int, 40, 22, 0);
	gfx.PutPixel(14 + x_int, 17 + y_int, 51, 28, 0);
	gfx.PutPixel(15 + x_int, 17 + y_int, 138, 77, 0);
	gfx.PutPixel(16 + x_int, 17 + y_int, 138, 77, 0);
	gfx.PutPixel(17 + x_int, 17 + y_int, 138, 77, 0);
	gfx.PutPixel(18 + x_int, 17 + y_int, 123, 69, 0);
	gfx.PutPixel(19 + x_int, 17 + y_int, 51, 28, 0);
	gfx.PutPixel(0 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(1 + x_int, 18 + y_int, 138, 77, 0);
	gfx.PutPixel(2 + x_int, 18 + y_int, 138, 77, 0);
	gfx.PutPixel(3 + x_int, 18 + y_int, 138, 77, 0);
	gfx.PutPixel(4 + x_int, 18 + y_int, 138, 77, 0);
	gfx.PutPixel(5 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(6 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(7 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(8 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(9 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(10 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(11 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(12 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(13 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(14 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(15 + x_int, 18 + y_int, 138, 77, 0);
	gfx.PutPixel(16 + x_int, 18 + y_int, 138, 77, 0);
	gfx.PutPixel(17 + x_int, 18 + y_int, 138, 77, 0);
	gfx.PutPixel(18 + x_int, 18 + y_int, 123, 69, 0);
	gfx.PutPixel(19 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(20 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(21 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(22 + x_int, 18 + y_int, 51, 28, 0);
	gfx.PutPixel(0 + x_int, 19 + y_int, 51, 28, 0);
	gfx.PutPixel(1 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(2 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(3 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(4 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(5 + x_int, 19 + y_int, 51, 28, 0);
	gfx.PutPixel(6 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(7 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(8 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(9 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(10 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(11 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(12 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(13 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(14 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(15 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(16 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(17 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(18 + x_int, 19 + y_int, 123, 69, 0);
	gfx.PutPixel(19 + x_int, 19 + y_int, 51, 28, 0);
	gfx.PutPixel(20 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(21 + x_int, 19 + y_int, 138, 77, 0);
	gfx.PutPixel(22 + x_int, 19 + y_int, 65, 36, 0);
	gfx.PutPixel(23 + x_int, 19 + y_int, 51, 28, 0);
	gfx.PutPixel(1 + x_int, 20 + y_int, 51, 28, 0);
	gfx.PutPixel(2 + x_int, 20 + y_int, 51, 28, 0);
	gfx.PutPixel(3 + x_int, 20 + y_int, 51, 28, 0);
	gfx.PutPixel(4 + x_int, 20 + y_int, 51, 28, 0);
	gfx.PutPixel(5 + x_int, 20 + y_int, 51, 28, 0);
	gfx.PutPixel(6 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(7 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(8 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(9 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(10 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(11 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(12 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(13 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(14 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(15 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(16 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(17 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(18 + x_int, 20 + y_int, 123, 69, 0);
	gfx.PutPixel(19 + x_int, 20 + y_int, 51, 28, 0);
	gfx.PutPixel(20 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(21 + x_int, 20 + y_int, 138, 77, 0);
	gfx.PutPixel(22 + x_int, 20 + y_int, 65, 36, 0);
	gfx.PutPixel(23 + x_int, 20 + y_int, 51, 28, 0);
	gfx.PutPixel(0 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(1 + x_int, 21 + y_int, 138, 77, 0);
	gfx.PutPixel(2 + x_int, 21 + y_int, 138, 77, 0);
	gfx.PutPixel(3 + x_int, 21 + y_int, 138, 77, 0);
	gfx.PutPixel(4 + x_int, 21 + y_int, 138, 77, 0);
	gfx.PutPixel(5 + x_int, 21 + y_int, 138, 77, 0);
	gfx.PutPixel(6 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(7 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(8 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(9 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(10 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(11 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(12 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(13 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(14 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(15 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(16 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(17 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(18 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(20 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(21 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(22 + x_int, 21 + y_int, 51, 28, 0);
	gfx.PutPixel(0 + x_int, 22 + y_int, 51, 28, 0);
	gfx.PutPixel(1 + x_int, 22 + y_int, 65, 36, 0);
	gfx.PutPixel(2 + x_int, 22 + y_int, 65, 36, 0);
	gfx.PutPixel(3 + x_int, 22 + y_int, 65, 36, 0);
	gfx.PutPixel(4 + x_int, 22 + y_int, 65, 36, 0);
	gfx.PutPixel(5 + x_int, 22 + y_int, 65, 36, 0);
	gfx.PutPixel(6 + x_int, 22 + y_int, 51, 28, 0);
	gfx.PutPixel(1 + x_int, 23 + y_int, 51, 28, 0);
	gfx.PutPixel(2 + x_int, 23 + y_int, 51, 28, 0);
	gfx.PutPixel(3 + x_int, 23 + y_int, 51, 28, 0);
	gfx.PutPixel(4 + x_int, 23 + y_int, 51, 28, 0);
	gfx.PutPixel(5 + x_int, 23 + y_int, 51, 28, 0);
	gfx.PutPixel(6 + x_int, 23 + y_int, 51, 28, 0);
}

void Poo::Update(float deltaTime)
{
	pos.x += vel.x * deltaTime;
	pos.y += vel.y * deltaTime;

	//Clamp Screen For X Axis
	if (pos.x > Graphics::ScreenWidth - width)
	{
		pos.x = Graphics::ScreenWidth - height;
		vel.x = -vel.x;
	}
	else if (pos.x < 0)
	{
		pos.x = 0;
		vel.x = -vel.x;
	}

	//Clamp Screen For Y Axis
	if (pos.y > Graphics::ScreenHeight - width)
	{
		pos.y = Graphics::ScreenHeight - height;
		vel.y = -vel.y;
	}
	else if (pos.y < 0)
	{
		pos.y = 0;
		vel.y = -vel.y;
	}
}

void Poo::ProcessConsumption(const Dude& dude)
{
	if (dude.GetPos().x <= pos.x + width &&
		dude.GetPos().x + dude.GetWidth() >= pos.x &&
		dude.GetPos().y <= pos.y + height &&
		dude.GetPos().y + dude.GetHeight() >= pos.y)
	{
		isEaten = true;
	}
}

bool Poo::GetIsEaten()
{
	return isEaten;
}
