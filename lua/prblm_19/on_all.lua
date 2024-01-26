#!/usr/bin/env lua

package.path = package.path .. ';/home/travisp/Workspace/test/programming_exercises/lua/lib/?.lua'
require 'lib'

local function on_all(list, func)

  for i = 1, #list, 1 do
      func(list[i])
  end

end

local list = {}

for i = 1, 20, 1 do
  table.insert(list, i)
end

local square = function(num)
  print(num * num)
end

on_all(list, square)
