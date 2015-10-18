int binary_search(int l, int r) {
    int lb = l, ub = r, mid;
    while(ub-lb>1) {
        mid = (lb+ub)/2;
        if(ok(mid)) ub = mid;
        else lb = mid;
    }
    return ub;
}

double binary_search(double l, double r) {
    double lb = l, ub = r, mid;
    int cnt = 100;
    while(cnt--) {
        mid = (lb+ub)/2;
        if(ok(mid)) ub = mid;
        else lb = mid;
    }
    return ub;
}
