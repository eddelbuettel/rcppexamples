// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppParamsExample.h: Rcpp R/C++ interface class library RcppVector example
//
// Copyright (C) 2005 - 2006 Dominick Samperi
// Copyright (C) 2008        Dirk Eddelbuettel
// Copyright (C) 2009 - 2010 Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#include <Rcpp.h>

RcppExport SEXP newRcppVectorExample(SEXP vector) {

    Rcpp::NumericVector vec(vector);		// creates Rcpp vector from SEXP
    Rcpp::NumericVector orig(vector);		// keep a copy (as the classic version does)

    // we could query size via
    //   int n = vec.size();
    // and loop over the vector, but using the STL is so much nicer
    // so we use a STL transform() algorithm on each element
    std::transform(orig.begin(), orig.end(), vec.begin(), sqrt);

    Rcpp::Pairlist res(Rcpp::Named( "result", vec),
                       Rcpp::Named( "original", orig));

    return res;
}

RcppExport SEXP classicRcppVectorExample(SEXP vector) {

    SEXP rl = R_NilValue; 		// Use this when there is nothing to be returned.
    char *exceptionMesg = NULL;

    try {

	// Get parameters in params.
	RcppVector<int> vec(vector);
	int n = vec.size();
	
	Rprintf("\nIn C++, seeing a vector of length %d\n", n);

	// create a C++ STL vector, and reserve appropriate size
	std::vector<double> res(n);
	
	for (int i=0; i<n; i++) {
	    res[i] = sqrt(static_cast<double>(vec(i)));
	}

	// Build result set to be returned as a list to R.
	RcppResultSet rs;

	rs.add("result",  res);
	rs.add("original", vec);

	// Get the list to be returned to R.
	rl = rs.getReturnList();
	
    } catch(std::exception& ex) {
	exceptionMesg = copyMessageToR(ex.what());
    } catch(...) {
	exceptionMesg = copyMessageToR("unknown reason");
    }
    
    if(exceptionMesg != NULL)
	Rf_error(exceptionMesg);

    return rl;
}


