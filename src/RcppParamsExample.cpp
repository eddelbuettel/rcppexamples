// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppParamsExample.h: Rcpp R/C++ interface class library RcppParams example
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

RcppExport SEXP RcppParamsExample(SEXP params) {

    SEXP rl = R_NilValue; 	// Use this when there is nothing to be returned.
    char *exceptionMesg = NULL;

    try {

	// Get parameters in params.
	RcppParams rparam(params);
	std::string method      = rparam.getStringValue("method");
	double tolerance   = rparam.getDoubleValue("tolerance");
	int    maxIter     = rparam.getIntValue("maxIter");
	RcppDate startDate = rparam.getDateValue("startDate");
	
	Rprintf("\nIn C++, seeing the following value\n");
	Rprintf("Method argument    : %s\n", method.c_str());
	Rprintf("Tolerance argument : %f\n", tolerance);
	Rprintf("MaxIter argument   : %d\n", maxIter);
	Rprintf("Start date argument: %04d-%02d-%02d\n", 
		startDate.getYear(), startDate.getMonth(), startDate.getDay());

	// Build result set to be returned as a list to R.
	RcppResultSet rs;

	rs.add("method",    method);
	rs.add("tolerance", tolerance);
	rs.add("maxIter",   maxIter);
	rs.add("startDate", startDate);

	// Instead of returning selected input parameters as we did in
	// the last statements, the entire input parameter list can be
	// returned like this:
	rs.add("params", params, false);  // 'false' to not PROTECT params

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


