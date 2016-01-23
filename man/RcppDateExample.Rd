\name{RcppDateExample}
\alias{RcppDateExample}
\title{C++ classes for interfacing date and datetime R objects}
\description{
    Rcpp has the classes \code{Rcpp::Date}, \code{Rcpp::Datetime}, 
    \code{Rcpp::DateVector} and \code{Rcpp::DatetimeVector}.
}
\details{

    In the \code{C++} code for the \code{RcppDateExample.cpp} file: 
    
    \preformatted{%
        // [[Rcpp::export]]
        List DateExample(DateVector & dv, DatetimeVector & dtv) {
            Function formatDate("format.Date");
            Function formatDatetime("format.POSIXct");
            
            Rprintf("\nIn C++, seeing the following date value\n");
            for (int i=0; i<dv.size(); i++) {
                Rcout << as<std::string>(formatDate(wrap(dv[i]))) << std::endl;
                dv[i] = dv[i] + 7;		// shift a week
            }
            Rprintf("\nIn C++, seeing the following datetime value\n");
            for (int i=0; i<dtv.size(); i++) {
                Rcout << as<std::string>(formatDatetime(wrap(dtv[i]))) << std::endl;
                dtv[i] = dtv[i] + 0.250;    // shift 250 millisec
            }
            
           // Build result set to be returned as a list to R.
           return List::create(Named("date",   dv),
                               Named("datetime", dtv));
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

# set up date and datetime vectors
dvec <- Sys.Date() + -2:2
dtvec <- Sys.time() + (-2:2)*0.5

# call the underlying  C++ function
result <- RcppDateExample(dvec, dtvec)

# inspect returned object
result
}
\keyword{programming}
\keyword{interface}

