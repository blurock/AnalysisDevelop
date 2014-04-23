#include "BasisSystem.hh"
#define TEMPLATE_INSTANTIATION
#include "Matrix.hh"
#include "Statistics.hh"


#define VECTOR_TYPE double


// Some statistical external routines

template void FindCorrelEigen(Matrix<VECTOR_TYPE>, Matrix<VECTOR_TYPE>&,
			      vector<VECTOR_TYPE>& );

template Matrix<VECTOR_TYPE> ReduceInMatrix(Matrix<VECTOR_TYPE>, Matrix<VECTOR_TYPE>&,
					    vector<VECTOR_TYPE>&, VECTOR_TYPE);

template void LeastSquares(vector<VECTOR_TYPE>, vector<VECTOR_TYPE>,
			   vector<VECTOR_TYPE>, vector<VECTOR_TYPE>&);

// Auxiliary function
// whchange added void:
template void CalcPolyProdValues(VECTOR_TYPE, vector<VECTOR_TYPE>&, int);

template class ClusterObject<VECTOR_TYPE>;
template class Cluster<VECTOR_TYPE>;
#undef VECTOR_TYPE

