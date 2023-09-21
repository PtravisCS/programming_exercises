#!/usr/bin/env lua

function nth_term(k)
  return ((-1)^(k+1)) / (2 * k - 1)
end

local series = 0

for n = 1, 100000000 do 
  series = series + nth_term(n)
end

series = series * 4

io.write(series,"\n")
