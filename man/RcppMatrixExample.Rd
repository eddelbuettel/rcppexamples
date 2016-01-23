\name{RcppMatrixExample}
\alias{RcppMatrixExample}
\title{Example of using Rcpp NumericMatrix}
\description{
    The \code{NumericMatrix} class represents numeric matrices
}
\details{

    The \code{C++} code presented in the \code{MatrixExample.cpp} file: 
    
    \preformatted{%
        #include <Rcpp.h>
        #include <cmath>
        
        // suncc needs help to disambiguate between sqrt( float ) and sqrt(double) 
        inline static double sqrt_double(double x) { return ::sqrt(x); }
        
        using namespace Rcpp; 
        
        // [[Rcpp::export]]
        List MatrixExample(const NumericMatrix & orig) {
            NumericMatrix mat(orig.nrow(), orig.ncol());	
        
            // we could query size via
            //   int n = mat.nrow(), k=mat.ncol();
            // and loop over the elements, but using the STL is so much nicer
            // so we use a STL transform() algorithm on each element
            std::transform(orig.begin(), orig.end(), mat.begin(), sqrt_double );

            return List::create(Named("result") = mat, 
                                Named("original") = orig);
        }
    
    }
}
\references{
  \emph{Writing R Extensions}, available at \url{https://www.r-project.org}.
}
\author{Dominick Samperi wrote the initial versions of Rcpp (and
  RcppTemplate) during 2005 and 2006.  Dirk Eddelbuettel made some
  additions, and became maintainer in 2008. Dirk Eddelbuettel and Romain
  Francois have been extending Rcpp since 2009.
}
\examples{

M <- matrix((1:16)^2, 4)
RcppMatrixExample(M)

}
\keyword{programming}
\keyword{interface}

