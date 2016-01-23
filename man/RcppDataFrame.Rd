\name{RcppDataFrame}
\alias{RcppDataFrame}
\title{Rcpp::DataFrame example for Rcpp}
\description{
  A \code{DataFrame} can be passed C++ and can be instantiated as a
  corresponding C++ object using the Rcpp API. 

  This example shows (in the corresponding C++ code) how to access,
  modify and create a data frame.
}
\details{
  Usage of \code{Rcpp::DataFrame} is fully defined in
  the respective header file.

  The C++ source file corresponding to the this function does the
  following:

  \preformatted{%
      // we receive a 'DF' data.frame object
      // and access each column by name
      Rcpp::IntegerVector a = DF["a"];
      Rcpp::CharacterVector b = DF["b"];
      Rcpp::DateVector c = DF["c"];
      
      // do something
      a[2] = 42;
      b[1] = "foo";
      c[0] = c[0] + 7;                      // move up a week

      // create a new data frame
      Rcpp::DataFrame NDF = 
	  Rcpp::DataFrame::create(Rcpp::Named("a")=a,
				  Rcpp::Named("b")=b,
				  Rcpp::Named("c")=c);

      // and return old and new in list
      return(Rcpp::List::create(Rcpp::Named("origDataFrame")=DF,
				Rcpp::Named("newDataFrame")=NDF));
  }
}
\author{Dirk Eddelbuettel and Romain Francois}
\examples{
  \dontrun{
  RcppDataFrame()
  }
}
\keyword{programming}
\keyword{interface}
