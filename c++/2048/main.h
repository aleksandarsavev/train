#ifndef MAIN_H
#define MAIN_H

const int AUTO_MODE = 1;
const int MANUAL_MODE = 2;

struct matrix {
    int width, height;
    int **m;
} *m = new matrix;

int width, height;

void setup(struct matrix *m);
void start();
void move(int *dir);

void print(struct matrix *m);
void inline log(const char * msg);
#endif
