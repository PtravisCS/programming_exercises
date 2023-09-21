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

math.randomseed(os.time())
local secret = math.random(1, 10000)
local guess = 0
local last_guess = 0
local tries = 0

while guess ~= secret do

  guess = get_number("Guess a number between 1 and 10000: ")

  if guess < secret then
    io.write("Too low\n")
  elseif guess > secret then
    io.write("Too high\n")
  end

  if guess ~= last_guess then
    tries = tries + 1
  end

end

io.write("You guessed correctly!\n")
io.write("You took ", tries, " tries to correctly guess the number\n")
