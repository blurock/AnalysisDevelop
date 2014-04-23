/*  FILE     Statistics.tcc
**  PACKAGE  Statistics
**  AUTHOR   ytsybukh
**
**  CONTENT
**    Exported functions for the "Statistics" package.
**
**  REFERENCES
**
**  COPYRIGHT (C) REACTION Project, Edward S. Blurock
*/



extern int Zero(int& x);
extern float Zero(float& x);
extern double Zero(double& x);


extern int Unit(int& x);
extern float Unit(float& x);
extern double Unit(double& x);

/*F FindCorrelEigen(InMatrix, OutEigenMatrix, OutEigenVector) . . . . . . .  
**
**  DESCRIPTION
**    InMatrix: param.
**    OutEigenMatrix: param.
**    OutEigenVector: param.
**
**    External (non-member) to any class within Statistics package routine.
**    Routine FindCorrelEigen(InMatrix, OutEigenMatrix, OutEigenVector) 
**    calculates correlation matrix from given input factor matrix,
**    and calculates its eigenvalues and corresponding eigenvectors.
**    Eigenvectors are presented as columns of matrix - OutEigenMatrix.
**    
**  REMARKS
**
*/
template<class T> void FindCorrelEigen(Matrix<T> InMatrix, Matrix<T>& OutEigenMatrix, vector<T>& OutEigenVector)
  {
    int x;
    int rotations = Zero(x);
    int n;

    n = InMatrix[0].size();    
    Matrix<T> InMatrixTranspose = InMatrix.transpose();
    Matrix<T> CorrelMatrix = InMatrixTranspose*InMatrix;
    jacobi(CorrelMatrix, OutEigenVector, OutEigenMatrix, rotations);
 
  };
 
/*F ReduceInMatrix(InMatrix, OutEigenMatrix, OutEigenVector, CutOff)  . . .  
**
**  DESCRIPTION
**    InMatrix: param.
**    OutEigenMatrix: param.
**    OutEigenVector: param.
**    CutOff: param.
** 
**    External (non-member) to any class within Statistics package routine.
**    Routine ReduceInMatrix(InMatrix, OutEigenMatrix, OutEigenVector, CutOff)
**    transforms initial input factor matrix considering values of calculated 
**    eigenvectors and eigenvalues of correlation matrix.
**    Eigenvectors are presented as columns of matrix - OutEigenMatrix.
**    Order of columns corresponds to the order of eigenvalues.
**    Input to the routine ReduceInMatrix(InMatrix, OutEigenMatrix, OutEigenVector, CutOff)
**    has to be prepared by FindCorrelEigen(InMatrix, OutEigenMatrix, OutEigenVector).
**    Parameter CutOff is the eigenvalue threshold. According to its value routine 
**    performs transformation (reduction) of initial input factor matrix.
**  REMARKS
**
*/
template<class T> Matrix<T> ReduceInMatrix(Matrix<T> InMatrix,
					   Matrix<T>& OutEigenMatrix, vector<T>& OutEigenVector, T CutOff)
  {

   Matrix<T> ReducedTransposedOutEigenMatrix(0,0);
   unsigned int i;


   Matrix<T> TransposedOutEigenMatrix = OutEigenMatrix.transpose();
   for(i=0; i<= OutEigenVector.size(); i++)
         if(OutEigenVector[i] >= CutOff)
           ReducedTransposedOutEigenMatrix.push_back(TransposedOutEigenMatrix[i]);

   Matrix<T> ReducedOutEigenMatrix = ReducedTransposedOutEigenMatrix.transpose();
   cout << "--------------------------------\n ";
   cout << " ReducedTransposedOutEigenMatrix " << " \n";
   cout << ReducedTransposedOutEigenMatrix;
   cout << "--------------------------------\n ";
   cout << " ReducedOutEigenMatrix " << " \n";
   cout << ReducedOutEigenMatrix;
   Matrix<T> ReducedInMatrix = InMatrix*ReducedOutEigenMatrix;

   return ReducedInMatrix;

  
  };

   
/*F LeastSquares(x_exp, y_exp, sigmas, params)  . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**    x_exp: param.
**    y_exp: param.
**    sigmas: param.
**    params: param.
**
**    External (non-member) to any class within Statistics package routine.
**    Routine LeastSquares(x_exp, y_exp, sigmas, params) 
**    allows to perform linear least squares fit of the 
**    experimental data ( given in form : independent
**    variable x_exp(i); corresponding depending variable y_exp(i) )
**    and the user defined approximation function with the set of 
**    parameters, which are calculated by the routine.
**  
**  
**  REMARKS
**
*/  
template<class T> void LeastSquares(vector<T> x_exp, vector<T> y_exp, vector<T> sigmas, vector<T>& params)


{ 
  unsigned int i,j;
  T x;
  
  
  unsigned int dim1=x_exp.size();
  unsigned int dim2=params.size();
  
  Matrix<T> a(dim1,dim2);
  
  vector<T> basis_values(dim2, Zero(x));
  
  vector<T> b(dim1, Zero(x));
  

for( i=0; i<=dim1-1; i++)
  for(j=0; j<=dim2-1; j++) 
     a[i][j] = Zero(x);

for(i=0; i<=dim1-1; i++)
 {
  CalcPolyProdValues(x_exp[i], basis_values, dim2);
     for(j=0;j<=dim2-1; j++)
	  a[i][j]= basis_values[j];
//          a[i][j]= basis_values[j]/sigmas[i];
  
 };


 for(i=0; i<=dim1-1; i++)
     b[i]=y_exp[i];
//     b[i]=y_exp[i]/sigmas[i];

 
 Matrix<T> b_as_matrix(1, dim1);

 copy(b.begin(), b.end(), b_as_matrix[0].begin());

 Matrix<T> transpose_a=a.transpose();

 Matrix<T> alpha = transpose_a*a;

 Matrix<T> copy_alpha=alpha;

 Matrix<T> transpose_b_as_matrix = b_as_matrix.transpose();

 Matrix<T> beta=transpose_a*transpose_b_as_matrix;

 Matrix<T> transpose_beta = beta.transpose(); 

 vector<T> beta_as_vector = transpose_beta[0];

 vector<T> copy_beta_as_vector = beta_as_vector;

 alpha.gauss_jordan(alpha, beta_as_vector, dim2);
 
 params = beta_as_vector;
 

 };
 

/*F CalcPolyProdValues(x, values, N)  . . . . . . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**    x: param.
**    values: param.
**    N: param.
** 
**    External (non-member) to any class within Statistics package routine.        
**    Routine CalcPolyProdValues(x, values, N) calculates power products of 
**    polynomial in point x.    
**
**  REMARKS
**
*/
template <class T>          
void CalcPolyProdValues(T x, vector<T>& values, int N)
     {
     int i;
     for(i=0; i<=N-1;i++)
	  values[i]=pow(x,i);	   
     
     };



/*F choose_unique(mat)  . . . . . . . . . . . . . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**    mat : param.
**
**    Chooses unique input points.
**    
**  REMARKS
**
*/
template<class T>  Matrix<T> Cluster<T>::choose_unique(Matrix<T> mat)
      {
      Matrix<T>::iterator v;  
      
      Matrix<T>	 mat_unique = mat ;

      v  = unique(mat_unique.begin(), mat_unique.end());
      mat_unique.erase(v, mat_unique.end());
      
      return mat_unique;
      

      };
 
/*F calculate_new_center(center, mat_of_points) . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**    center: param.
**    mat_of_points: param.
**
**    Calculates new cluster center.    
**
**  REMARKS
**
*/
template<class T>  void Cluster<T>::calculate_new_center( vector<T>& center, Matrix<T> mat_of_points)
     {
      unsigned int i;
      T x;
      
/*
      cout << " old center " << " \n";
      cout << center;
      cout << "--------------------------- \n";
      cout << " center.size() " << center.size() << " \n";
      cout << " mat_of_points[0].size() " << mat_of_points[0].size() << " \n";
      cout << "--------------------------- \n";
*/ 
      if (mat_of_points.size()!=0)
	{
	 fill_n (center.begin (), center.size (), Zero(x)); 
           for( i=0; i<=mat_of_points.size()-1; i++)
                 center = center+mat_of_points[i];
           center = center/(mat_of_points.size());
	 };
      
      

     };
 
/*F compare_centers( actual_clusters, mat_old_centers)  . . . . . . . . . .  
**
**  DESCRIPTION
**    actual_clusters: param.
**    mat_old_centers: param.
**    
**    Compares coordinates of new and old (calculated on the
**    previous step) cluster centers. In case all new and old
**    centers coincide, returns 1. If even one pair of centers 
**    does not coincide, returns 0.
**    
**  REMARKS
**
*/
template<class T> int Cluster<T>::compare_centers(vector< ClusterObject<T>  >&  actual_clusters, Matrix<T>& mat_old_centers)
    {
     int sentinel;
     unsigned int i, j;
     int x;

     sentinel = Unit(x);
     if(actual_clusters.size()==mat_old_centers.size()&& actual_clusters[0].center.size()==mat_old_centers[0].size())
        {
         for(i=0;i<=actual_clusters.size()-1;i++)
            for(j=0;j<=actual_clusters[i].center.size()-1;j++)
                   {if(actual_clusters[i].center[j]!=mat_old_centers[i][j])
                       {
                         sentinel = Zero(x);
                         return sentinel;
                       };
                    };
         return sentinel;
         }
      else 
         {
          cout << " in compare_centers different dimensions " << " \n";
          sentinel = Zero(x);
          return sentinel;
         };
      };
 
/*F euclid_norm(Vec1, Vec2) . . . . . . . . . . . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**    Vec1: param.
**    Vec2: param.
**
**    Calculates Euclidean norm of input vectors difference. 
**   
**  REMARKS
**
*/
template<class T> T  Cluster<T>::euclid_norm( vector<T> Vec1,  vector<T> Vec2)
      {

              T x;
	      if (Vec1.size()==Vec2.size())
	           {
                   
                    vector<T> Temp(Vec1.size(), Zero(x));
                    vector<T> Temp1(Vec1.size(), Zero(x));

                    transform(Vec1.begin(), Vec1.end(), Vec2.begin(), Temp.begin(), minus<T>());
                    transform(Temp.begin(), Temp.end(), Temp.begin(), Temp1.begin(), times<T>());
                    T Temp_scalar = accumulate(Temp1.begin(), Temp1.end(), Zero(x));
                 
	            return Temp_scalar;

	           };

               return Zero(x);
//  	       cout << " Sorry vectors have different sizes\n";

      };

 
/*F K_mean_method(K, input) . . . . . . . . . . . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**    K: param.
**    input: param.
**
**    Routine K_mean_method(K, input) is the implementation of one of the
**    clustering algorithms. Firs parameter to the routine is the number
**    of clusters, second parameter -matrix with number of rows (dim1) equal
**    to the number of experimental points and number of columns (dim2)
**    equal to the space dimension. 
**    On output points of each cluster along with the appropriate cluster 
**    number are returned.
**    If the number of clusters is greater or equal to the number of experimental
**    points, then these points are returned on the output.     
**
**  REMARKS
**
*/
template<class T> void Cluster<T>::K_mean_method(unsigned int K, Matrix<T> input)
 {
  
  T zero_T;
  int zero_int;
  vector<T> zero_vector_T;

  unsigned int i, j, count;
  int number_of_iterations = Zero(zero_int);
  T  dummy;  

  vector< ClusterObject<T> > RealClusters(K); 
  Matrix<T> OldCenters(K,input[0].size());

  int indicator = Zero(zero_int); 
  vector<T> sample_norm(K, Zero(zero_T));
  Matrix<T> temp_norm(K, input.size());

// Copy of input
     Matrix<T> input_copy = input;
     
// Make unique set
   
   Matrix<T> unique_input = choose_unique(input_copy);

//   cout << " ------------------------- \n";
//   cout << "unique_input " << " \n";
//   cout << unique_input;
//   cout << " ------------------------- \n";
   
   
   if(unique_input.size()<=K)
     {
	           
        cout << "number of unique is less or equal to K \n"; 
        
	cout << " ------------------------- \n";
	cout << "  unchanged unique input " << " \n";
	for(i=0; i<=unique_input.size()-1; i++)	     
	       cout << unique_input[i] << " \n" ;
	     
      }
  else
      {
       
// Initial choise of cluster centers

   for(i=0; i<=K-1; i++)
     RealClusters[i].set_center(unique_input[i]);

/* for(i=0; i<=K-1; i++)
   {    
    cout << " ----------------------- \n";
    cout << "  RealClusters[ " << i << "].center \n ";
    cout <<  RealClusters[i].center;
    cout << " ----------------------- \n";
   };
*/


// Zero initiation of OldCenters

 for (i=0;i<=K-1;i++)
   for(j=0;j<=input[0].size()-1;j++)
     OldCenters[i][j]=Zero(zero_T);

//  cout << " ----------------------- \n";
//  cout << " OldCenters \n"; 
//  cout << OldCenters;
//  cout << " ----------------------- \n";
 
 
// Computing matrix of norms for centers and input points 

 for (i=0;i<=K-1;i++)
   for(j=0;j<=input.size()-1;j++)
       temp_norm[i][j]=euclid_norm(RealClusters[i].center, input[j]);

//  cout << " ----------------------- \n";
//  cout << " temp_norm  \n ";
//  cout <<  temp_norm;
//  cout << " ----------------------- \n";



// Initializing sample norm ( first set it to maximum )

 for (i=0;i<=K-1;i++)
     sample_norm[i]=*max_element(temp_norm[i].begin(), temp_norm[i].end());

  
//  cout << " ----------------------- \n";
//  cout << " sample_norm  \n ";
//  cout <<  sample_norm;
//  cout << " ----------------------- \n";
  


// Initial partitioning to clusters

  for(j=0; j<=input.size()-1; j++)
     { 
      count=Zero(zero_int);
//      cout << "count= \n";
//      cout << count << " \n";
      
      
      for(i=0; i<=K-1; i++)         
          temp_norm[i][j] = euclid_norm(RealClusters[i].center, input[j]);
      dummy = temp_norm[0][j];
      
      for(i=1; i<=K-1; i++) 
         {
          if(temp_norm[i][j]<dummy)
            {
              dummy=temp_norm[i][j];
              count = i;
            };
         };

      RealClusters[count].push_cluster_points(input[j]);
       
      };

/* for(i=0; i<=K-1; i++)
   {    
    cout << " ----------------------- \n";
    cout << "  RealClusters[ " << i << "].cluster_points \n ";
    cout <<  RealClusters[i].cluster_points;
    cout << " ----------------------- \n";
   };
*/


while ( indicator!=1 && number_of_iterations<=100 )
     {

// Creating  copy of previously calculated centers to make possible comparison 
     
     for(i=0; i<=K-1; i++)
	  copy(RealClusters[i].center.begin(), RealClusters[i].center.end(), OldCenters[i].begin());

for(i=0; i<=K-1; i++)
     calculate_new_center(RealClusters[i].center, RealClusters[i].cluster_points);
 
// Erasing old cluster points
   
   for(i=0; i<=K-1; i++)
      RealClusters[i].erase_cluster_points();

// Computing matrix of norms for centers and input points 

 for (i=0;i<=K-1;i++)
   for(j=0;j<=input.size()-1;j++)
       temp_norm[i][j]=euclid_norm(RealClusters[i].center, input[j]);

// Initializing sample norm ( first set it to maximum )

 for (i=0;i<=K-1;i++)
     sample_norm[i]=*max_element(temp_norm[i].begin(), temp_norm[i].end());

// Subsequent partitioning to clusters
  
  for(j=0; j<=input.size()-1; j++)
     { 
      count=Zero(zero_int);
      
      for(i=0; i<=K-1; i++)         
          temp_norm[i][j] = euclid_norm(RealClusters[i].center, input[j]);
      dummy = temp_norm[0][j];
      
      for(i=1; i<=K-1; i++) 
         {
          if(temp_norm[i][j]<dummy)
            {
              dummy=temp_norm[i][j];
              count = i;
            };
         };

      RealClusters[count].push_cluster_points(input[j]);
       
      };

  indicator=compare_centers(RealClusters, OldCenters);
  number_of_iterations++;
 
   };

    cout << " ------------------------- \n";
    cout << " number of iterations made by method  " << number_of_iterations << " \n";
    cout << " ------------------------- \n";
    
 for(i=0; i<=K-1; i++)
   {
    cout << "  Clusters number " << i << " \n";
    cout << " ------------------------- \n";
    cout << " it's points (as rows) " << " \n";
    cout << " ------------------------- \n";
    cout << RealClusters[i].cluster_points;
    cout << " ------------------------- \n";
   };

  };
    
 };





















