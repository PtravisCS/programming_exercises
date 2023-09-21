#!/usr/bin/env lua

function is_leap_year(year)
  if year % 4 == 0 or year % 400 == 0 then
    return true
  end

  return false
end

local date = os.date("*t")
local year = date["year"]

for i = year, year + 20 do
  if is_leap_year(i) then
    io.write(i,"\n")
  end
end
