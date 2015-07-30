namespace D2 {
std::vector<point> convex_hull(std::vector<point> ps)
{
        int n = ps.size(), k = 0;
        if(n < 3) return ps;
        std::sort(begin(ps),end(ps));
        std::vector<point> ret(2*n);

        for (int i = 0; i < n; ret[k++] = ps[i++])
                while (k >= 2 and ccw(ret[k-2], ret[k-1], ps[i]) < 1) k--;
        for (int i = n-2, t = k+1; i >= 0; ret[k++] = ps[i--])
                while (k >= t and ccw(ret[k-2], ret[k-1], ps[i]) < 1) k--;
        ret.resize(k-1);
        return ret;
}
}
