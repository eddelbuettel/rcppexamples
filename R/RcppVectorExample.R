
## RcppVectorExample.R: Rcpp R/C++ interface class library RcppVector example
##
## Copyright (C) 2008        Dirk Eddelbuettel
## Copyright (C) 2009 - 2010 Dirk Eddelbuettel and Romain Francois
##
## This file is part of Rcpp.
##
## Rcpp is free software: you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 2 of the License, or
## (at your option) any later version.
##
## Rcpp is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

RcppVectorExample <- function(v) {

    ## Check that params is properly set.
    if (missing(v)) {
        cat("\nIn R, setting default argument for v\n")
        v <- seq(1,9)^2
    }

    ## Make the call...
    val <- .Call("RcppVectorExample",
                 v,
                 PACKAGE="RcppExamples")

    ## Define a class for the return value so we can control what gets
    ## printed when a variable assigned this value is typed on a line by itself.
    ## This has the effect of calling the function print.RcppExample(). The
    ## function (defined below) simply prints the names of the fields that are
    ## available. Access each field with val$name.
    class(val) <- "RcppExample"

    val
}
