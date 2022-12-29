class BaseLayer;
class Input2D;
class ReLU;

using namespace std;
class MaxPooling2D :public BaseLayer
{
public:
	MaxPooling2D(int pool_size,ReLU *previous_layer,int stride);
	void max_pooling(Input2D input2D);
private:
	int pool_size, stride;
	ReLU *previous_layer;
};

