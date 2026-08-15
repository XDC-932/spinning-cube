/*#######################################################
#Author    : XDC
#Time      : 2025-12-08 10 : 26 : 21
#FileName  : main.c
########################################################*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "calculate.h"

int main(int argc, char* argv[]) {
	printf("\x1b[2J");	
	while(1) {
		memset(buffer , background_ascii_code, width * height);
		memset(zbuffer, 0                    , width * height * 4);
		for(float cube_x = - cube_width; cube_x < cube_width; cube_x += step) {
			for(float cube_y = - cube_width; cube_y < cube_width; cube_y += step) {
				calculate_surface(cube_x     , cube_y     , -cube_width, '.');	
				calculate_surface(cube_width , cube_y     , cube_x     , '$');	
				calculate_surface(-cube_width, cube_y     , -cube_x    , '~');
				calculate_surface(-cube_x    , cube_y     , cube_width , '#');
				calculate_surface(cube_x     , -cube_width, -cube_y    , ';');
				calculate_surface(cube_x     , cube_width , cube_y     , '+');
			}
		}
		printf("\x1b[H");	
		for(int k = 0; k < width * height; k++) {
			putchar(k % width ? buffer[k] : 10);
		}

		A += 0.005;
		B += 0.005;
		usleep(1000);
	}
	exit(0);
}
