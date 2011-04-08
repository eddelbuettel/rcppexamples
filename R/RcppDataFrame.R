
## RcppDataFrame.R: Rcpp R/C++ interface class library DataFrame example
##
## Copyright (C) 2011        Dirk Eddelbuettel and Romain Francois
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

RcppDataFrame <- function() {

    ## create a simple data.frame
    ## here we enforce strings, factors can be used too
    D <- data.frame(a=1:3,
                    b=LETTERS[1:3],
                    c=as.Date("2011-01-01")+0:2,
                    stringsAsFactors=FALSE)
    cat("Original data frame before call:\n")
    print(D)

    ## Make the call...
    val <- .Call("RcppDataFrame", D, PACKAGE="RcppExamples")

    cat("\nAfter call, original and new data frames:\n")
    print(val)

    val
}
