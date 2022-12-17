#pragma once
class CNN {
	public:
		vector<vector<float>> conv_(vector<vector<float>> img, vector<vector<float>> conv_filter);
		vector<vector<vector<float>>> relu(vector<vector<vector<float>>> feature_map);
		vector<vector<vector<float>>> conv(vector<vector<float>> img, vector<vector<vector<float>>> conv_filter);
		vector<vector<vector<float>>> conv(vector<vector<vector<float>>> img, vector<vector<vector<vector<float>>>> conv_filter);

		vector<vector<vector<float>>> pooling(vector<vector<vector<float>>> feature_map, int size, int stride);
		
		void setL1_filter(vector<vector<vector<float>>> value);
		vector<vector<vector<float>>> getL1_filter();
		void setL1_feature_map(vector<vector<vector<float>>> value);
		vector<vector<vector<float>>> getL1_feature_map();
		void setL1_feature_map_relu(vector<vector<vector<float>>> value);
		vector<vector<vector<float>>> getL1_feature_map_relu();
		void setL1_feature_map_relu_pool(vector<vector<vector<float>>> value);
		vector<vector<vector<float>>> getL1_feature_map_relu_pool();

		void setL2_filter(vector<vector<vector<vector<float>>>> value);
		vector<vector<vector<vector<float>>>> getL2_filter();
		void setL2_feature_map(vector<vector<vector<float>>> value);
		vector<vector<vector<float>>> getL2_feature_map();
		void setL2_feature_map_relu(vector<vector<vector<float>>> value);
		vector<vector<vector<float>>> getL2_feature_map_relu();
		void setL2_feature_map_relu_pool(vector<vector<vector<float>>> value);
		vector<vector<vector<float>>> getL2_feature_map_relu_pool();

		void setL3_filter(vector<vector<vector<vector<float>>>> value);
		vector<vector<vector<vector<float>>>> getL3_filter();
		void setL3_feature_map(vector<vector<vector<float>>> value);
		vector<vector<vector<float>>> getL3_feature_map();
		void setL3_feature_map_relu(vector<vector<vector<float>>> value);
		vector<vector<vector<float>>> getL3_feature_map_relu();
		void setL3_feature_map_relu_pool(vector<vector<vector<float>>> value);
		vector<vector<vector<float>>> getL3_feature_map_relu_pool();

private:
		vector<vector<vector<float>>> l1_filter;
		vector<vector<vector<float>>> l1_feature_map;
		vector<vector<vector<float>>> l1_feature_map_relu;
		vector<vector<vector<float>>> l1_feature_map_relu_pool;

		vector<vector<vector<vector<float>>>> l2_filter;
		vector<vector<vector<float>>> l2_feature_map;
		vector<vector<vector<float>>> l2_feature_map_relu;
		vector<vector<vector<float>>> l2_feature_map_relu_pool;

		vector<vector<vector<vector<float>>>> l3_filter;
		vector<vector<vector<float>>> l3_feature_map;
		vector<vector<vector<float>>> l3_feature_map_relu;
		vector<vector<vector<float>>> l3_feature_map_relu_pool;
};