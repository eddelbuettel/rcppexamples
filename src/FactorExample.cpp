
// FactorExample.cpp: Factor example
//
// Copyright (C) 2023 - 2024  Dirk Eddelbuettel
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

#include <Rcpp/Lightest>
#include <cstdint>      		// for int32_t, needed on Windoze

// Adapted with love from R's own src/coerce.c

//' Convert Index and String Vector into CharacterVector, and vice versa
//'
//' These two functions are an illustration of how \code{as.character} and
//' \code{as.factor} may be reimplemented at the C++ level.
//' @param iv A Integer Vector corresponding to numeric representation of the factor
//' This vector is also expected to have an attribute \sQuote{levels} with the factor
//' levels
//' @return A Character Vector which at each position contains the level value of the
//' corresponding index, or a Factor, depending on the function
//' @examples
//' f <- as.factor(c("red", "green", "blue", "red"))
//' factor2char(f);
// [[Rcpp::export]]
Rcpp::CharacterVector factor2char(Rcpp::IntegerVector iv) {
    // could add a check here but it will throw appropriately
    std::vector<std::string> cv = iv.attr("levels");
    R_xlen_t n = iv.size();
    Rcpp::CharacterVector ans(n);
    R_xlen_t nl = cv.size();
    for (R_xlen_t i=0; i<n; i++) {
        int ii = iv[i];
        if (ii == NA_INTEGER)   // this is R and we do have a bitmap for NA on ints
            ans[i] = NA_STRING; // and on strings
        else if (ii >= 1 && ii <= nl)
            ans[i] = cv[ii - 1];
        else
            Rcpp::stop("Malformed factor");
    }
    return ans;
}

//' @rdname factor2char
//' @param sv A String Vector
//' @examples
//' f <- as.factor(c("red", "green", "blue", "red"))
//' v <- factor2char(f);
//' char2factor(v)
// [[Rcpp::export]]
Rcpp::IntegerVector char2factor(std::vector<std::string> sv) {
    // Use a set to keep track of what we have already seen
    std::set<std::string> ss;
    for (auto& s: sv) {
        if (ss.find(s) == ss.end()) {
            //Rcpp::Rcout << "Inserting " << s << std::endl;
            ss.insert(s);
        }
    }

    // Map strings to position, also fill vector for levels
    std::unordered_map<std::string, int32_t> mp;
    std::vector<std::string> vv;
    int32_t pos = 0;
    for (auto& s: ss) {
        mp[s] = ++pos;
        //Rcpp::Rcout << "Mapping " << s << " to " << pos << std::endl;
        vv.push_back(s);
    }

    // Put it back into an integer vector mapping each string to its pos
    size_t n = sv.size();
    Rcpp::IntegerVector iv(n);
    for (size_t i=0; i<n; i++) {
        iv[i] = mp[ sv[i] ];
    }

    // And a factor really is just a vector with a commensurate class
    // attribute, and its levels as another attribute
    iv.attr("levels") = vv;
    iv.attr("class") = "factor";
    return iv;
}
