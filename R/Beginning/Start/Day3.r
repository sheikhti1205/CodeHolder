# Lexical Scoping in R
make.power <- function(n){
    pow <- function(x){
        x <- x^n
    }
    pow
}
cube <- make.power(3)
square <- make.power(2)

print(paste("Square of 2 is: ", square(2)))
print(paste("Cube of 3 is: ", cube(3)))
ls(environment(cube))

x <- 1:10
y <- c(3, 1, 5, 2, 3, 8, 4, 7, 6, 9)

plot(x, y, type="l", col="#000000", lwd=2,
     main="Basic Line Plot", xlab="X", ylab="Y")
