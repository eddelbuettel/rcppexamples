// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppParamsExample.h: Rcpp R/C++ interface class library RcppParams example
//
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

RcppExport SEXP newRcppParamsExample(SEXP params) {

    try {					// or use BEGIN_RCPP macro

	Rcpp::List rparam(params); 		// Get parameters in params.
	std::string method   = Rcpp::as<std::string>(rparam["method"]);
	double tolerance     = Rcpp::as<double>(rparam["tolerance"]);
	int    maxIter       = Rcpp::as<int>(rparam["maxIter"]);
	Rcpp::Date startDate = Rcpp::Date(Rcpp::as<int>(rparam["startDate"])); // ctor from int
	
	Rprintf("\nIn C++, seeing the following value\n");
	Rprintf("Method argument    : %s\n", method.c_str());
	Rprintf("Tolerance argument : %f\n", tolerance);
	Rprintf("MaxIter argument   : %d\n", maxIter);
	Rprintf("Start date argument: %04d-%02d-%02d\n", 
		startDate.getYear(), startDate.getMonth(), startDate.getDay());

	return Rcpp::List::create(Rcpp::Named("method", method),
				  Rcpp::Named("tolerance", tolerance),
				  Rcpp::Named("maxIter", maxIter),
				  Rcpp::Named("startDate", startDate),
				  Rcpp::Named("params", params));  // or use rparam

    } catch( std::exception &ex ) {		// or use END_RCPP macro
	forward_exception_to_r( ex );
    } catch(...) { 
	::Rf_error( "c++ exception (unknown reason)" ); 
    }
    return R_NilValue; // -Wall
}



