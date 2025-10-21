# barplot(airquality$Ozone,
#         main = 'Ozone Concenteration in air',
#         xlab = 'ozone levels', horiz = TRUE)

# barplot(airquality$Ozone, 
#         main = 'Ozone Concenteration in air', 
#         xlab = 'ozone levels', col ='blue', horiz = FALSE)

# data(airquality)

# hist(airquality$Temp, main ="La Guardia Airport's Maximum Temperature(Daily)",
#     xlab ="Temperature(Fahrenheit)",
#     xlim = c(50, 125), col ="yellow",
#     freq = TRUE)

# data(airquality)

# boxplot(airquality$Wind, main = "Average wind speed at La Guardia Airport",
#         xlab = "Miles per hour", ylab = "Wind",
#         col = "orange", border = "brown",
#         horizontal = TRUE, notch = TRUE)

# boxplot(airquality[, 0:4], 
#         main ='Box Plots for Air Quality Parameters')

# data(airquality)

# plot(airquality$Ozone, airquality$Month,
#      main ="Scatterplot Example",
#      xlab ="Ozone Concentration in parts per billion",
#      ylab =" Month of observation ", pch = 19)

# data <- matrix(rnorm(25, 0, 5), nrow = 5, ncol = 5)

# colnames(data) <- paste0("col", 1:5)
# rownames(data) <- paste0("row", 1:5)

# heatmap(data)

# # install.packages("maps")
# library(maps)
# map(database = "world")

# df <- data.frame(
#   city = c("New York", "Los Angeles", "Chicago", "Houston", "Phoenix"),
#   lat = c(40.7128, 34.0522, 41.8781, 29.7604, 33.4484),
#   lng = c(-74.0060, -118.2437, -87.6298, -95.3698, -112.0740)
# )

# points(x = df$lng, y = df$lat, col = "Red")

# cone <- function(x, y){
# sqrt(x ^ 2 + y ^ 2)
# }
  
# x <- y <- seq(-1, 1, length = 30)
# z <- outer(x, y, cone)
  
# persp(x, y, z,
#       main="Perspective Plot of a Cone",
#       zlab = "Height",
#       theta = 30, phi = 15,
#       col = "orange", shade = 0.4
#       )

barplot(airquality$Ozone, 
        main = 'Ozone Concentration Level',
        xlab = 'Ozone levels',
        col = '#79ffd9',
        horiz = FALSE)

data(airquality)
airquality$MonthFactor <- factor(airquality$Month, 
                                 levels = 5:9, 
                                 labels = c("May", "Jun", "July", "August", "September"))