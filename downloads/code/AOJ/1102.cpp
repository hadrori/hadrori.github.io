#include <bits/stdc++.h>
using namespace std;
const string opl = "+-*(", opr = "+-*)", op = "*+-";

typedef complex<int> number;
string s;

void insert_b(int p)
{
        int d = 0, l = p, r = p;
        do {
                l--;
                if(s[l] == ')') d++;
                if(s[l] == '(') d--;
                if(l == 0 or (d == 0 and opl.find(s[l-1]) != string::npos)) break;
        } while(1);

        do {
                if(s[r] == ')') d++;
                if(s[r] == '(') d--;
                r++;
                if(r == (int)s.size() or (d == 0 and opr.find(s[r]) != string::npos)) break;
        } while(1);

        s = s.substr(0,l)+"("+s.substr(l,r-l)+")"+s.substr(r);
}

void bracket()
{
        for (int i = 0; i < (int)s.size(); i++) if(s[i] == '*') insert_b(i++);
        for (int i = 0; i < (int)s.size(); i++) if(s[i] == '+' or s[i] == '-') insert_b(i++);
}

string normalize(string t)
{
        int p = 0;
        while(p < (int)t.size() and t[p] == '0') p++;
        string ret = t.substr(p);
        if(!ret.size()) ret = "0";
        return ret;
}

number parse(int l, int r)
{
        if(s[l] == '(') l++, r--;
        int m = l, d = 0;
        while(m < r and (d or op.find(s[m]) == string::npos)) {
                if(s[m] == '(') d++;
                if(s[m] == ')') d--;
                m++;
        }
        if(m == r) {
                string t = s.substr(l,r-l);
                if(s[l] == '(') return parse(l,r);
                if(t == "i") return number(0,1);
                t = normalize(t);
                if((int)t.size() > 4 and t != "10000") throw 0;
                return number(atoi(t.c_str()), 0);
        }
        else {
                number x = parse(l,m), y = parse(m+1,r), z;
                if(s[m] == '+') z = x+y;
                else if(s[m] == '-') z = x-y;
                else if(s[m] == '*') z = x*y;
                if(abs(z.real()) > 10000 or abs(z.imag()) > 10000) throw 0;
                return z;
        }
}

string solve()
{
        bracket();
        number val;
        try {
                val = parse(0,s.size());
        } catch(int e) {
                return "overflow";
        }
        string ans = "";
        if(val.real() != 0) ans += to_string(val.real());
        if(val.imag() != 0) {
                if(val.real() and val.imag() > 0) ans += "+";
                ans += to_string(val.imag())+"i";
        }
        if(ans.size() and ans[0] == '+') ans = ans.substr(1);
        if(!ans.size()) ans = "0";
        return ans;
}

bool input()
{
        return cin >> s;
}

int main()
{
        while(input()) cout << solve() << endl;
        return 0;
}
