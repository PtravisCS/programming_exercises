#!/usr/bin/env lua

io.write("Please provide a number: ")
str_number = io.read()

number = tonumber(str_number)
sum = 1

if number > 1 then
  for i = 2, number, 1 do
    sum = sum + i 
  end

  io.write(sum, "\n")
else
  io.write("1\n")
end
