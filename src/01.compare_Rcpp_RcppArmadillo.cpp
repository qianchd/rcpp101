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

// [[Rcpp::export]]
void Modmatrix(NumericMatrix A, unsigned int i, unsigned int j, double s) {
  A(i, j) = s;
  return;
}

// [[Rcpp::export]]
void equalTest(arma::uword i, double s) {
  if(i == s) Rcpp::Rcout << "equal!" << std::endl;
  else Rcpp::Rcout << "not equal!" << std::endl;
}

// [[Rcpp::export]]
bool is_na_arma(arma::mat A, int i, int j) {
  return(std::isnan(A(i, j)));
}

// [[Rcpp::export]]
arma::mat sub_mat(arma::mat A, int i1, int i2, int j1, int j2) {
  return(A.submat(i1,j1,i2,j2));
}
