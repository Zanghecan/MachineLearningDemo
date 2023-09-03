#pragma once

#include <vector>
#include <random>
#include <assert.h>

typedef std::vector<double> datapoint;

class KmeansPP
{	

public:

	
	KmeansPP(const std::vector<datapoint> &input_data);
	
	~KmeansPP(void);

	
	std::vector<std::vector<int> > RunKMeansPP(int K, std::vector<datapoint> &centroids);

	
private:
	
	
	std::vector<datapoint> input_data;

	std::vector<int> nearest_cluster_idx;
	std::vector<double> nearest_cluster_dist;
	std::vector<datapoint>initial_centroids_;
	std::vector<datapoint> cur_centroids_ ;
	std::vector<datapoint> prev_centroids_;

	
    std::random_device rd;
	std::default_random_engine random_engine;
	std::uniform_int_distribution<int> random_index_gen;
	std::uniform_real_distribution<double> random_real_gen;


	void init();
	void updateNearestClusters(const std::vector<datapoint> &centroids_);
	void updateCentroids(const std::vector<datapoint> &centroids_);
	int getNextInitialCentroidIndex();
	int getClosestCentroidIndex(int data_point_idx, const std::vector<datapoint> &centroids_);
	double distance(const datapoint &a , const datapoint &b);
	bool equalCentroids(const std::vector<datapoint> &a , const std::vector<datapoint> &b);
	datapoint getMeanCentroid(const std::vector<datapoint> &centroids_);

};
