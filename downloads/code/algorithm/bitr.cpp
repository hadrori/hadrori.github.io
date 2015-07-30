// T have +-*/ and 0
template<class T> class bitr
{
public:
    
        bit<T> b, c;

        bitr(){}
        bitr(int N) {
                b = BIT<T>(N);
                c = BIT<T>(N);
        }
        // add x to [i,j) 
        void add(int i, int j, T x){
                b.add(i,-i*x); b.add(j,j*x);
                c.add(i,x); c.add(j,-x);
        }
        // sum [0,i)
        T sum(int i){ return b.sum(i+1)+c.sum(i+1)*i;}
        // sum [i,j)
        T sum(int i, int j){ return sum(j)-sum(i);}
};
