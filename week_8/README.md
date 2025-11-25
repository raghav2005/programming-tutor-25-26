# Week 7

- [Leetcode](#leetcode)
- [Haskell](#haskell)
- [Engineering Challenges (ESP32 \<-\> Nucleo Connection via I2C)](#engineering-challenges-esp32---nucleo-connection-via-i2c)

## Leetcode

- [Determine if Two Strings Are Close (Medium)](https://leetcode.com/problems/determine-if-two-strings-are-close/) 
  - [Python Solution](leetcode_sols/leetcode_1_sol.py)

## Haskell

- typeclasses
  
  - `Eq` - equality (must define == and /=)
  
  - `Ord` - ordering (must define <, <=, >, >=)
  
  - `Num` - numbers (providing +, -, *, /, etc.)
  
  - `Integral` - subclass of num for Int/Integer
  
  - `Fractional` - subclass of num for Float/Double
  
  - `Show` - allows converting to a human-readable String
  
  - `Read` - allows converting a String back into another type
  
  - `Enum` - sequentially ordered types that can be enumerated
  
  - `Bounded` - has an upper and lower bound
  
  - there are more but we don't need to go over them right now (honestly, just the first 5 here are enough)

- lambda functions

  - `\var1 var2 ... -> function`

  - e.g. `\x y -> x + y`

- partially applied functions

- cons (`:`) vs append (`++`)

- `map` - `map f xs`

- `filter` - `filter f xs`

  - this is filter true i.e. `filter (>5) (take 10 [1..])` results in `[6,7,8,9,10]`

- `fold`

  - `foldl` - `foldl f acc xs` means append acc to the beginning of xs and apply the operation f from left to right

    - e.g. `foldl (/) 4 [1.0,2.0,4.0]` =>

    - 4 : (1 : (2 : (4 : []))) =>

    - (((4 / 1) / 2) / 4) =>

    - ((4 / 2) / 4) =>

    - 2 / 4 =>

    - 0.5

  - `foldr` - `foldr f acc xs` means append acc to the end of xs and apply the operation f from right to left

    - e.g. `foldr (/) 2 [8,12,24,4]` =>

    - 8 : (12 : (24 : (4 : 2))) =>

    - 8 / (12 / (24 / (4 / 2))) =>

    - 8 / (12 / (24 / 2)) =>

    - 8 / (12 / 12) =>

    - 8 / 1 =>

    - 8.0

  - `foldl1` / `foldr1` - no `acc`
