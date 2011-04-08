// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// DataFrame.cpp: Rcpp R/C++ interface class library data frame example
//
// Copyright (C) 2011        Dirk Eddelbuettel and Romain Francois
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

RcppExport SEXP RcppDataFrame(SEXP Dsexp) {

    try {					// or use BEGIN_RCPP macro

      // construct the data.frame object
      Rcpp::DataFrame DF = Rcpp::DataFrame(Dsexp);

      // and access each column by name
      Rcpp::IntegerVector a = DF["a"];
      Rcpp::CharacterVector b = DF["b"];
      Rcpp::DateVector c = DF["c"];
      
      // do something
      a[2] = 42;
      b[1] = "foo";
      c[0] = c[0] + 7;                      // move up a week

      // create a new data frame
      Rcpp::DataFrame NDF = 
	  Rcpp::DataFrame::create(Rcpp::Named("a")=a,
				  Rcpp::Named("b")=b,
				  Rcpp::Named("c")=c);

      // and return old and new in list
      return(Rcpp::List::create(Rcpp::Named("origDataFrame")=DF,
				Rcpp::Named("newDataFrame")=NDF));

    } catch( std::exception &ex ) {		// or use END_RCPP macro
	forward_exception_to_r( ex );
    } catch(...) { 
	::Rf_error( "c++ exception (unknown reason)" ); 
    }
    return R_NilValue; // -Wall
}



