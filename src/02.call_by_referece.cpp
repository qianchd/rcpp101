// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

// [[Rcpp::export]]
Rcpp::List mod_mat(arma::mat & A, int & i, int & j, double & x) {
  Rcpp::List out;
  A(i-1, j-1) = x;
  out["A"] = A;
  out["x"] = x;
  return out;
}

// [[Rcpp::export]]
arma::mat return_mat(arma::mat & A) {
  return A;
}

// [[Rcpp::export]]
Rcpp::List mod_mat_v(arma::mat A, int & i, int & j, double & x) {
  Rcpp::List out;
  A(i-1, j-1) = x;
  out["A"] = A;
  out["x"] = x;
  return out;
}

// [[Rcpp::export]]
arma::mat return_mat_v(arma::mat A) {
  return A;
}

/*** R
A <- matrix(NA, 10, 10)
print(A[1, 1])

res <- mod_mat(A, 1, 1, 2)
print(A[1, 1])

A <- return_mat(A)
res <- mod_mat(A, 1, 1, 2)
print(A[1, 1])

A <- matrix(NA, 10, 10)
A[2, 2] <- 1
print(A[1, 1])

res <- mod_mat(A, 1, 1, 2)
print(A[1, 1])

A <- return_mat(A)
res <- mod_mat(A, 1, 1, 2)
print(A[1, 1])



A <- matrix(NA, 10, 10)
print(A[1, 1])

res <- mod_mat_v(A, 1, 1, 2)
print(A[1, 1])

A <- return_mat_v(A)
res <- mod_mat_v(A, 1, 1, 2)
print(A[1, 1])
*/
