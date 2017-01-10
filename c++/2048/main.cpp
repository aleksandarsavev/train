#include "main.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    log("2048");
    setup(m);
    print(m);
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


