int u, v;
int *x, *y;

void foo() {
    // Case A: dead pointer assignment, x never used after
    x = &u;

    // Case B: dead chain - y computed but never used
    y = &v;

    // Case C: dead arithmetic, result unused
    int a = 10;
    int b = a * 2;

    // Case D: partially dead - c used, d not
    int c = 1;
    int d = 2;
    int e = c + 1;

    // Case F: dead store through pointer (writes to x but x never read after)
    *x = 99;
}

void bar() {
    // Case E: live pointer assignment, x used after
    x = &u;
    int val = *x; // x is live here, so assignment to x is not dead
}