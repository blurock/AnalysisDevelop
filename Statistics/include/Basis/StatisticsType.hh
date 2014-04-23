/*  FILE     StatisticsType.hh
**  PACKAGE  Statistics
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    Class definitions for the "Statistics" package.
**
**  OVERVIEW
**
**  IMPLEMENTATION
**
**  REFERENCES
**
**  COPYRIGHT (C) 1996 STURM Project, RISC Linz
*/
 
#ifndef BASIS_STATISTICSTYPE_HH
#define BASIS_STATISTICSTYPE_HH

/*C ClusterObject<T>  . . . . . . . . .  Container class for cluster objects.
**
**  DESCRIPTION
**    Class ClusterObject<T> contains specific to each
**    cluster data - cluster center and cluster points, 
**    and provide some basic mehtods to handle these data.
** 
**  REMARKS
**
*/
template <class T>
class ClusterObject 
  {
 public:
  
   vector<T> center;
   Matrix<T> cluster_points;
  
   inline   ClusterObject(); 
   inline   ClusterObject(const ClusterObject<T> &x); 

   void set_center( vector<T> x);
   void push_cluster_points(vector<T> x);     
   void erase_cluster_points();         
   void show();
  };

/*C  Cluster<T> . . . . . . . . . . . . . . . . . Cluster related algorithms.
**
**  DESCRIPTION
**    Class Cluster provides some algorithms for 
**    cluster analysis - at present K-mean method
**    and some supplementary routines, which are
**    designed to be used also with other clustering
**    methods.
**     
**  REMARKS
**
*/
template<class T>
class Cluster
{
public:
  Cluster();

  Matrix<T> choose_unique(Matrix<T> mat);
  void calculate_new_center( vector<T>& center, Matrix<T> mat_of_points);
  int compare_centers(vector< ClusterObject<T>  >& actual_clusters, Matrix<T>& mat_old_centers);
  T  euclid_norm( vector<T> Vec1,  vector<T> Vec2);
  
  void K_mean_method(unsigned int K, Matrix<T> input);
};



#endif
