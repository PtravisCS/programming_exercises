#!/usr/bin/env lua

num_1 = 3
num_2 = 5

function sum_divis_by(divisor, end_num)

  local count_divis_nums = (end_num - 1) // divisor
  local biggest_divis = divisor * count_divis_nums
  
  return (count_divis_nums * (divisor + biggest_divis)) // 2

end

io.write("Please provide a number: ")
local str_number = io.read()

local number = tonumber(str_number)

if number > 1 then

  local first_sum = sum_divis_by(num_1, number) 
  local second_sum = sum_divis_by(num_2, number)
  local combined_sum = sum_divis_by(num_1 * num_2, number)
  local total = first_sum + second_sum - combined_sum

  io.write("Sum of all multiples of ", num_1, " and ", num_2, " for the range [1, ", number, ") = ", total, "\n")
else
  io.write("1\n")
end
