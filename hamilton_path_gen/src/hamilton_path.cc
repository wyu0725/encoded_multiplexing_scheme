#include "hamilton_path.hh"

hamilton_path::hamilton_path(int n, int graphy_type)
{
	if (graphy_type == 0)
	{
		conplete_graph_construct(n);
	}
	else if (graphy_type == 1)
	{
		if (n % 4 != 0)
		{
			cout << "Only even number of channels is support" << endl;
			return;
		}
		bipatite_graph_constrcut(n / 2, n / 2);
	}
	else
	{
		cout << "\033[31m" << "Only support complete graph and bipatite graph" << "\033[0m" << endl;
	}
}
hamilton_path::~hamilton_path()
{
}

int hamilton_path::v_cp(int n, int k, int i)
{
	int v_ink;
	if (i <0 || n < 0 || k < 0 || k > n-2)
	{
		cout << "n, k ERROR!!! n: " << n << " k: " << k << endl;
		return -1;
	}
	if (i > _vertices.size())
	{
		cout << "Please construct in sequence" << endl;
		return -1;
	}
	if (i == 0)
	{
		return k;
	}
	if (i % 2 == 1)
	{
		return  modulo((_vertices[i - 1] + i), n - 1);
	}
	return modulo((_vertices[i - 1] - i), n - 1);
}
void hamilton_path::show()
{
	for (int i = 0; i < vertices.size(); i++)
	{
		for (int j = 0; j < vertices[i].size(); j++)
			cout << vertices[i][j] << " ";
		cout << endl;
	}
}
int hamilton_path::modulo(int value, unsigned m)
{
	int mod = value % (int)m;
	if (value < 0) {
		mod += m;
	}
	return mod;
}
void hamilton_path::conplete_graph_construct(int n)
{
	vector<int> hamilton_idx = cp_hamilton_index_gen(n);
	vector<int> single_path;
	for (int k = 0; k <hamilton_idx.size(); k++)
	{		
		single_path.clear();
		if (n % 2 == 1)
		{
			
			path_construct_cg(n, hamilton_idx[k]);
			single_path.push_back(n - 1);
			for (int i = 0; i < n - 1; i++)
			{

				single_path.push_back(_vertices[i]);
			}
		}
		else
		{
			path_construct_cg(n - 1, hamilton_idx[k]);
			single_path.push_back(n - 2);
			int j = 0;
			for (int i = 0; i < n - 1; i++)
			{
				if (i == (n / 2 - 1))
				{
					single_path.push_back(n - 1);
				}
				else
				{
					single_path.push_back(_vertices[j]);
					j++;
				}
			}
		}
		vertices.push_back(single_path);
	}
	
}
void hamilton_path::path_construct_cg(int n, int k)
{
	_vertices.clear();
	for (int i = 0; i < n - 1; i++)
	{
		_vertices.push_back(v_cp(n, k, i));
	}
}

void hamilton_path::bipatite_graph_constrcut(int n, int m)
{
	if (m != n || m % 2 == 1)
	{
		cout << "\033[33m" << "Only construct with even number of vertices " << "\033[0m" << endl;
		return;
	}
	for (int k = 0; k <= n - 2; k += 2)
	{
		path_construct_bg(n, m, k);
		vertices.push_back(_vertices);
	}
}

void hamilton_path::path_construct_bg(int n, int m, int k)
{
	// At present (20220310), m is not used!
	_vertices.clear();
	for (int i = 0; i < n; i++)
	{
		_vertices.push_back(i * 2);
		_vertices.push_back(modulo(2 * k + 2 * i + 1, 2 * n));
	}
	
}

vector<int> hamilton_path::cp_hamilton_index_gen(int n)
{
	int n_calc = (n % 2 == 0) ? (n - 1) : n;
	vector<int> hamilton_idx;
	if (n_calc % 4 == 1)
	{
		for (int k = 0; k <= (n_calc - 5) / 2; k += 2)
		{
			hamilton_idx.push_back(k);
		}
		for (int k = floor((n_calc - 3) / 2); k > 0; k -= 2)
		{
			hamilton_idx.push_back(k);
		}
	}
	else
	{
		for (int k = 0; k <= (n_calc - 3) / 2; k += 2)
		{
			hamilton_idx.push_back(k);
		}
		for (int k = floor((n_calc - 5) / 2); k > 0; k -= 2)
		{
			hamilton_idx.push_back(k);
		}
	}
	return hamilton_idx;
}
