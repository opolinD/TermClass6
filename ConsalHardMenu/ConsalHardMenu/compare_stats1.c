float compare_stats1(int a, int b, int c) {
    float minimal = 0;
    if (a <= b && a <= c) {
        minimal = a;
    }
    else if (b <= a && b <= c) {
        minimal = b;
    }
    else if (c <= b && c <= a) {
        minimal = c;
    }
    return minimal;
}