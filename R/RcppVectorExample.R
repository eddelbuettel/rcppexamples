
## RcppVectorExample.R: RcppVector example
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

RcppNumericVectorExample <- function(vec=seq(1,9)^2) {

    ## Make the call...
    val <- NumericVectorExample(vec)
    val
}
