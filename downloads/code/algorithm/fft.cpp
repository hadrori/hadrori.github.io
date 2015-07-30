typedef complex<double> cd;
vector<cd> fft(vector<cd> f, bool inv)
{
        int n, N = f.size();
        for(n=0;;n++) if(N == (1<<n)) break;
        for (int m = 0; m < N; m++) {
                int m2 = 0;
                for(int i = 0; i < n; i++) if(m&(1<<i)) m2 |= (1<<(n-1-i));
                if(m < m2) swap(f[m], f[m2]);
        }

        for(int t=1;t<N;t*=2){
                double theta = acos(-1.0) / t;
                cd w(cos(theta), sin(theta));
                if(inv) w = cd(cos(theta), -sin(theta));
                for(int i=0;i<N;i+=2*t){
                        cd power(1.0, 0.0);
                        for (int j = 0; j < t; j++) {
                                cd tmp1 = f[i+j] + f[i+t+j] * power;
                                cd tmp2 = f[i+j] - f[i+t+j] * power;
                                f[i+j] = tmp1;
                                f[i+t+j] = tmp2;
                                power = power * w;
                        }
                }
        }
        if(inv) for(int i = 0; i < N; i++) f[i] /= N;
        return f;
}
