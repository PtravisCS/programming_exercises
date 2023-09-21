#!/usr/bin/env lua

function contains_int(n)
  if string.find(n, '^[+-]?%d+$') then
    return true
  else
    return false
  end
end

function get_number(prompt)
  local str_num = ''

  while not contains_int(str_num) do
    io.write(prompt)
    str_num = io.read()
  end

  return tonumber(str_num)
end

-- Function assumes that the table has already been sorted.
function in_list(num, list)
  if list[#list // 2] < num then

    for i = (#list // 2), #list do
      if list[i] == num then
        return true
      end
    end

    return false
  else

    for i = 0, (#list // 2) do
      if list[i] == num then
        return true
      end
    end

    return false
  end
end

local list = {}
math.randomseed(os.time())

for i = 0, 10000000 do
  local rand = math.random(1, 10000000)
  table.insert(list, rand)
end

local num = 0

io.write(table.concat(list, ", \n", #list - 10), "\n\n")
io.write("Enter -1 to quit\n\n")

table.sort(list) -- Table must be sorted for rest of code to work

while num ~= -1 do
  num = get_number("Please provide a number between [1, 10000]: ")

  if in_list(num, list) then
    io.write(num, " is in the list.\n")
  else
    io.write(num, " is not in the list.\n")
  end
end
