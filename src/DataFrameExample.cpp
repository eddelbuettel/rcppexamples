// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// DataFrame.cpp: data frame example
//
// Copyright (C) 2011 - 2016  Dirk Eddelbuettel and Romain Francois
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
List DataFrameExample(const DataFrame & DF) {

    // access each column by name
    IntegerVector a = DF["a"];
    CharacterVector b = DF["b"];
    DateVector c = DF["c"];
    
    // do something
    a[2] = 42;
    b[1] = "foo";
    c[0] = c[0] + 7; // move up a week
    
    // create a new data frame
    DataFrame NDF = DataFrame::create(Named("a")=a,
                                      Named("b")=b,
                                      Named("c")=c);
    
    // and return old and new in list
    return List::create(Named("origDataFrame") = DF,
                        Named("newDataFrame") = NDF);
}



