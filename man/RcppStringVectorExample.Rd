\name{RcppStringVectorExample}
\alias{RcppStringVectorExample}
\title{Example of using Rcpp StringVector (aka CharacterVector) }
\description{
    The \code{StringVector} (aka \code{CharacterVector}
    class represents character vectors. 
}
\details{

    The \code{C++} code presented in the \code{StringVectorExample.cpp} file: 
    
    \preformatted{%
        #include <Rcpp.h>
        using namespace Rcpp ;
        
        // [[Rcpp::export]]
        List StringVectorExample(StringVector orig) {
            StringVector vec(orig.size());	
        
            std::transform(orig.begin(), orig.end(), vec.begin(), 
        		   make_string_transformer(tolower));
        
            List result = List::create(
                Named( "result" )   = vec,
                Named( "original" ) = orig
            );
            return result ;
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

RcppStringVectorExample( c("Tick", "Tack", "Tock") )

}
\keyword{programming}
\keyword{interface}
