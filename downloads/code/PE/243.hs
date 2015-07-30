import Math.NumberTheory.Primes
import Data.Ratio

t = 15499 % 94744
frac = (1,2):[ ((fst a) * (b - 1), ((snd a) * b)) | (a,b) <- zip frac (tail primes)]
q = head[ x | x <- frac, (fst x) % (snd x) < t]
ans = head[ (snd q) * k | k <- [1,2..], ((fst q) * k) % ((snd q) * k - 1) < t]
main = print(ans)
