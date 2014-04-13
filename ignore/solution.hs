if (n > 99) count += 7
    if (n % 100 /= 0) 
        count += 3
        count += (n `rem` 100)
    else count += (n )
    if (n % 10 /= 0)
        count += (n `rem` 10)
        count += if n `elem` ppTy then 2
                                  else tens ((n `div` 10) * 10)


ppTy = [4, 6, 7, 9]

tens n = case n of
    10 -> 3
    20 -> 6
    30 -> 6
    50 -> 5
    80 -> 6
