import Math.NumberTheory.Powers

sqrtList x = calc ((mrg $ splitInt x) ++ (repeat 0)) 0 0
    where
      splitInt n | n <= 9 = [n]
                 | otherwise = (splitInt (div n 10)) ++ [mod n 10]
      mrg a = if odd (length a) then (0 : a) else a
      calc (a : b : xs) r d = nn : calc xs nr nd
          where
            n = r * 100 + a * 10 + b
            nn = last $ takeWhile (\x -> (d + x) * x <= n) [0..9]
            nr = n - (d + nn) * nn
            nd = 10 * (d + nn + nn)

main = print(sum [sum $ take 100 $ sqrtList x | x <- filter (\x -> not $ isSquare x) [1..100]])
