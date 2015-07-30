import Math.NumberTheory.Primes
import Data.Set (fromList, size)

m = 50000000
ansList = [x + y + z | x <- takeWhile (< m) $ map (^2) primes,
                       y <- takeWhile (\a -> a + x < m) $ map (^3) primes,
                       z <- takeWhile (\a -> a + x + y < m) $ map (^4) primes]
main = print(size $ fromList ansList)
 
 
