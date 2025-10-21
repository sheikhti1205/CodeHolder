name <- readline(prompt = "Enter your name: ")
print(paste0("Hello, ", name, ". Nice to meet you!"))
print("Enter numbers only: ")
y <- scan()
x <- 1:10
print(paste(x))
plot(x, y, type = "l", col = "#000000", lwd = 2,
     main = "Second Plot", xlab = "X", ylab = "Y")