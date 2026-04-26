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

## Wichmann-Hill Pseudo-Random Number Generator

```r
wh = function(seed, start = 0, end = 1) {
    seed[1] = (171 * seed[1]) %% 30269
    seed[2] = (172 * seed[2]) %% 30307
    seed[3] = (170 * seed[3]) %% 30323
    x = (seed[1]/30269 + seed[2]/30307 + seed[3]/30323) %% 1
    start + (end - start) * x
}
whv = function(seed, start = 0, end = 1) {
    y = c(171, 172, 170)
    z = c(30269, 30307, 30323)
    seed = (y * seed) %% z
    x = sum(seed / z) %% 1
    start + (end - start) * x
}
```

## Programming Style

- Use meaningful variable and function names
- Modularize code into functions
- Document code with comments and function documentation
- Use consistent indentation and spacing
- Use existing functions and libraries when possible
- Use parentheses to make grouping and operator precedence clear
- Avoid unnecessary loops and use vectorized operations when possible
- Avoid using recursive functions when iterative solutions are more efficient

## IQR

```r
IQR(x, na.rm = FALSE)
q <- quantile(x, probs = c(0.25, 0.75))
iqr <- q[2] - q[1]
iqr
```

## Monte Carlo Demonstration of `CLT` in `R`

```r
set.seed(42)

# Population: Exponential distribution (skewed)
n <- 30              # sample size
num_sim <- 10000     # number of Monte Carlo repetitions

# True parameters
mu <- 1              # mean of Exp(1)
sigma <- 1           # std dev of Exp(1)

z_values <- replicate(num_sim, {
  x <- rexp(n, rate = 1)         # draw sample
  x_bar <- mean(x)               # sample mean
  sqrt(n) * (x_bar - mu)         # standardized value
})

hist(z_values, probability = TRUE, breaks = 50,
     main = "CLT Demonstration (Monte Carlo)",
     xlab = expression(sqrt(n) * (bar(X) - mu)))

# Overlay theoretical normal curve
curve(dnorm(x, mean = 0, sd = sigma), 
      col = "red", lwd = 2, add = TRUE)
```

## Alpha-trimmed Mean

```r
alpha_trimmed_mean_safe <- function(x, alpha) {
  if (!is.numeric(x)) {
    stop("x must be numeric")
  }

  if (alpha < 0 || alpha >= 0.5) {
    stop("alpha must be in [0, 0.5)")
  }

  n <- length(x)
  k <- floor(alpha * n)

  x_sorted <- sort(x)

  if (2 * k >= n) {
    stop("Trimming removes all data")
  }

  mean(x_sorted[(k + 1):(n - k)])
}
```

## Sample Correlation

```r
sample_correlation <- function(x, y) {
  if (length(x) != length(y)) {
    stop("Vectors must have the same length")
  }

  x_bar <- mean(x)
  y_bar <- mean(y)

  numerator <- sum((x - x_bar) * (y - y_bar))
  denominator <- sqrt(sum((x - x_bar)^2)) * sqrt(sum((y - y_bar)^2))

  numerator / denominator
}

sample_correlation_stable <- function(x, y) {
  if (length(x) != length(y)) {
    stop("Vectors must have the same length")
  }

  n <- length(x)

  cov_xy <- sum(x * y) / n - mean(x) * mean(y)
  sd_x <- sqrt(sum(x^2) / n - mean(x)^2)
  sd_y <- sqrt(sum(y^2) / n - mean(y)^2)

  cov_xy / (sd_x * sd_y)
}
```

## Debugging and Maintenance

- Error messages generated by `R` functions can be helpful for debugging.
- Use `browser()` function to set breakpoints.
- Use `print()` or `cat()` to display intermediate values for debugging.
- Do not use `print()` in return statements of functions, just use `return(return_object)`.

## QQ Plot and Normality Test

### Quantile

A quantile is a value that divides a dataset into intervals containing equal proportions of the data.

Sort the given data from smallest to largest, a quantile tells you the value below which a certain percentage of the data falls. For example, the 25th percentile (or first quartile) is the value below which 25% of the data falls.

For a dataset of size `n`, the `p`-th quantile is roughly the value at the position `p * (n - 1) + 1` in the sorted data. If this position is not an integer, you can interpolate between the two nearest values.

If the data is normally distributed, the points in a QQ plot will approximately lie on a straight line. Deviations from this line indicate departures from normality.

### QQ Plot

A QQ plot (quantile-quantile plot) is a graphical tool to assess if a dataset follows a particular distribution, such as the normal distribution (most commonly seen). It plots the quantiles of the dataset against the quantiles of the theoretical distribution.

A Q–Q plot is straight because quantiles transform linearly under affine transformations, and the plot is literally visualizing that relationship.

```r
x <- rnorm(100)
y <- rnorm(100, mean = 2)

qqplot(x, y)
abline(0, 1, col = "blue")
```

### `R` Graphics

- `plot`, `hist`, `boxplot`, `qqplot`, `pairs`
- `xlab`, `ylab`, `sub`, `main`, `xlim`, `ylim`

Symbol Options:

- `lty` line type: `1` solid, `2` dashed, `3` dotted, `4` dotdash, `5` longdash, `6` twodash
- `lwd` line width: `1` default, `2` double, etc
- `mkh` marker height (in): `mkh = 0.5`
- `pch` marker type: `pch = "*"` for star, `pch = 16` for filled circle, `pch = 17` for filled triangle, etc
- `col` colour type: `col = "blue"`
- `cex` character expansion: `cex = 1.5` to increase size by 50%
- `type` plot type: `type = "p"` for points, `type = "l"` for lines, `type = "b"` for both, etc

Plot Layout:

- Multiple figures on one plot: `par(mfrow = c(2, 2))` for 2 rows and 2 columns
- Split screen: `split.screen(figs=c(2, 1))` for 2 rows and 1 column
- `close.screen(all=T))` to close all split screens

## Graphics with Expressions

```r
x <- seq(-1, 1, length.out = 100)
y <- sqrt(1 - x^2)

plot(x, y,
     type = "l",
     main = expression(y == sqrt(1 - x^2)),
     xlab = "x",
     ylab = "y")
```

```r
x <- seq(-1, 1, length.out = 100)

y1 <- sqrt(1 - x^2)
alpha <- 0.5
beta <- 1
y2 <- alpha + beta * x

plot(x, y1,
     type = "l",
     col = "blue",
     ylim = range(c(y1, y2)),
     main = "Two Functions",
     xlab = "x",
     ylab = "y")

lines(x, y2, col = "red")

legend("topright",
       legend = c(
         expression(y == sqrt(1 - x^2)),
         expression(y == alpha + beta * x)
       ),
       col = c("blue", "red"),
       lty = 1)
```

## Express a Statistical Model with `R`

- Use factor or ordered to represent categorical variables
- Use `lm` for linear regression, `glm` for generalized linear models
- `~` operator means "is modeled by": `Gas ~ Temp`
- `+` operator means "add another term": `Gas ~ Temp + Insul`
- `:` operator means "have an interactive term": `Gas ~ Temp + Insul + Temp:Insul`
- `*` operator means "have both main and interactive terms": `Gas ~ Temp * Insul` is equivalent to `Gas ~ Temp + Insul + Temp:Insul`
- `-l` means "remove or exclude term": `Gas ~ Temp + Insul -l`
- `^` operator means "limit depth of interaction": `Gas ~ (Temp + Insul)^2` is equivalent to `Gas ~ Temp + Insul + Temp:Insul`
- `%in%` operator means "nesting": `effect ~ teacher + school + teacher %in% school` means that the effect is modeled by teacher and school, but teachers are nested within schools
- `/` operator means "main effect and nesting": `effect ~ school + teacher/school` is equivalent to `effect ~ teacher + school + teacher %in% school`

## Common Arguments to Modeling Functions

- `data` to specify the data frame containing the variables
- L.H.S of `~`: dependent variable (response variable)
- R.H.S of `~`: independent variables (predictor variables)
- `.`: include all other variables in the `data.frame` as predictors 
    - `lm(Gas ~ ., data = whiteside)`
    - `lm(Gas ~ . ^2, data = whiteside)`
- Subset argument `subset = Gas > 2 & Gas < 5`
- Weights argument `weights = 1 / (Temp^2)` to give more weight to observations with smaller `Temp` values
- `na.action` to specify how to handle missing values, e.g., `na.omit` to exclude rows with missing values
    - `na.fail` to throw an error if there are missing values
    - `na.exclude` to exclude missing values from the analysis but keep them in the residuals and fitted values
    - `na.include` to include missing values in the analysis, treating them as a separate category

## Random Number Generation (RNG)

- `set.seed` to set the seed for reproducibility
- A key element of a Monte Carlo simulation requires a good quality of RNG
- More specifically, one needs a good uniform or normal RNG
- Almost all other distributions can be implemented by using uniform RNG as a source
- How to generate a random number without a computer (pre-computer age)?
    - Lottery 649
    - A book with pre-printed "random numbers"
    - Drawbacks: slow, limited quantity, not reproducible
- "True" RNG
    - Quantum mechanics: quantum unpredictability leads to true RNG
    - Physical phenomena without quantum mechanics
    - Thermal noise from resistors; later 1999 Intel CPUs contain such circuit
    - Atmospheric noise detected by radio receiver

### Mersenne-Twister RNG (R’s default RNG)

- Pseudorandom number generator developed in 1997 by Matsumoto and Nishimura
- Period: `2^19937 − 1`
- Pseudo-RNG is good as long as it has an extremely long period (cycle)
- Seed: a 624-dimensional set of 32-bit integers plus a current position in that set
- The Mersenne Twister is designed with Monte Carlo simulations and other statistical simulations in mind
- For non-parallel RNG, this is probably the best RNG
- http://en.wikipedia.org/wiki/Mersenne_twister

### Quality of RNG

Since a RNG normally uses a deterministic algorithm, its randomness property is important.

- Kolmogorov-Smirnov test: Goodness-of-fit test; test uniform distribution
    - `R` function `ks.test`
    - Try: `x = seq(0, 1, length = 10000)`
- The longest runs of head

### Generating Non-uniform Distributions

- Use `R` built-in RNG functions such as `rpois`, `rexp`, `rgama`, `rbinom` etc.
- How to generate nonstandard distributions?
- Inversion method
    - Let `F(x)` be the C.D.F of a random variable `X`. Its inverse function (quantile function) is defined `Q(t) = F^{-1}(t) = inf{x: F(x) >= t}`
    - In principle if `Q(t)` has a closed form, inversion method is the best way to generate required random numbers
    - Distributions: `Exp`, `Cauchy`, `Geometric`, `Pareto`, `Logistic`, `Extreme Value`, `Weibull` etc.
    - Normal distribution has no closed form for `Q(t)`
    - There are other ways to generate normal sample exactly
    - `Box-Muller` normal RNG uses 2 independent uniform `[0, 1]` to generate 2 independent normal; computation is costly (sin, cos, log, sqrt)
    - Rejection method
    - `R` and `Matlab` use highly refined numerical approximation of `Q(t)`
- Random variables are functions of random variables
    - `Z` is normal, then `exp(Z)` is log-normal
- Rejection method
    - density of interest: `f(x), a <= x <= b`
    - A known function: `M(x) >= f(x), a <= x <= b`
    - algorithm: let `m(x) = M(x) / (integral of M over [a, b])`
    - step 1: Generate `T` with the density function `m(x)`
    - step 2: Generate `U` of `unif[0, 1]`. If `M(T) * U <= f(T)` then `X = T` else go to step 1

```r
rejection_sample <- function(n, f, M, r_m) {
  samples <- numeric(n)
  count <- 0
  
  while (count < n) {
    # Step 1: sample T ~ m(x)
    T <- r_m(1)
    
    # Step 2: sample U ~ Uniform(0,1)
    U <- runif(1)
    
    # Accept or reject
    if (M(T) * U <= f(T)) {
      count <- count + 1
      samples[count] <- T
    }
  }
  
  return(samples)
}
```

```r
rejection_sample_vec <- function(n, f, M, r_m, batch_size = 10000) {
  samples <- numeric(0)
  
  while (length(samples) < n) {
    # Step 1: generate a batch of proposals
    T <- r_m(batch_size)
    
    # Step 2: generate uniforms
    U <- runif(batch_size)
    
    # Step 3: vectorized acceptance test
    accept <- (M(T) * U) <= f(T)
    
    # Keep accepted samples
    samples <- c(samples, T[accept])
  }
  
  # Trim to exactly n samples
  samples[1:n]
}
```

