{-# LANGUAGE BangPatterns #-}
import Data.Vector.Unboxed (Vector, unfoldr, fromList, (!))
import qualified Data.ByteString.Lazy.Char8 as B
import System.IO.Unsafe (unsafePerformIO)


main = print vectorPass

vec = unsafePerformIO . fmap parse . B.readFile $ "grid.dat"

vectorPass = antidiagonalPass 342 . commonPass 0 $ 0

commonPass ix n 
    | (ix == 399)           = n
    | (mod (ix+3) 19 == 0 ) = commonPass (ix+3) n
    | otherwise            = commonPass (ix+1) (maximum [h,v,d,n])
    where
        h = (vec ! (ix+0)) * (vec ! (ix+1)) 
          * (vec ! (ix+2)) * (vec ! (ix+3))
        v | ix >= 339 = 0
          | otherwise = (vec ! (ix+20*0)) * (vec ! (ix+20*1)) 
                      * (vec ! (ix+20*2)) * (vec ! (ix+20*3))
        d | ix >= 336 = 0
          | otherwise = (vec ! (ix+21*0)) * (vec ! (ix+21*1)) 
                      * (vec ! (ix+21*2)) * (vec ! (ix+21*3))
antidiagonalPass ix n
    | (ix < 4)              = n
    | (mod (ix-3) 20 == 0)   = antidiagonalPass (ix-3) n
    | otherwise             = antidiagonalPass (ix-1) (max a n)
    where
        a = (vec ! (ix+19*0)) * (vec ! (ix+19*1))
          * (vec ! (ix+19*2)) * (vec ! (ix+19*3))


-- Fill a new vector from a file containing a list of numbers.
parse = unfoldr step
  where
     step !s = case B.readInt s of
        Nothing       -> Nothing
        Just (!k, !t) -> Just (k, B.tail t)
