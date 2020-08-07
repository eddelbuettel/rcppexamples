// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// DateExample.cpp: RcppDate example
//
// Copyright (C) 2009 - 2020  Dirk Eddelbuettel and Romain Francois
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
List DateExample(DateVector & dv, DatetimeVector & dtv) {
    // Support for this changed with Rcpp 0.12.8 but is still optional
    // Support for << redirection added added with 0.12.8.2 and later
    Rcout << "\nIn C++, seeing the following date values before/after adding a week:\n"
          << dv << std::endl;
    dv = dv + 7;		// shift a week
    Rcout << dv << std::endl;

    Rcout << "\nIn C++, seeing the following datetime values before/after adding a quarter second:\n"
          << dtv << std::endl;
    dtv = dtv + 0.250;          // shift 250 millisec
    Rcout << dtv << std::endl;

    // Build result set to be returned as a list to R.
    return List::create(Named("date",   dv),
                        Named("datetime", dtv));
}
