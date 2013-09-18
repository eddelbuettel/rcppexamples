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
  following (inside of a \code{try/catch} block):

  \preformatted{%
        Rcpp::RNGScope scope;         		// needed when RNGs are drawn

        int n = Rcpp::as<int>(ns); 		// length vector 
        Rcpp::NumericVector rn = Rcpp::rnorm(n);
        Rcpp::NumericVector rt = Rcpp::rt(n, 1.0);
        Rcpp::NumericVector rp = Rcpp::rpois(n, 1.0);

        // create a new data frame to return drawns
        Rcpp::DataFrame NDF = 
            Rcpp::DataFrame::create(Rcpp::Named("rnorm") =rn,
                                    Rcpp::Named("rt")    =rt,
                                    Rcpp::Named("rpois") =rp);

        // and return old and new in list
        return(NDF);
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
