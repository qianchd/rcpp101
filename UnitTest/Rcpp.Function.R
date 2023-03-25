# The tips behind Rcpp::Function ----
## The time for passing arma::mat and NumericMatrix ----
n=10000
A=matrix(rnorm(n^2),n,n)
x <- function(A) A[5,5]
system.time({matrixCall(A,x)})
system.time({matrixCall2(A,x)})
system.time({matrixCall3(A,x)})
system.time({matrixCall4(A,x)})

# Conclusion: it is better to pass NumericMatrix than arma::mat when Rcpp::Function is called in C++ function body.

## The scope of Rcpp::Function ----
# When we need to apply some complex R-functions like regression, machine learning to some data, and the R-function need to be called in C++ function body.
# Is there a way that the data does not need to be passed?
# Yes!
n=10000
A=matrix(rnorm(n^2),n,n)
y <- function(A,i,j) A[i,j]
x <- function(i,j) y(A=A,i,j)
system.time({accessRmatrix(5,5,x)})
x <- function(i,j) A[i,j]
system.time({accessRmatrix(5,5,x)})
# Conclusion: When use Rcpp::Function, it is possible to pass a minimum set of arguments.

