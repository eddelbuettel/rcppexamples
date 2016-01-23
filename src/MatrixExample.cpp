// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppMatrixExample.cpp: RcppMatrix example
//
// Copyright (C) 2009 - 2016  Dirk Eddelbuettel and Romain Francois
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
#include <cmath>

// suncc needs help to disambiguate between sqrt( float ) and sqrt(double) 
inline static double sqrt_double(double x) { return ::sqrt(x); }

using namespace Rcpp; 

// [[Rcpp::export]]
List MatrixExample(const NumericMatrix & orig) {
    NumericMatrix mat(orig.nrow(), orig.ncol());	

    // we could query size via
    //   int n = mat.nrow(), k=mat.ncol();
    // and loop over the elements, but using the STL is so much nicer
    // so we use a STL transform() algorithm on each element
    std::transform(orig.begin(), orig.end(), mat.begin(), sqrt_double);

    return List::create(Named("result") = mat, 
                        Named("original") = orig);
}

