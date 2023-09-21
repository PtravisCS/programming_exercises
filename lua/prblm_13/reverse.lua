#!/usr/bin/env lua

local list = {}
local list2 = {} --A duplicate of list for printing later to prove reversal
math.randomseed(os.time())

for i = 0, 10 do
  local rand = math.random(1, 1000)
  table.insert(list, rand)
  table.insert(list2, rand)
end

for i = 1, #list // 2 do
  local j = #list - i + 1
  list[i], list[j] = list[j], list[i]
end

io.write("Original: ", table.concat(list2, ", "), "\n\n")
io.write("Reversed: ", table.concat(list, ", "), "\n\n")
