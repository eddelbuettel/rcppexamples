// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppStringVectorExample.cpp: Rcpp R/C++ interface class library 
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

RcppExport SEXP newRcppStringVectorExample(SEXP strvec) {
BEGIN_RCPP

    Rcpp::StringVector orig(strvec);		// creates Rcpp string vector from SEXP
    Rcpp::StringVector vec(orig.size());	

    std::transform( orig.begin(), orig.end(), vec.begin(), 
    	Rcpp::make_string_transformer(tolower) ) ;

    return Rcpp::List::create(
    	Rcpp::Named( "result" )   = vec,
    	Rcpp::Named( "original" ) = orig 
    	) ;

END_RCPP
}

RcppExport SEXP classicRcppStringVectorExample(SEXP strvec) {

    SEXP rl = R_NilValue; 		// Use this when there is nothing to be returned.
    char *exceptionMesg = NULL;

    try {

	RcppStringVector orig(strvec);
	RcppStringVector vec(strvec);
	
	for (int i=0; i<orig.size(); i++) {
	    std::transform(orig(i).begin(), orig(i).end(), 
			   vec(i).begin(), ::tolower);	
	}
	// Build result set to be returned as a list to R.
	RcppResultSet rs;

	rs.add("result",  vec);
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


