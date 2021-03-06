#ifndef NN_H
#define NN_H

#include "Matrix.h"
#include <string>

namespace Metagross {
	class NeuralNet {
		protected:
			Matrix* theta;
			Matrix* net;
			Matrix* Delta;
			int layers;
			int m;
			double alpha;
			double lambda;
			
			
		public:
			//Constructors
			NeuralNet();
			NeuralNet(std::string file);
			NeuralNet(int layers, int* nodeAmt);
			
			//Destructor
			~NeuralNet();
			
			//Modifier functions
			void forwardPropigate(Matrix X);
			void backPropigate(Matrix y);
			void updateGradient();
			void train(Matrix X, Matrix y);
			
			//Other functions
			void print();
			void save();
			void save(std::string file);
			double cost(Matrix X, Matrix y, int m);
			Matrix predict(Matrix X);
			
	};
}
#endif /*NN_H*/