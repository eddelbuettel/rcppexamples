// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// DateExample.cpp: RcppDate example
//
// Copyright (C) 2009 - 2013 Dirk Eddelbuettel and Romain Francois
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
List DateExample(DateVector dv, DatetimeVector dtv) {
	Function formatDate("format.Date");
	Function formatDatetime("format.POSIXct");

	Rprintf("\nIn C++, seeing the following date value\n");
	for (int i=0; i<dv.size(); i++) {
	    Rcout << as<std::string>(formatDate(wrap(dv[i]))) << std::endl;
	    dv[i] = dv[i] + 7;		// shift a week
	}
	Rprintf("\nIn C++, seeing the following datetime value\n");
	for (int i=0; i<dtv.size(); i++) {
	    Rcout << as<std::string>(formatDatetime(wrap(dtv[i]))) << std::endl;
	    dtv[i] = dtv[i] + 0.250;    // shift 250 millisec
	}

	// Build result set to be returned as a list to R.
	List result = List::create(
        Named("date",   dv),
        Named("datetime", dtv)
        );
    
    return result ;
}


