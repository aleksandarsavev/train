#include "main.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    srand(time(NULL));
//    log("2048 (c)");
    struct matrix *m = new matrix;
    setup(m);
    //print(m);
    cout << rnd_number() << '\n';
}

void setup(struct matrix *m) {
    m->width = 8;
    m->height = 8;
    m->m = new int*[m->height];
    for (int i = 0; i < m->height; i++) {
        m->m[i] = new int[m->width];
    }
}

void print(struct matrix *m) {
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
	   cout << m->m[i][j] << setw(10) << ' ';
	}
	cout << '\n';
    }
}

void inline log(const char *msg) {
    cout << msg << '\n';
}

int inline rnd(int max) {
    return (rand() % max) + 1;
}

int inline rnd_number() {
    return rnd(2) * 2;
}

int rnd_position(struct matrix *m) {
    bool found = false;
    int x, y;
    while (!found) {
        
    }
}
