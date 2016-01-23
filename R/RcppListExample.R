
## RcppListExample.R: RcppParams example
##
## Copyright (C) 2008         Dirk Eddelbuettel
## Copyright (C) 2009 - 2016  Dirk Eddelbuettel and Romain Francois
##
## This file is part of RcppExamples.
##
## RcppExamples is free software: you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 2 of the License, or
## (at your option) any later version.
##
## RcppExamples is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with RcppExamples.  If not, see <http://www.gnu.org/licenses/>.

RcppListExample <- function(params) {

    ## Check that params is properly set.
    if (missing(params)) {
        cat("\nIn R, setting default argument for params\n")
        params <- list(method='BFGS',
                       tolerance=1.0e-8,
                       maxIter=1000,
                       startDate=as.Date('2006-7-15'))
    }

    ## Make the call...
    val <- ListExamples(params)
    val
}

