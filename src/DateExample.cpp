// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// DateExample.cpp: RcppDate example
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

// [[Rcpp::export]]
List DateExample(DateVector & dv, DatetimeVector & dtv) {
    Function formatDate("format.Date");
    Function formatDatetime("format.POSIXct");

    Rcout << "\nIn C++, seeing the following date values before/after adding a week:\n";
    print(formatDate(dv));
#if RCPP_VERSION >= Rcpp_Version(0,12,8)
    dv = dv + 7;		// shift a week
#else
    // fallback for older Rcpp versions
    for (int i=0; i<dv.size(); i++) {
        dv[i] = dv[i] + 7;
    }
#endif
    print(formatDate(dv));

    Rcout << "\nIn C++, seeing the following datetime values before/after adding a quarter second:\n";
    print(formatDatetime(dtv));
#if RCPP_DEV_VERSION >= RcppDevVersion(0,12,8,1)
    // this didn't get done quite right in Rcpp 0.12.8
    dtv = dtv + 0.250;          // shift 250 millisec
#else
    // fallback
    for (int i=0; i<dtv.size(); i++) {
        dtv[i] = dtv[i] + 0.250;
    }
#endif
    print(formatDatetime(dtv));
    
    // Build result set to be returned as a list to R.
    return List::create(Named("date",   dv),
                        Named("datetime", dtv));
}


