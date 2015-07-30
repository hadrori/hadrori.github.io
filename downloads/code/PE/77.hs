import Math.NumberTheory.Primes
n = 5000
solver h res
  | res < 0 = 0
  | res == 0 = 1
  | otherwise = sum [solver x (res-x) | x <- takeWhile (<= h) primes]
main = print (head [x| x <- [0..], solver x x > n])

