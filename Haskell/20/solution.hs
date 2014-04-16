-- | The number n! = n * (n - 1) * .. * 3 * 2 * 1
-- Find the sum of the digits in the number 100!

import Data.List (foldl1')

main = print . sum . digits . fac $ 100

digits :: Integral a => a -> [a]
digits 0 = []
digits n = n `mod` 10 : digits (n `div` 10)

fac n = foldl1' (*) [1 .. n]
