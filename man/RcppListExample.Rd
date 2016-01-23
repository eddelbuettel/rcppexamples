\name{RcppListExample}
\alias{RcppListExample}
\title{Examples of uses of List}
\description{
    \code{List} is an \code{Rcpp} class that can be used to manipulate R lists.  
}
\arguments{
  \item{params}{A heterogeneous list specifying \code{method} (string),
    \code{tolerance} (double), \code{maxIter} (int) and \code{startDate}
  (Date in R, RcppDate in C++).}
}
\value{
  \code{RcppListExample} returns a list containing:
  \item{method}{string input paramter}
  \item{tolerance}{double input paramter}
  \item{maxIter}{int input parameter}
  \item{startDate}{Date type with starting date}
  \item{params}{input parameter list (this is redundant because we
    returned the input parameters above)}
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

# set up some value
params <- list(method='BFGS',
               tolerance=1.0e-5,
               maxIter=100,
               startDate=as.Date('2006-7-15'))

# call the underlying  C++ function
result <- RcppListExample(params)

# inspect returned object
result

}
\keyword{programming}
\keyword{interface}
