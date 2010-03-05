
## RcppStringVectorExample.R: Rcpp R/C++ interface class library
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

RcppStringVectorExample <- function(vec=c("Tick", "Tack", "Tock"),
                                    api=c("classic", "new")) {

    api <- match.arg(api)               # match to classic or new
    fun <- paste(api, "RcppStringVectorExample", sep="")

    ## Make the call...
    val <- .Call(fun,                   # either new or classic
                 vec,
                 PACKAGE="RcppExamples")

    val
}
