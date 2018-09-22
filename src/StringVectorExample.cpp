// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppStringVectorExample.cpp: 
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
using namespace Rcpp;

template <class T> T mytolower (T c) {
    static std::locale loc;
    return std::tolower(c, loc);
}

// [[Rcpp::export]]
List StringVectorExample(const StringVector & orig) {
    StringVector vec(orig.size());	

    std::transform(orig.begin(), orig.end(), vec.begin(), 
		   make_string_transformer(mytolower<char>) );

    return List::create(Named("result")   = vec,
                        Named("original") = orig);
}

