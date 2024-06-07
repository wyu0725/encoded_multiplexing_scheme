// hamiltion_path_gen.cpp : Defines the entry point for the application.
//

#include "hamilton_path_gen.hh"

using namespace std;

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		cout << "\033[31m" << "Parameters are needed !" << "\033[0m" << endl;
		show_info(argv[0]);
		return -1;
	}
	// -G graph type
	//		0: Complete graphy; 1: bipatite graph
	int graph_type = 0;
	// -e number of electronics channels
	int number_of_rd = 64;
	// -m magnification factor
	int multiple_times = 8;
	while ((c = getopt(argc, argv, "G:e:m:")) != EOF)
	{
		switch (c)
		{
		case 'G':
			graph_type = atoi(optarg);
			break;
		case 'e':
			number_of_rd = atoi(optarg);
			break;
		case 'm':
			multiple_times = atoi(optarg);
			break;

		case '?':
			cout << "<<----------\?\?---------->>" << endl;
			cout << "unknow parameters" << endl;
			cout << "<<----------\?\?---------->>" << endl;
			cout << "Or forget break in the last case???" << endl;
			show_info(argv[0]);
			return -1;
			break;
		default:
			break;
		}
	}


	hamilton_path hp = hamilton_path(number_of_rd, graph_type);
	string graph_name = "error";
	if (graph_type == 0)
	{
		graph_name = "complete_graph";
	}
	else
	{
		graph_name = "bipatite_graph";
	}
	string file_name = "encoded_lists_chn_" + graph_name + "_" + to_string(number_of_rd) + ".csv";
	
	ofstream file_out;
	file_out.open(file_name.c_str());
	int chn = 0;
	for (int i = 0; i < hp.vertices.size(); i++)
	{
		for (int j = 0; j < hp.vertices[i].size(); j++)
		{
			file_out << hp.vertices[i][j] << ",";
		}
		file_out << endl;
		for (int j = 0; j < hp.vertices[i].size(); j++)
		{
			file_out << chn << ",";
			chn++;
		}
		file_out << endl;
	}
	file_out.close();

	chn = 0;
	array<vector<int>, 128> asic_det_chn;
	if (argc > 2 && number_of_rd <= 128)
	{	
		for (int i = 0; i < multiple_times; i++)
		{
			for (int j = 0; j < hp.vertices[i].size(); j++)
			{
				asic_det_chn[hp.vertices[i][j]].push_back(chn);
				chn++;
			}
		}
		ofstream asic2det_lists;
		string filename = "asic2det_chn_" + graph_name + "_" + to_string(number_of_rd) + "_line" + to_string(multiple_times) + ".csv";
		asic2det_lists.open(filename.c_str());
		asic2det_lists << "ASIC CHN, DET CHN" << endl;
		for (int i = 0; i < number_of_rd; i++)
		{
			asic2det_lists << i << ",";
			for (int j = 0; j < asic_det_chn[i].size(); j++)
			{
				asic2det_lists << asic_det_chn[i][j] << ",";
			}
			asic2det_lists << endl;
		}
		asic2det_lists.close();
	}
	cout << "Done" << endl;
}

void show_info(char* name)
{
	cout << "\033[34m"  << "Usage: " << endl
		<< name << " -parameter" << endl
		<< " -G [graph type. 0: Complete graph; 1: Bipatite graph] " << endl
		<< " -e [Number of electronics]" << endl
		<< " -m [Multiple times. N_strips = N_electroncis * m]"
		<< "\033[0m"  << endl;
}
