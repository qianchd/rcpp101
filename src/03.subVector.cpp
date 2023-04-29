#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double get_i(Rcpp::NumericVector x, int i) {
  return (x(i));
}

// [[Rcpp::export]]
Rcpp::NumericVector get_subvec(Rcpp::NumericVector x, int i, int j) {
  Rcpp::Rcout << Rcpp::mean(x[Rcpp::seq(i, j)]) << std::endl;
  return x[Rcpp::seq(i, j)];
}

/*** R
x <- rnorm(10)
print(x)
get_subvec(x, 2, 5)
*/
