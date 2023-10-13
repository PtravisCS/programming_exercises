#!/usr/bin/env lua

io.write("Provide a string to check if it is a palindrome: ")
local str = io.read()
local list = {}

for char in str:gmatch"." do
  table.insert(list, char)
end

for i = 0, #list, 1 do

end

io.write('\n')
