#!/usr/bin/env lua

package.path = package.path .. ';/home/travisp/Workspace/test/programming_exercises/lua/lib/?.lua'
require 'lib'

local list = generate_random_array(100, 0, 100)
local for_sum = 0
local while_sum = 0
local recursive_sum = 0

-- Summing with for loop
for i = 1, #list, 1 do
  for_sum = for_sum + list[i]
end

-- Summing with while loop
local i = 1
while (i < #list + 1) do
  while_sum = while_sum + list[i]

  i = i + 1
end

-- Summing with recursive loop
function looper(i, list)

  if (i < #list) then
    return list[i] + looper(i + 1, list)
  else
    return list[i]
  end

end

recursive_sum = looper(1, list)

io.write('for sum: '..for_sum..'\n')
io.write('while sum: '..while_sum..'\n')
io.write('recursive sum: '..recursive_sum..'\n')
