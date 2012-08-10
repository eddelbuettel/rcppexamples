// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppRNGs.cpp: Rcpp R/C++ interface class library RNG example
//
// Copyright (C) 2012        Dirk Eddelbuettel and Romain Francois
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

RcppExport SEXP RcppRNGs(SEXP ns) {

    try {					// or use BEGIN_RCPP macro
        
        Rcpp::RNGScope scope;         		// needed when RNGs are drawn

        int n = Rcpp::as<int>(ns); 		// length vector 
        Rcpp::NumericVector rn = Rcpp::rnorm(n);
        Rcpp::NumericVector rt = Rcpp::rt(n, 1.0);
        Rcpp::NumericVector rp = Rcpp::rpois(n, 1.0);

        // create a new data frame to return drawns
        Rcpp::DataFrame NDF = 
            Rcpp::DataFrame::create(Rcpp::Named("rnorm") =rn,
                                    Rcpp::Named("rt")    =rt,
                                    Rcpp::Named("rpois") =rp);

        // and return old and new in list
        return(NDF);

    } catch( std::exception &ex ) {		// or use END_RCPP macro
	forward_exception_to_r( ex );
    } catch(...) { 
	::Rf_error( "c++ exception (unknown reason)" ); 
    }
    return R_NilValue; // -Wall
}



