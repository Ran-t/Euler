import Data.List (sort)

digits :: Int -> [Int]
digits 0 = []
digits n = n `rem` 10 : digits (n `quot` 10)

eqDigits :: [[Int]] -> Bool
eqDigits (x:[]) = True
eqDigits (x:y:xs) | (x == y)    = eqDigits (y:xs)
                  | otherwise  = False

products :: Int -> [Int]
products n = map ($ n) $ map (*) [1..6]

solution  :: Int
solution' :: Int -> Int
solution = solution' 1
solution' n = case (eqDigits . map sort . map digits . products $ n) of
                True -> n
                False -> solution' (n+1)

main = print solution
