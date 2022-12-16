float compare_stats(int a, int b, int c, int d) {
    float minimal = 0;
    if (a <= b && a <= c && a <= d) {
        minimal = a;
    }
    else if (b <= a && b <= c && c <= d) {
        minimal = b;
    }
    else if (c <= b && c <= a && c <= d) {
        minimal = c;
    }
    else {
        minimal = d;
    }
    return minimal;
}