// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

using namespace Rcpp;


// [[Rcpp::export]]
void matrixCall(arma::mat A, Function x) {
  x(A);
  return;
}

// [[Rcpp::export]]
void matrixCall2(arma::mat & A, Function x) {
  x(A);
  return;
}

// [[Rcpp::export]]
void matrixCall3(NumericMatrix A, Function x) {
  x(A);
  return;
}

// [[Rcpp::export]]
void matrixCall4(NumericMatrix& A, Function x) {
  x(A);
  return;
}

// [[Rcpp::export]]
void accessRmatrix(arma::uword i, arma::uword j, Function x) {
  Rcpp::Rcout << *REAL(x(i,j)) << std::endl;
  return;
}
