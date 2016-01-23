\name{RcppRNGsExample}
\alias{RcppRNGsExample}
\title{Rcpp RNGs example}
\description{
  Rcpp sugar provides numerous p/q/d/r functions for numerous distributions.

  This example shows (in the corresponding C++ code) how to draw from
  three different distributions and returns a data frame.
}
\details{
  The various header file, and the Rcpp sugar vignette, provide full
  documentation for Rcpp sugar.

  The C++ source file corresponding to the this function does the
  following:

  \preformatted{%
        int n;  	// length passed in from R
    
        NumericVector rn = rnorm(n);
        NumericVector rt = rt(n, 1.0);
        NumericVector rp = rpois(n, 1.0);

        // create a new data frame to return drawns
       return DataFrame::create(Named("rnorm") = xn,
                                Named("rt")    = xt,
                                Named("rpois") = xp);
  }

  As shown in the example section, provided the seed is reset, the exact
  same draws can be obtained in R itself -- which is important for reproducibility.
}
\author{Dirk Eddelbuettel and Romain Francois}
\examples{
  set.seed(42)
  X <- RcppRNGsExample(10L)
  set.seed(42)
  Y <- data.frame(rnorm=rnorm(10),rt=rt(10,1),rpois=rpois(10,1))
  all.equal(X,Y)
}
\keyword{programming}
\keyword{interface}
