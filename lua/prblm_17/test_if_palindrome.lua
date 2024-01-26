#!/usr/bin/env lua

io.write("Provide a string to check if it is a palindrome: ")
local str = io.read()
local list = {}
local is_palindrome = true

for char in str:gmatch"." do
  table.insert(list, char)
end

local list_size = #list

for i = 1, #list, 1 do
  io.write(list[i]..' '..list[list_size - (i - 1)]..'\n')
  if list[i] ~= list[list_size - (i - 1)] then
    is_palindrome = false
  end
end

if is_palindrome then
  io.write(str..' is a palindrome.\n')
else
  io.write(str..' is not a palindrome.\n')
end

io.write('\n')
