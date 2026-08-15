#ifndef __calculate_h
#define __calculate_h

extern float A, B, C;
extern float x, y, z;
extern float cube_width;
extern int width, height;
extern float zbuffer[160 * 44];
extern char  buffer[160 * 44];
extern int background_ascii_code;
extern float step;
extern int distance_from_cam;
extern float ooz;
extern int xp, yp;
extern float K1;
extern int idx;

float calculate_x(int, int, int );
float calculate_y(int, int, int);
float calculate_z(int, int, int);
void  calculate_surface(float, float, float, int);

#endif
