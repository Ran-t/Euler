-- | This program finds the sum of the digits of the number 2^1000.

main = print . sum . digits $ 2^1000

digits :: Integral a => a -> [a]
digits 0 = []
digits n = n `mod` 10 : digits (n `div` 10)
