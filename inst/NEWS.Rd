\name{NEWS}
\title{News for Package \pkg{RcppExamples}}

\section{Changes in RcppExamples version 0.1.8 (2016-11-24)}{
  \itemize{
    \item Updated DateExample to show vector addition available under
    Rcpp 0.12.8 when the (currently still phased in and optional) new
    Date(time) classes are used via the define in src/Makevars{,.win};
    with fallback code for older versions 
    \item Other minor edits to DESCRIPTION and README.md
  }
}

\section{Changes in RcppExamples version 0.1.7 (2016-01-23)}{
  \itemize{
    \item All examples were updated to use \emph{Rcpp Attributes}
    and (where possible) use \code{const &} interfaces.  
    \item Updated \code{DESCRIPTION} for current \code{R CMD check}
    standards
    \item The \CRANpkg{Rcpp} package is now imported rather than depended
    upon. 
    \item Added \code{README.md} as well as \code{.travis.yml}.
    \item Also updated and refreshed all manual pages and R files.
  }
}

\section{Changes in RcppExamples version 0.1.6 (2013-01-15)}{
  \itemize{
    \item Moved \code{NEWS.Rd} from top-level directory to correct
    location \code{inst/} per CRAN maintainer suggestion
  }
}

\section{Changes in RcppExamples version 0.1.5 (2012-12-27)}{
  \itemize{
    \item Moved all examples using \CRANpkg{RcppClassic} to a new package
      \CRANpkg{RcppClassicExamples}
    \item Various minor small updates
  }
}

\section{Changes in RcppExamples version 0.1.4 (2012-08-09)}{
  \itemize{
    \item Added new example for Rcpp sugar and vectorised draws of RNGs
    \item Minor updates to reflect newer CRAN Policy
  }
}
\section{Changes in RcppExamples version 0.1.3 (2011-12-28)}{
  \itemize{
    \item Added new example for Rcpp::DataFrame
    \item Switched two examples from using std::cout (which 'Writing R
      Extensions' recommends agains) to the new Rcpp::Rcout device
    \item Minor .Rd correction, suppressing one warning
  }
}
\section{Changes in RcppExamples version 0.1.2 (2010-12-20)}{
  \itemize{
    \item Updated src/Makevars
    \item Now depends also on RcppClassic so that we can keep continue to show
      examples using the classic API
    \item Added examples for Rcpp::Date, Rcpp::Datetime and Rcpp::List
  }
}
\section{Changes in RcppExamples version 0.1.1 (2010-07-29)}{
  \itemize{
    \item Minor update, no new examples or documentation added yet
  }
}
\section{Changes in RcppExamples version 0.1.0 (2010-03-10)}{
  \itemize{
    \item Initial release as a package, carved out of Rcpp 0.7.7
  }
}
