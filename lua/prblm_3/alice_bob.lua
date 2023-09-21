#!/usr/bin/env lua

io.write("What is your name?\n>")
name = io.read()

if name == "Alice" or name == "Bob" then
  io.write("Hi, ", name, "\n")
end
