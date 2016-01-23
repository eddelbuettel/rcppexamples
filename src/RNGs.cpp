// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppRNGs.cpp: RNG example
//
// Copyright (C) 2012 - 2016  Dirk Eddelbuettel and Romain Francois
//
// This file is part of RcppExamples.
//
// RcppExamples is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// RcppExamples is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with RcppExamples.  If not, see <http://www.gnu.org/licenses/>.

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
DataFrame RcppRNGs(const int n) {
    NumericVector xn = rnorm(n);
    NumericVector xt = rt(n, 1.0);
    NumericVector xp = rpois(n, 1.0);
    
    // create a new data frame to return drawns
    return DataFrame::create(Named("rnorm") = xn,
                             Named("rt")    = xt,
                             Named("rpois") = xp);
}

