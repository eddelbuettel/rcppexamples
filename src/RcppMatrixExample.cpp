// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppMatrixExample.cpp: Rcpp R/C++ interface class library RcppMatrix example
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
#include <cmath>

RcppExport SEXP newRcppMatrixExample(SEXP matrix) {
BEGIN_RCPP

    Rcpp::NumericMatrix orig(matrix);	// creates Rcpp matrix from SEXP
    Rcpp::NumericMatrix mat(orig.nrow(), orig.ncol());	

    // we could query size via
    //   int n = mat.nrow(), k=mat.ncol();
    // and loop over the elements, but using the STL is so much nicer
    // so we use a STL transform() algorithm on each element
    std::transform(orig.begin(), orig.end(), mat.begin(), sqrt);

    Rcpp::Pairlist res(Rcpp::Named( "result", mat),
                       Rcpp::Named( "original", orig));

    return res;
END_RCPP
}

RcppExport SEXP classicRcppMatrixExample(SEXP matrix) {

    SEXP rl = R_NilValue; 		// Use this when there is nothing to be returned.
    char *exceptionMesg = NULL;

    try {

	// Get parameters in params.
	RcppMatrix<int> orig(matrix);
	int n = orig.rows(), k = orig.cols();
	
	RcppMatrix<double> mat(n, k); 	// reserve n by k matrix
 
	for (int i=0; i<n; i++) {
	    for (int j=0; j<k; j++) {
		mat(i,j) = sqrt(orig(i,j));
	    }
	}

	// Build result set to be returned as a list to R.
	RcppResultSet rs;

	rs.add("result",  mat);
	rs.add("original", orig);

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


