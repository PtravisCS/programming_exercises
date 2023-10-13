#!/usr/bin/env lua

package.path = package.path .. ';/home/travisp/Workspace/test/programming_exercises/lua/lib/?.lua'
require 'lib'

local list = generate_random_array(100, 0, 100)

local total = 0

for i, num in ipairs(list) do

  io.write(i..': '..total..' + '..num..' = '..total + num..'\n')
  total = total + num

end

io.write('Grand total is: '..total..'\n')
