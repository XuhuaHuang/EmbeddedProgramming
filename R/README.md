# Statistical Programming

## Setup: Installing R and Tools

```r
install.packages("ggplot2")
```

## Statistical Computing
- Statistics → modeling, inference, probability
- Computer Science → algorithms, efficiency
- Data → storage, processing, transformation
- Programming → automation and reproducibility
- Graphics → visualization and communication
- Simulation → e.g., Monte Carlo methods

Statistical computing is the use of computational methods to perform statistical analysis, simulation, and data visualization.

## Main Components of Statistical Computing

1. Data Manipulation
```r
subset(cars, speed > 10)
```
2. Programming
```r
square <- function(x) {
  x^2
}
```
3. Graphics
```r
plot(cars)
```

## Object-Oriented Nature of `R`
```r
class(cars)
summary(cars)
plot(cars)

```
- Regression Example
```r
out <- lm(dist ~ speed, data = cars)
class(out)
summary(out)
plot(out)
```

## Command Line Options and Helps
- `-save` or `-no-save`
- `-restore` or `-no-restore`

```r
help(search)
```

## Syntax and Grammar

A complete expression is any typed expression that falls into one of the following seven classes:

- Literals
- Calls
- Assignments
- Conditionals: comparison, logical
- Loops
- Control flow statements
- Grouping statements

## R Sessions
`setwd` and `getwd`

Use `?Syntax` to find operator syntax

If unsure of operator precedence, use parentheses.

## R Objects

All objects created in command line (`RStudio` calls it console) are saved
in `.GlobalEnv`.

`R` treats everything as an object
- data objects
- function objects
- list objects
- `NULL` objects
- `...` object
- language objects
- symbol objects
- expression objects

```r
ls()
objects()
ls.str()
find("lm")
help.search("lm")
rm(x)
rm(x, y, z)
rm(list = ls())
```

### Class, Type of Length of an Object
```r
class(cars)
typeof(cars)
length(cars)
attributes(cars)
names(cars)
dim(cars)
```
