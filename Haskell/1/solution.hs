-- returns the sum of all the multiples of 3 or 5 below 1000.
import Data.Set (toList, fromList, union)

main = print . sum . toList 
     $ fromList [3,6..999] `union` fromList [5,10..999]
