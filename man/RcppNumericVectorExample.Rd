\name{RcppNumericVectorExample}
\alias{RcppNumericVectorExample}
\title{Rcpp NumericVector example}
\description{
  Example on how to use a NumericVector and manipulate it with the STL. 
}
\details{
  \preformatted{%
    NumericVector orig ;                 // from R
    NumericVector vec(orig.size());	 // create a target vector of the same size
    
    // we could query size via
    //   int n = vec.size();
    // and loop over the vector, but using the STL is so much nicer
    // so we use a STL transform() algorithm on each element
    std::transform(orig.begin(), orig.end(), vec.begin(), sqrt_double );

    return List::create(Named("result") = vec, 
                        Named("original") = orig);
  }

  As shown in the example section, provided the seed is reset, the exact
  same draws can be obtained in R itself -- which is important for reproducibility.
}
\author{Dirk Eddelbuettel and Romain Francois}
\examples{
    RcppNumericVectorExample(seq(1,9)^2)
}
\keyword{programming}
\keyword{interface}
