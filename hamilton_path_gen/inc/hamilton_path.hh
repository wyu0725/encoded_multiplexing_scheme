#ifndef hamilton_path_hh
#define hamilton_path_hh 1

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class hamilton_path
{
public:
	hamilton_path(int n, int graph_type);
	~hamilton_path();
	void show();
	vector<vector<int>> vertices;
private:
	int v_cp(int n, int k, int i);
	vector<int> _vertices;
	int modulo(int value, unsigned m);
	// Constrcut hamilton path for complete graph
	void conplete_graph_construct(int n);
	void path_construct_cg(int n, int k);
	void bipatite_graph_constrcut(int n, int m);
	void path_construct_bg(int n, int m, int k);

	vector<int> cp_hamilton_index_gen(int n);
};
#endif // !hamilton_path_hh
