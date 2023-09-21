#!/usr/bin/env lua

function get_value_in_table(table, prompt)
  local str_number = ""

  while table[str_number] == nil do
    io.write(prompt) 
    str_number = io.read()
  end

  return str_number
end

function get_number(prompt)
  io.write(prompt)
  local str_num = io.read()
  return tonumber(str_num)
end

function sum_of_n_natural_numbers(n)
  return (n * (n + 1) // 2)
end

function factorial(n)
  if n == 0 then
    return 1
  elseif n > 20 then
    --Stirling's Approximation for n!
    local e = 2.7182818284590452353602874713527
    return (n ^ n) * (e ^ (0 - n)) * math.sqrt(2 * math.pi * n) * (1 + (1 / (12 * n)))
  else 
    local result = 1

    for i = 2, n, 1 do
      result = result * i
    end

    return result
  end
end

local number = get_number("Please provide a number: ")
local choice = get_value_in_table({ ["1"] = true, ["2"] = true }, "Do you want the (1) Sum or (2) Product of the series [1, " .. number .. "]? ")

if choice == "1" then
  io.write("The sum is: ", sum_of_n_natural_numbers(number), "\n")
else
  io.write("The product is: ", factorial(number), "\n")
end
