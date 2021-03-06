#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

using namespace std;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
    * Calculate the RMSE here.
  */
    VectorXd rmse = VectorXd(4);
    rmse << 0,0,0,0;

    if(estimations.size() !=ground_truth.size() ||
    	estimations.size()==0){
    	cout << "Invalid estimation or ground_truth data" << endl;
    	return rmse;

    }

    // accumulate squared residuals
    for(unsigned int i = 0; i<estimations.size(); i++){
    	VectorXd residual = estimations[i] - ground_truth[i];

    	// coefficient wise multiplication
    	residual = residual.array()*residual.array();
    	rmse += residual;

    }

    // calculate the mean
    rmse /= estimations.size();

    // squared root
    rmse = rmse.array().sqrt();

    // return
    return rmse;

}