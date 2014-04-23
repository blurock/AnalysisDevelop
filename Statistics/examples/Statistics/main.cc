/*  FILE     
**  PACKAGE     REACTION    
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    
**
**  REFERENCES
**
**  COPYRIGHT (C) 1995  REACTION Project / Edward S. Blurock 
*/
 
#define TEMPLATE_INSTANTIATION
#include "Basis/System.hh"
#include "Basis/Matrix.hh"
#include "Basis/String.hh"
#include "Basis/Statistics.hh"

static double ReadVectorElem(int i);
static double ReadMatrixElem(int i, int j);
static Matrix<double> ReadInMatrix(istream& in);
static vector<double> ReadInVector(istream& in);
static void ReadAndTranspose();



static void eigenvaluetest();

static void leastsquarestest();
static void clustertest();

 
/*F main
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
main (int argc, char *argv[])
    {
      /*
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "Matrix Transpose Test\n";
    ReadAndTranspose();
    */    
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "EigenValue and EigenVector Test\n";
    eigenvaluetest();
    
    /*
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "Least Squares Test\n";
    leastsquarestest();
    */
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "Cluster Test\n";
    clustertest();

    return 0;
    }
 

 
/*f ReadAndTranspose()
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
static void ReadAndTranspose()
{
  ifstream myin1("infile");
  if(!myin1) 
    {
      cout <<  "Cannot open file 2\n";
    };
  
  cout << " ----------------------------\n ";
  cout << " test for transpose " << " \n";
  Matrix<double> a=ReadInMatrix(myin1);
  
  Matrix<double> tr_a=a.transpose();
  cout << " transposed " << endl;
  cout << tr_a;
  cout << " ----------------------------\n ";
  Matrix<double> res1=tr_a*a;
  cout << " transpose*original " << endl;
  cout << res1;
  cout << " ----------------------------\n ";
  Matrix<double> res2=a*tr_a;
  cout << " original*transpose " << endl;
  cout << res2;
}
 
/*f eigenvaluetest()  . . . . . . . . . . . . . . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
static void eigenvaluetest()
{
  ifstream myin("infile");
  if(!myin) 
    {
      cout <<  "Cannot open file\n";
    }
  else
    {
      Matrix<double> in_mat=ReadInMatrix(myin);
      cout << " after reading matrix " << endl;
      cout << " ----------------------------" << endl;
      unsigned int DIM1=in_mat.size();
      cout << " extern DIM1 = " <<  DIM1 << endl;
      unsigned int DIM2=in_mat[0].size();
      cout << " extern DIM2 = " <<  DIM2 << endl;
      
      cout << " ----------------------------" << endl;
      cout << " test for factor analysis " << endl;
      Matrix<double> out_eigen_mat(DIM2,DIM2);
      double x;
      vector<double> out_eigen_vec(DIM2, Zero(x));
      cout << " after declaring matrix and vector " << endl;
      cout << " ----------------------------" << endl;     
      FindCorrelEigen(in_mat, out_eigen_mat, out_eigen_vec );
      cout << " EigenMatrix " << endl;
      cout << out_eigen_mat;
      cout << "-----------------------------" << endl;
      cout << " EigenVector  " << " \n";
      cout << out_eigen_vec;    
      double level = 10;
      Matrix<double> reduced_in_mat = ReduceInMatrix(in_mat, out_eigen_mat, out_eigen_vec, level);
      cout << " reduced input matrix " << endl;
      cout << reduced_in_mat;
      cout << "-----------------------------" << endl;
    }
}
/*f leastsquarestest()  . . . . . . . . . . . . . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
static void leastsquarestest()
{
  unsigned int N;
  double x;
  
  ifstream myin1("infile2");
  if(!myin1) 
    {
      cout <<  "Cannot open file 2\n";
    };
  cout << " ----------------------------" << endl;
  cout << " test for Least Squares " << endl;
  
  cout << " x_exp " << endl;
  vector<double> x_exp = ReadInVector(myin1);
  cout << " y_exp " << endl;
  vector<double> y_exp = ReadInVector(myin1);
  cout << " sigmas " << endl;
  vector<double> sigmas = ReadInVector(myin1);
  cout << " number of params " << N << endl;
  vector<double> params(N, Zero(x));
  cout << "-----------------------------" << endl;
  
  LeastSquares(x_exp, y_exp, sigmas, params);
  for(unsigned int i=0;i<=params.size()-1;i++)
    cout << " parameter [" << i << "]= " << params[i] << endl;
  cout << "-----------------------------" << endl;
  
}
/*f clustertest() . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
static void clustertest()
{
  cout << "-------------------------\n";
  cout << " test for cluster analysis \n";
  cout << "-------------------------\n";
  
  Cluster<double> ZZZ;
  Matrix<double> CLUSTER_INPUT1(5,2);
  CLUSTER_INPUT1[0][0]=4;
  CLUSTER_INPUT1[0][1]=1;
  CLUSTER_INPUT1[1][0]=2.1;
  CLUSTER_INPUT1[1][1]=1;
  CLUSTER_INPUT1[2][0]=3;
  CLUSTER_INPUT1[2][1]=1;
  CLUSTER_INPUT1[3][0]=3;
  CLUSTER_INPUT1[3][1]=1;
  CLUSTER_INPUT1[4][0]=3;
  CLUSTER_INPUT1[4][1]=1;
  
  Matrix<double> CLUSTER_INPUT(20,2);
  CLUSTER_INPUT[0][0]=0;
  CLUSTER_INPUT[0][1]=0;
  CLUSTER_INPUT[1][0]=1;
  CLUSTER_INPUT[1][1]=0;
  CLUSTER_INPUT[2][0]=0;
  CLUSTER_INPUT[2][1]=1;
  CLUSTER_INPUT[3][0]=1;
  CLUSTER_INPUT[3][1]=1;
  CLUSTER_INPUT[4][0]=2;
  CLUSTER_INPUT[4][1]=1;
  CLUSTER_INPUT[5][0]=1;
  CLUSTER_INPUT[5][1]=2;
  CLUSTER_INPUT[6][0]=2;
  CLUSTER_INPUT[6][1]=2;
  CLUSTER_INPUT[7][0]=3;
  CLUSTER_INPUT[7][1]=2;
  CLUSTER_INPUT[8][0]=6;
  CLUSTER_INPUT[8][1]=6;
  CLUSTER_INPUT[9][0]=7;
  CLUSTER_INPUT[9][1]=6;
  CLUSTER_INPUT[10][0]=8;
  CLUSTER_INPUT[10][1]=6;
  CLUSTER_INPUT[11][0]=6;
  CLUSTER_INPUT[11][1]=7;
  CLUSTER_INPUT[12][0]=7;
  CLUSTER_INPUT[12][1]=7;
  CLUSTER_INPUT[13][0]=8;
  CLUSTER_INPUT[13][1]=7;
  CLUSTER_INPUT[14][0]=9;
  CLUSTER_INPUT[14][1]=7;
  CLUSTER_INPUT[15][0]=7;
  CLUSTER_INPUT[15][1]=8;
  CLUSTER_INPUT[16][0]=8;
  CLUSTER_INPUT[16][1]=8;
  CLUSTER_INPUT[17][0]=9;
  CLUSTER_INPUT[17][1]=8;
  CLUSTER_INPUT[18][0]=8;
  CLUSTER_INPUT[18][1]=9;
  CLUSTER_INPUT[19][0]=9;
  CLUSTER_INPUT[19][1]=9;
  
  
  int K=2;
  ZZZ.K_mean_method(K, CLUSTER_INPUT);
  
  cout << "-------------------------\n";
  cout << ZZZ.euclid_norm(CLUSTER_INPUT[1], CLUSTER_INPUT[2]);
  cout << "-------------------------\n";
}
 
/*f ReadMatrixElem
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
static double ReadMatrixElem(int i, int j)
{
	  double elem;
	  
	  
	  cout << " Input mat_elem " << "[" << i << "]" << "[" << j << "]";
	  cin >> elem; 
	  cout << "\n ";	  
	  return elem;
	  }

static double ReadVectorElem(int i)
	 {
	   double elem;
	   cout << " Input vec_elem " << "[" << i << "]";
           cin >> elem; 
           cout << "\n ";	  
           return elem;
         }
 
/*f ReactionInMatrix
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
static Matrix<double> ReadInMatrix(istream& in)
{
String str1;
String str2;
String word1;
int DIM1, DIM2;
int i, j;
cout << " read in DIM1"  << endl;
 cout << "----------------------------- \n";
 str1.ReadFullLine(in);
 str1.IsolateNextWord(word1, ' ');
 DIM1=word1.ToInteger();
 cout << "this is DIM1 "  << DIM1 << endl;
 cout << "----------------------------- \n";
 cout << " read in DIM2"  << endl;
 cout << "----------------------------- \n";
// str1.IsolateNextWord(word1, ' ');
 DIM2=str1.ToInteger();
 cout << "this is DIM2 "  << DIM2 << endl;
 cout << "----------------------------- \n";
cout << " constructing matrix with DIM1, DIM2 " << endl;
Matrix<double> mat1(DIM1, DIM2);
cout << " checking dimensions of matrix" << endl;
cout << " DIM1=mat1.size()= " << mat1.size() << endl;
cout << "----------------------------- \n";
cout << " DIM2=mat1[0].size()= " << mat1[0].size() << endl;
cout << "----------------------------- \n";
cout << " read in matrix mat1 " << endl;
cout << "----------------------------- \n";
for(i=0;i<DIM1;i++)
  {
   str1.ReadFullLine(in);
   cout << " str1 " << str1 << endl;
   
   for(j=0; j<DIM2-1; j++)
      {
      str1.IsolateNextWord(word1, ' ');
      mat1[i][j]=word1.ToFloat(); 
      };
   mat1[i][j]=str1.ToFloat(); 
  }; 
cout << "----------------------------- \n";
cout << " now print out matrix mat1 " << endl;
cout << mat1;
cout << " end of test" << endl;
return mat1;

}
 
/*f ReadInVector
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
static vector<double> ReadInVector(istream & in)
     {
     int i;
     
     int N;      
     double x;
     
     
     in>>N;
     cout << " dimension N  = " << N << endl; 
     vector<double> temp(N, Zero(x));
     cout << " dimension of constructed vector " << temp.size() << endl;
     
     for(i=0;i<N;i++)
        in>>temp[i];
     cout << " dimension of vector after initiation " << temp.size() << endl;
   
     cout << " ------------------- " << endl;
     
     for(i=0;i<N;i++) 
        cout << "temp[" << i << "]=" << temp[i] << endl;
     
     cout << " ------------------- " << endl;
     return temp;
     
     }
	

