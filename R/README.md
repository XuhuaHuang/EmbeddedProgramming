# Statistical Programming

## Setup: Installing `R` and Tools

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

## `R` Sessions
`setwd` and `getwd`

Use `?Syntax` to find operator syntax

If unsure of operator precedence, use parentheses.

## `R` Objects

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

## `R` Data Objects

- Vectors
    - **Simplest** data object starting at index `1`
    - **Ordered** set of values (numeric or character)
    - `scan`, `c`, `rep`, `:`, `seq`
    - `length`, `mode`, `class`, `names`
    - conversion operations: `as.integer`, `as.double`
    - verification operations: `is.integer`, `is.double`, `is.character`
    - statistics: `max`, `min`, `mean`, `var`, `sd`
    - mathematics: `sum`, `rank`, `order`, `round`, `floor`, `ceiling`, `abs`, `sqrt`, `exp`, `sin`, `sign`, `log`, `prod`

- Matrices
    - **Two-dimensional** data object
    - `matrix`, `rbind`, `cbind`
    - `length`, `dim`, `dimnames`, `nrow`, `ncol`
    - indexing: `A[i, j]`, `x[1, 2:3]`, `x[1:2, 3]`, `x[1,]`, `x[, 2]`
    - arithmetic: `+`, `-`, `*`, `/`
    - matrix algebra: `%*%`, `t`, `solve`

- `data.frame`
    - **Tabular** data object (all objects have the same length)
    - `data.frame`, `read.table`, `read.csv`, `as.data.frame`, `cbind`, `rbind`, `merge`
    - `nrow`, `ncol`, `names`, `str`
    - `is.data.frame`, `is.matrix`
    - `length`, `mode`, `class`, `names`, `attributes`, `row.names`
    - indexing: `df[i, j]`, `df$colname`, `df[["colname"]]`

- Arrays
    - **Multi-dimensional** homogeneous data object (all objects have the same type)
    - `list`
    - `array`, `as.array`
    - `dim`, `dimnames`
    - indexing: `A[i, j, k]`

- Lists
    - **Heterogeneous** data object (different types of objects)
    - `list`, `as.list`
    - `length`, `mode`, `class`, `attributes`
    - `names`, `str`
    - indexing: `L[[i]]`, `L$name`

## Recycling Rule

When performing operations on vectors of different lengths, `R` recycles the shorter vector until it matches the length of the longer vector. If the length of the longer vector is not a multiple of the shorter vector, `R` will issue a warning.

```r
x <- c(1, 2, 3)
y <- c(10, 20)
z <- x + y  # z will be c(11, 22, 13)
```

## Matrix Algebra

- `+`, `-`, `*`, `/`: element-wise operations
- `^`: element-wise exponentiation
- module division: `%%`, `%/%`
- `%*%`: matrix multiplication, `crossprod`
- outer product: `outer`
- `t`: transpose
- `solve`: inverse of a matrix, or solution of linear equations

### Indexing and Subsetting

- `data[['name']] = NULL` to remove a column from a `data.frame`
- `data$colname` to access a column in a `data.frame`

### Logical indexing

```r
x <- c(1, 2, 3, 4, 5)
x[x > 3]  # returns c(4, 5)
x[c(T, F, T)]
```

### Missing values

- `NA` represents missing values
- `is.na(x)` to check for missing values
- `x[!is.na(x)]` to remove missing values
- `na.omit(x)` to remove missing values from a vector or data frame
- `x[is.na(x)] <- 0` to replace missing values with a specific value (e.g., `0`)

### Find Index(es) of a Specific Value within a Vector

```r
x <- c(1, 2, 3, 4, 5)
which(x == 3)  # returns 3
match(3, x)  # returns 3
which(x %in% vals)
which(x > 3)  # returns c(4, 5)
```

## Reading and Writing Datasets

- `read.table`, `read.csv` to read data from files
- `write.table`, `write.csv` to write data to files
- `source` and `dump` to read and write `R` objects
- `save` and `load` to save and load `R` objects in binary format
- `sink("output.txt")` and `sink()` to redirect output to a file and stop redirecting output

## `R` Functions

Vectorized logical operations and logical indexes are extremely useful to compare, find, replace data elements.

Write functions in `R` to turn repeated, complex, or parameterized logic into reusable, modular, and reliable building blocks. Eliminate repetition, abstraction, modularity, reproducibility, encapsulation, vectorized design, code clarity and readability.

Big computation job can be broken into many small jobs which can be executed by a sequences of R functions either in sequential or in parallel.

Before any real computation, should use some procedures to check inputs: checking data type, data coercing, logical testing, etc.

- Domain: arguments lists
- Function body: expressions that define the function
- Range: return values

If the end of the function body is not an explicit `return` statement, the value of the last evaluated expression is returned.

### Variable Number of Arguments

- `...` in a function argument list is used to specify that an arbitrary number of arguments are to be passed to a function within the body of the function.
- `list(...)` to capture the variable arguments as a list

### Required and Optional Arguments

- Required arguments are those arguments for which the function definition provides neither a default value nor instructions on what to do if the argument is missing. All other arguments are optional.

### Testing Argument Lists

- `is.type(x)` to check if an argument is of a specific type, `is.vector`, `is.matrix`, `is.data.frame`, `is.integer`, `is.double`, `is.character`
- `as.type(x)` to convert an argument to a specific type, `as.vector`, `as.matrix`, `as.data.frame`, `as.integer`, `as.double`, `as.character`

### Logical Operators

- `&` vectorized AND
- `|` vectorized OR
- `&&` control flow AND
- `||` control flow OR

### Error Handling

- `stop("error message")` to throw an error and stop execution
- `warning("warning message")` to throw a warning and continue execution
- `try(expr)` to execute an expression and catch any errors without stopping execution
- `tryCatch(expr, error = function(e) { ... })` to execute an expression and handle errors with a custom function
