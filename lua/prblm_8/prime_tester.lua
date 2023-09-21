#!/usr/bin/env lua

function isPrime(num, curr_num)

  if num % curr_num == 0 then
    return false
  elseif curr_num == 2 then
    return true
  end

  return isPrime(num, curr_num - 1)

end

function get_number(prompt)
  io.write(prompt)
  local str_num = io.read()
  return tonumber(str_num)
end

local number = get_number("Please provide a number to check the primeness of: ")

if isPrime(number, number -1) then
  io.write(number, " is prime!\n")
else
  io.write(number, " is not prime :(\n")
end
