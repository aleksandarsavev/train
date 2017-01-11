#ifndef MAIN_H
#define MAIN_H

typedef int direction;

const int AUTO_MODE = 1;
const int MANUAL_MODE = 2;

struct matrix {
    int width, height;
    int **m;
};

int width, height;

void setup(struct matrix *m);
void start();
void move(direction dir);

void print(struct matrix *m);
void inline log(const char * msg);
int inline rnd(int max);
int inline rnd_number();
void rnd_position();

#endif
