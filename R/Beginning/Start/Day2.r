# if else loop works the same way as C, C++ it seems
a <- 10
b <- 100
count <- 0
# while loop works the same way as C, C++ it seems
while (a <- a + 1) {
  if (a > b) {
    print(paste("YES!", count))
    break
# break is needed to exit the loop
  } else {
    count <- count + 1
  }
}
# repeat - similar to while but needs a break condition
repeat{
  if (a != 20) {
    a <- a - 1
    count <- count + 1
  } else {
    print(paste(a, count - 1))
    break
  }
}
# for loop works the same way as C, C++ it seems
for (a in a:100) {
# the a in a:100 creates a sequence from a to 100
# and a is incremented automatically
  print(a)
}
# function definition
evenodd <- function(var) {
  if (var %% 2 == 0) {
    return("EVEN!")
  } else {
    return("ODD!")
  }
}
print(evenodd(a))
# functions can be called after their definition
print(evenodd(11))
for (b in b:120) {
  if (b %% 2 == 0) {
    print("next?")
    next
  }
  print(b)
}
# NULL NA NaN Inf - special values
# logical, integer, numeric (double), complex, character are data types
# typeof() and class() functions give data type and class of variable
# class() is more general, typeof() is more specific
print(paste(class(NA), typeof(NA)))
print(paste(class(NaN), typeof(NaN)))
val <- NULL
print(paste(val, class(val), typeof(val)))
x <- c(Inf, 1999)
print(is.finite(x))
y <- c(NULL, NA, NaN)
print(paste(y, class(y), typeof(y)))
z <- is(x > y)
print(paste(z, class(z), typeof(z)))
# complex numbers are represented as a + bi
# i is represented as 1i in R
print(paste(
  class(TRUE), class(10), class(3L),
  class(10.5), class(1 + 2i), class("9/27/2025")
))
# is.* functions check if the variable is of that type
# e.g. - is.numeric(), is.integer(), is.character(), is.logical(), is.complex()
# they return TRUE or FALSE
print(paste(
  is.logical(TRUE), is.numeric(10), is.integer(3L),
  is.numeric(10.5), is.complex(1 + 2i), is.character("9/27/2025")
))
a <- 10
print(paste(typeof(a), class(a)))
a <- as.character(10)
print(paste(typeof(a), class(a)))

f <- function(x) { x * x }
environment(f)
parent.env(environment(f))
# List variables in f's environment
# get("varname", environment(f))
# Retrieve a variable from that environment

print(ls())
# ls and rm are used to list and remove variables
rm(evenodd)
print(ls())