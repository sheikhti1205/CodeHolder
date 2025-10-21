"R can directly print this message"

# Assignments work in three ways typically -
# equal sign "=" a = 10
# left assignment "<-" a <- 10
# right assignment "->" 10 -> a

# R doesn't support Multi-line and Documentation comments.
# It only supports single-line comments drafted by a '#' symbol.

# Printing -
a <- 100
b <- 80

print(a - b) # Prints 20

# Basic operators such as +, -, *, / exist
# Additionally -
# Power operator "^" (a^2)
# Modulo operator "%%" (a %% 33) returns the remainder
print(paste("A powered by 2 : ", a^2))
print(paste("A modulo 33 : ", a %% 33))

# New cat--
cat("This is cat?", a, " - ", b, " = ", a - b, "\n")

# Any non-zero element is considered TRUE even imaginary numbers
# c(var_A, var_B) combines element into a vector. Combine or concatenate
a <- c(10, 20)
# Meaning - a[1] = 10 and a[2] = 20
cat(a[1], " ", a[2], "\n")
b <- c(0, 4 + 3i)

# Logical operator AND "&"
# Both element of the same index are true prints TRUE
# This works element wise
print(a & b)
# OR "|" operator...same as "&"
print(a | b)
# ____N.B. The above single ones works element wise.
# Simply put for all elements of a variable

# NOT "!" operator...the opposite of what state the element is in
print(!a)
# TRUE becomes FALSE and FALSE becomes TRUE

print(a[1] && b[1])

# New ~ need to specify the index of the element for vectors...
# Otherwise it'll fail --- OoO ><

# This "&&" compares only the first element unlike the "&" which does for all
# Same for "||"

print(a[1] || b[1]) # Check line 48 & 49

# Relational Operators
# Less than "<" compares all element of the same index a[i] to b[i]

b <- c(0, 10)

print(a < b)

# New ~ can't compare complex values like a+ib

# Similarly Greater than ">"

print(a > b) # Check line 62

# Again "<=" and ">=" and "!=" and "=="

# Assignment operator again...
a <- 10 # a = 10 less preferred
a <<- c(100, 200) # Works globally... "<<-" or "->>"
# Needed if we're working with variables outside of a functions access
var <- c(100, 200, "string?")
print(var %in% a)
# %in% prints TRUE or FALSE
# If a value inside the first variable is present in the second variable

# Matrix
mat <- matrix(c(1, 2, 3, 4, 5, 6, 7, 8, 9), nrow = 3, ncol = 3)
# Row --- Col |||
# Default there's "byrow = FALSE" which means matrix is filled column by column
# Setting "byrow = TRUE" makes it go row by row...
print(mat)
# See...output...
mat <- matrix(c(1, 2, 3, 4, 5, 6, 7, 8, 9), nrow = 3, ncol = 3, byrow = TRUE)
print(mat)
# help(reserved)
# Launches help but doesn't work in vscode...use terminal or Rstudio
a <- 10
print("Enter")
if (a > 0) {
  print("Positive Number.")
} else if (a == 0) {
  print("It's Zero!")
} else {
  print("Negative Number")
}
