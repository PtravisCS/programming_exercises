function str_contains_int(n)
  if string.find(n, '^[+-]?%d+$') then
    return true
  else
    return false
  end
end

function str_contains_float(n)
  if string.find(n, '^[+-]?%d+%.%d$') then
    return true
  else
    return false
  end
end

function str_contains_number(n)
  if contains_int(n) or contains_float(n) then
    return true
  else
    return false
  end
end

function get_int(prompt)
  local str_num = ''

  while not contains_int(str_num) do
    io.write(prompt)
    str_num = io.read()
  end

  return tonumber(str_num)
end

function get_float(prompt)
  local str_num = ''

  while not contains_float(str_num) do
    io.write(prompt)
    str_num = io.read()
  end

  return tonumber(str_num)
end

function get_number(prompt)
  local str_num = ''

  while not contains_number(str_num) do
    io.write(prompt)
    str_num = io.read()
  end

  return tonumber(str_num)
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

function generate_random_array(size, min, max)
  local list = {}
  math.randomseed(os.time())

  for i = 0, size do
    local rand = math.random(min, max)
    table.insert(list, rand)
  end

  return list
end
