void rsucc(int &r, deque<int> &q) {
    while(!q.empty() and seq[q.back()] >= seq[r]) q.pop_back();
    q.push_back(r++);        
}
// assume l < r
void lsucc(int &l, deque<int> &q) { if(q.front() == l++) q.pop_front(); }

vector<int> slide_min(const vector<int> &seq, int w) {
    vector<int> ret;
    deque<int> q;
    int l = 0, r = 0, n = seq.size();
        
    while(r < w) rsucc(r,q);
    while(r < n) {
        rsucc(r,q); lsucc(l,q);
        ret.push_back(seq[q.front()]);
    }
    return ret;
}
