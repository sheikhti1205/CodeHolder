# Indexing starts from 1, not 0

# 1. Vectors
# homogeneous
# one-dimensional

# 1.1 Creating a vector
# X = c(1, 3, 5, 7, 8)
# Y<- seq(1, 10, length.out = 5)
# Z<- 2:7

# 1.2 Functions
# length(x)
# sort(X)
# sort(X, decreasing = TRUE)

# 1.3 Accessing elements
# X[2]
# Y[c(4, 1)]

# 1.4 Deleting
# M <- c(8, 10, 2, 5)
# M <- NULL

# 2. Lists
# ordered collection of objects
# heterogeneous
# one-dimensional

# 2.1 Creating
# 1.
# empId = c(1, 2, 3, 4)
# empName = c("Raju", "Sandeep", "karim", "Rajjak")
# numberOfEmp = 4
# empList = list(empId, empName, numberOfEmp)
# print(empList)

# 2.2 Accessing
# 1.
#  empId = c(1, 2, 3, 4)
#  empName = c("Raju", "Sandeep", "karim", "Rajjak")
#  numberOfEmp = 4
#  empList = list(
#    "ID" = empId,
#    "Names" = empName,
#    "Total Staff" = numberOfEmp
#    )
#  print(empList)
#  cat("Accessing name components using $ command\n")
#  print(empList$Names)

# 2.
# print(empList[[2]])
# print(empList[[2]][2])

# 2.3 Modifying
# empList[[1]][5] = 5
# empList[[2]][5] = "Rahim"

# 2.4 Concatenation
# list = c(list, list1)

# 2.5 Adding Item
# my_numbers = c(1,5,6,3)
# append(my_numbers, 45)

# 2.6 Deleting
# print(empList[-3])
# print(empList[[2]][-2])

# 2.7 Converting List to Vector
# lst <- list(1:5)
# print(lst)
# vec <- unlist(lst)
# print(vec)

# 2.8 List to matrix
# lst1 <- list(list(1, 2, 3),
#             list(4, 5, 6))
# cat("The list is:\n")
# print(lst1)
# cat("Class:", class(lst1), "\n")
# mat <- matrix(unlist(lst1), nrow = 2, byrow = TRUE)
# cat("\nAfter conversion to matrix:\n")
# print(mat)
# cat("Class:", class(mat), "\n")


# 3. Data Frames
# objects which are used to store tabular data
# heterogeneous
# two-dimensional
# lists of vectors of equal lengths

# 3.1 Create Data Frame
# Name = c("Amiya", "Raj", "Asish")
# Language = c("R", "Python", "Java")
# Age = c(22, 25, 45)
# df = data.frame(Name, Language, Age)
# print(df)

# 3.2  Printing Structure of the R Data Frame
# Get the data types of the data
# friend.data <- data.frame(
#     friend_id = c(1:5),
#     friend_name = c("Sachin", "Sourav",
#                     "Dravid", "Sehwag",
#                     "Dhoni"),
#     stringsAsFactors = FALSE
# )
# print(str(friend.data))

# 3.3 Summary of Data
# friend.data <- data.frame(
#     friend_id = c(1:5),
#     friend_name = c("Sachin", "Sourav",
#                     "Dravid", "Sehwag",
#                     "Dhoni"),
#     stringsAsFactors = FALSE
# )
# print(summary(friend.data))

# 3.4 Extract Data
# result <- data.frame(friend.data$friend_name)
# print(result)

# 3.5 Expand Data
# friend.data$location <- c("Kolkata", "Delhi",
#                           "Bangalore", "Hyderabad",
#                           "Chennai")
# resultant <- friend.data
# print(resultant)

# 3.6 Access Items
# print(friend.data[1])
# friend.data[['friend_name']]
# print(friend.data$friend_id)

# 3.7 Amount of Rows and Columns
# dim(friend.data)

# 3.8 Add Rows and Columns
# 1. Rows
# New_Product <- c(104, "Sunglasses", 39.99, 40)
# Products <- rbind(Products, New_Product)

# 2. Columns
# Discount <- c(5, 10, 8)
# Products <- cbind(Products, Discount)

# 3.9 Remove Rows and Columns
# 1. Rows
# data <- subset(data, friend_id != 3)

# 2. Columns
# data <- select(data, -location)

# 3.10 Combining Data Frames in R
# 1. Vertically
# combined_df <- rbind(df1, df2)

# 2. Horizontally
# combined_df <- cbind(df1, df2)


# 4. Matrices
# rectangular arrangement of numbers in rows and columns
# homogeneous
# two-dimensional
# Syntax -> matrix(data, nrow, ncol, byrow, dimnames)

# 4.1 Creating
# A = matrix(
#   c(1, 2, 3, 4, 5, 6, 7, 8, 9),
#   nrow = 3,
#   ncol = 3,
#   byrow = TRUE
# )
# rownames(A) = c("a", "b", "c")
# colnames(A) = c("d", "e", "f")
# cat("The 3x3 matrix:\n")
# print(A)

# 4.2 Special Matrices
# 1. all rows and columns are filled by a single constant
# print(matrix(5, 3, 3))

# 2. Diagonal matrix
# print(diag(c(5, 3, 3), 3, 3))

# 3. Identity matrix
# print(diag(1, 3, 3))

# 4.3 Accessing Elements
# 1. Accessing rows
# print(A[1:2, ])

# 2. Accessing columns
# print(A[, 1:2])

# 3. Accessing Elements
# print(A[1, 2])

# 4.4 Accessing Submatrices
# print(A[1:3, 1:2])

# 4.5 Modifying Elements
# A[3, 3] = 30

# 4.6 Matrix Concatenation
# 1. Concatenation of a row
# C = rbind(A, B)

# 2. Concatenation of a column
# C = cbind(A, B)

# 4.7 Adding Rows and Columns
# 1. Adding Row
# new_row <- c(10, 11, 12)
# A <- rbind(number[1, ], new_row, number[-1, ])

# 2. Adding Column
# new_column <- c(10, 11, 12)
# number <- cbind(number, new_column)

# 4.8 Deleting Rows and Columns
# 1. Rows
# A = A[-2, ]

# 2. Columns
# A = A[, -2]


# 5. Arrays
# n-dimensional
# homogeneous

# 5.1  Creating
# Syntax: array(data, dim = (nrow, ncol, nmat), dimnames=names)

# 1 Uni-Dimensional Array
# vec1 <- c(1, 2, 3, 4, 5, 6, 7, 8, 9)
# print (vec1)
# cat ("Length of vector : ", length(vec1))

# 2. Multi-Dimensional Array
# arr = array(2:13, dim = c(2, 3, 2))
# print(arr)

# 5.2  Dimension of the Array
# arr = array(2:13, dim = c(2, 3, 2))
# dim(arr)

# 5.3  Naming of Arrays
# row_names <- c("row1", "row2")
# col_names <- c("col1", "col2", "col3")
# mat_names <- c("Arr1", "Arr2")

# arr = array(2:14, dim = c(2, 3, 2),
#             dimnames = list(row_names,
#                             col_names, mat_names))
# print (arr)

# 5.4 Accessing arrays
# array[3]
# array[1, 2]

# 5.5 Adding elements
# x <- c(1, 2, 3, 4, 5)
# x <- c(x, 6)

# x <- append(x, 7)

# len <- length(x)
# x[len + 1] <- 8

# 5.5 Removing Elements
# m <- c(1, 2, 3, 4, 5, 6, 7, 8, 9)
# m <- m[m != 3]

# m <- m[m > 2 & m <= 8]

# remove <- c(4, 6, 8)

# 5.6 Updating Existing Elements
# m[1] <- 0
# m[7:9] <- -1
# m[c(2, 5)] <- c(-1, -2)


# 6. Factors
# categorize the data and store it as levels
# can store both strings and integers
# useful in data analysis for statistical modeling

# 6.1 Creating a Factor
# x <-c("female", "male", "male", "female")
# print(x)
# gender <-factor(x)
# print(gender)

# 6.2 Checking for a Factor
# gender <- factor(c("female", "male", "male", "female"));
# print(is.factor(gender))

# 6.3 Accessing elements of a Factor
# gender <- factor(c("female", "male", "male", "female"))
# print(gender[3])

# 6.4. Modification of a Factor
# gender <- factor(c("female", "male", "male", "female"  ))
# gender[2]<-"female"
# print(gender)

# 6.5 Removing Elements from a factor
# gender <- factor(c("female", "male", "male", "female"  ))
# print(gender[-3])

# 6.6 Factors in Data Frame
# age <- c(40, 49, 48, 40, 67, 52, 53)
# salary <- c(103200, 106200, 150200,
#             10606, 10390, 14070, 10220)
# gender <- c("male", "male", "female",
#             "female", "male", "female", "male")
# employee <- data.frame(age, salary, gender = factor(gender))
# print(employee)



# 7. Strings
# one-dimensional array of characters

# 7.1 Creation of String
# str1 <- "OK1"
# cat ("String 1 is : ", str1)

# 7.2 Length of String
# library(stringr)
# str_length("hello")

# nchar("hel'lo")

# 7.3 Accessing portions of a string
# substr("Learn Code Tech", 1, 2)

# substring("Learn Code Tech", 2, 3)

# 7.4 Case Conversion
# str <- "Hi LeArn CodiNG"
# print(toupper(str))
# print(tolower(str))
# print(casefold(str, upper = TRUE))

# 7.5 Concatenation of Strings
# string1 <- "Hello"
# string2 <- "World"
# result <- paste(string1, string2)
# print(result)

# 7.6 String formatting
# x <- 42
# y <- 3.14159
# result <- sprintf("The answer is %d, and pi is %.2f.", x, y)
# print(result)

# 7.7 Updating the Strings
# string <- "Hello, World!"
# string <- gsub("World", "Universe", string)
# print(string)


# 8. Tibbles
# enhanced version of data frames
# offer improved printing, stricter column types, consistent subsetting behavior
# provide a modern, user-friendly approach to tabular data

# library(tibble)
# my_data <- tibble(
#   name = c("Sandeep", "Amit", "Aman"),
#   age = c(25, 30, 35),
#   city = c("Pune", "Jaipur", "Delhi")
# )
# print(my_data)
