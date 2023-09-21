#!/usr/bin/env lua

io.write("Never tell me the odds\n")

local list = {}
math.randomseed(os.time())

for i = 1, 20 do
  local rand = math.random(1, 100)
  table.insert(list, rand)
end

for i = 1, #list, 2 do
  io.write(i, ": ", list[i], "\n") 
end
