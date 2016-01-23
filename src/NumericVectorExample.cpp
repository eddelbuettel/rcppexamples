// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// NumericVectorExample.cpp: RcppVector example
//
// Copyright (C) 2005 - 2006  Dominick Samperi
// Copyright (C) 2008         Dirk Eddelbuettel
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

using namespace Rcpp; 

// suncc needs help to disambiguate between sqrt( float ) and sqrt(double) 
inline static double sqrt_double( double x ){ return ::sqrt( x ); }

// [[Rcpp::export]]
List NumericVectorExample(const NumericVector & orig) {
    NumericVector vec(orig.size());		// create a target vector of the same size
    
    // we could query size via
    //   int n = vec.size();
    // and loop over the vector, but using the STL is so much nicer
    // so we use a STL transform() algorithm on each element
    std::transform(orig.begin(), orig.end(), vec.begin(), sqrt_double);

    return List::create(Named("result") = vec, 
                        Named("original") = orig);
}



