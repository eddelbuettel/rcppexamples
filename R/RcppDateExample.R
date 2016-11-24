
## RcppDateExample.R: RcppDate example
##
## Copyright (C) 2008        Dirk Eddelbuettel
## Copyright (C) 2009 - 2016 Dirk Eddelbuettel and Romain Francois
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

RcppDateExample <- function(dv, dtv) {

    ## Check that params is properly set.
    if (missing(dv)) {
        cat("\nIn R, setting default argument for dv\n")
        dv <- Sys.Date() + -2:2
    }

    if (missing(dtv)) {
        cat("\nIn R, setting default argument for dtv\n")
        dtv <- Sys.time() + (-2:2)*0.5
    }

    optdig <- getOption("digits.secs")
    options(digits.secs=3)

    ## Make the call...
    val <- DateExample(dv, dtv)

    options(digits.secs=optdig)

    val
}

