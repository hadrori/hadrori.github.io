a = 2:[if x `mod` 3 == 2 then (x + 1) `div` 3 * 2 else 1| x <- [1..100]]
p = 1:head a:[x * y + z | (x, y, z) <- zip3 (tail a) (tail p) p]
dig x | x == 0 = []
      | otherwise = (x `mod` 10):(dig (x `div` 10))
main = print((sum . dig) (p !! 100))

