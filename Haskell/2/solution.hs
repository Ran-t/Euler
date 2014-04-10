-- this program calculates the sum of all even Fibonacci numbers
-- whose values do not exceed four million.

-- function generating the Fibonacci numbers.
fibbs = 1 : 2 :    fibbs' 1 2
fibbs' x y = x+y : fibbs' y (x+y)

main = print . sum . takeWhile (<4000000) . filter even $ fibbs
