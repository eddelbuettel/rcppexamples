// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// ListExamples.cpp: List examples
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
List ListExamples(const List & rparam) {

    // accessing all list elements by name
    std::string method   = as<std::string>(rparam["method"]);
    double tolerance     = as<double>(rparam["tolerance"]);
    int    maxIter       = as<int>(rparam["maxIter"]);
    Date startDate = Date(as<int>(rparam["startDate"])); // ctor from int
	
    Rprintf("\nIn C++, seeing the following value\n");
    Rprintf("Method argument    : %s\n", method.c_str());
    Rprintf("Tolerance argument : %f\n", tolerance);
    Rprintf("MaxIter argument   : %d\n", maxIter);
    Rprintf("Start date argument: %04d-%02d-%02d\n", 
            startDate.getYear(), startDate.getMonth(), startDate.getDay());

    return List::create(Named("method", method),
                        Named("tolerance", tolerance),
                        Named("maxIter", maxIter),
                        Named("startDate", startDate),
                        Named("params", rparam));

}



