/*  FILE     Statistics.hh
**  PACKAGE  Statistics
**  AUTHOR   ytsybukh
**
**  CONTENT
**    Definitions for the "Statistics" package.
**
**  OVERVIEW
**    This package is designed to perform
**    some typical statistical procedures -
**    regression, factor analysis, cluster analysis.
**    Regression at present is implemented as 
**    generalized linear regression.
**    Cluster analysis at present uses K-mean algorihtm 
**    More features will be added
**   
**
**  IMPLEMENTATION
**    implementation remarks
**
**  REFERENCES
**
**  COPYRIGHT (C) 1996 Reaction, Edward S. Blurock
*/
 
#ifndef REACTION_STATISTICS_HH
#define REACTION_STATISTICS_HH
 
 
/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
#ifdef _msdos_stl
#include <iostream>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
#pragma warning(disable:4786)
#else
#include "STL.h"
#endif

#include <math.h>
typedef vector<int> myvector_int;
extern int Zero(int& x);
extern float Zero(float& x);
extern double Zero(double& x);
extern int Unit(int& x);
extern float Unit(float& x);
extern double Unit(double& x);

#include "StatisticsType.hh"
	
	
/*P  . . . PROTOTYPES  . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
template <class T>
bool operator>(const ClusterObject<T>& t1, const ClusterObject<T>& t2);
template <class T>
bool operator==(const ClusterObject<T>& t1, const ClusterObject<T>& t2);



// Inlines
#include "Statistics.itc"


template<class T> 
extern void FindCorrelEigen(Matrix<T> InMatrix, Matrix<T>& OutEigenMatrix, vector<T>&
			    OutEigenVector);

template<class T> 
extern Matrix<T> ReduceInMatrix(Matrix<T> InMatrix,
				Matrix<T>& OutEigenMatrix, vector<T>& OutEigenVector, T CutOff);

template<class T> 
extern void LeastSquares(vector<T> x_exp, vector<T> y_exp, vector<T> sigmas, vector<T>&
			 params);

template <class T>          
extern void CalcPolyProdValues(T x, vector<T>& values, int N);
#ifdef TEMPLATE_INSTANTIATION
// Exported
#include "Statistics.tcc"
#endif
#endif




