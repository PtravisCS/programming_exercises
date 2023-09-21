#!/usr/bin/env lua

local list = {}
math.randomseed(os.time())

for i = 0, 20 do
  table.insert(list, math.random(1, 1000))
end

io.write("Table: \n ", table.concat(list, ",\n "), "\n\n")
io.write("Largest element: ", math.max(table.unpack(list)), "\n")
