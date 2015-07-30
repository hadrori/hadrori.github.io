ans :: Integer
ans = sum [ x^x `mod` 10000000000 | x <- [1..1000]] `mod` 10000000000
main = print(ans)