int u, v;
int *x, **y;

void foo() {
    x = &u;
    y = &x;
    int a = 5;
    int b = a + 3;
}
