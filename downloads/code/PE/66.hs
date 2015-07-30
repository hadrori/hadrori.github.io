int_sqrt = floor . sqrt . fromIntegral
is_square n = n == m * m where m = int_square n
is_ans x y n = x^2 - n * (y^2) == 1

next_frac n (m0,(a,b,c)) = (m, (a2 `div` d, b2 `div` d, c2 `div` d)) where
    b1 = b - m * c
    c2 = a * a * n - b1 * b1
    a2 = a * c
    b2 = -b1 * c
    d = gcd a2 (gcd b2 c2)
    m = floor (((sqrt (fromIntegral n)) * (fromIntegral a)
                + (fromIntegral b)) / (fromIntegral c))
        
pell_solve n = head [x | (x, y) <- zip (tail p) (tail q), is_ans x y n] where
    a n = (0,(1,0,1)):[next_frac n x | x <- a n]
    r = map fst (tail (a n))
    p = 1:(head r):[a * p1 + p0 | (a, p0, p1) <- zip3 (tail r) p (tail p)]
    q = 0:1:[a * q1 + q0 | (a, q0, q1) <- zip3 (tail r) q (tail q)]

greater x y = if snd x >= snd y then x else y
a = [(n, pell_solve n) | n <- [2..1000], not (is_square n)]
main = print (fst (foldr greater (0, 0) a))
