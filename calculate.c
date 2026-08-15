/*#######################################################
#Author    : XDC
#Time      : 2025-12-08 10 : 26 : 21
#FileName  : calculate.c
########################################################*/

#include "calculate.h"
#include <math.h>

float A, B, C;
float x, y, z;
float cube_width = 15;
int   width = 160, height = 44;
float zbuffer[160 * 44];
char  buffer[160 * 44];
int   background_ascii_code = ' ';
float step = 0.6;
int   distance_from_cam = 60;
float ooz;
int   xp, yp;
float K1 = 40;
int   idx;

float calculate_x(int i, int j, int k) {
	return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
		   j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);  
}

float calculate_y(int i, int j, int k) {
	return j * cos(A) * cos(C) + k * sin(A) * cos(C) - j * sin(A) * sin(B) * sin(C) +
		   k * cos(A) * sin(B) * sin(C) - i * cos(B) * sin(C);
}


float calculate_z(int i, int j, int k) {
	return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i* sin(B);
}

void calculate_surface(float cube_x, float cube_y, float cube_z, int ch) {
	x   = calculate_x(cube_x, cube_y, cube_z);
	y   = calculate_y(cube_x, cube_y, cube_z);
	z   = calculate_z(cube_x, cube_y, cube_z) + distance_from_cam;
	ooz = 1 / z;
	xp  = (int)(width  / 2 - 2 * cube_width + K1 * ooz * x * 2); 
	yp  = (int)(height / 2 + K1 * ooz * y); 

	idx = xp + yp * width;
	if(idx >= 0 && idx < width * height) {
		if(ooz > zbuffer[idx]) {
			zbuffer[idx] = ooz;
			buffer[idx]  = ch;
		}
	}
}
