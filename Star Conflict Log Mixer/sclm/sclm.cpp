#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
//h
using namespace std;
int main()
{
	cout << "Star Conflict Log Mixer.\n";
	cout << "v 0.01a  12/5/2019\nby ComwpODG\n\n";


	string filename;
	string outf;
	cout << "File#1 name: ";
	cin >> filename;
	ifstream infile1(filename);
	cout << "\nFile#2 name: ";
	cin >> filename;
	ifstream infile2(filename);
	cout << "\nOutput file name: ";
	cin >> outf;
	ofstream outfile(outf);



	cout << "\nProcessing... This may take up to a minute depending on the log size...\n";
	string in1cur, in2cur;
	getline(infile1, in1cur);
	getline(infile2, in2cur);
	getline(infile1, in1cur);
	getline(infile2, in2cur);
	if (in1cur != in2cur)
	{
		cout << "These logs are from different times or players, the log has been modified previously, or at least one of these is not a star conflict log.\n";
	}
	getline(infile1, in1cur);
	getline(infile2, in2cur);
	getline(infile1, in1cur);
	getline(infile2, in2cur);

	//cout << in1cur.substr(0, 2) << in1cur.substr(3, 2) << in1cur.substr(6, 2) << in1cur.substr(9, 3);
	while (!infile1.eof()&&!infile2.eof())
	{
		if (stoi(in1cur.substr(0, 2)) == stoi(in2cur.substr(0, 2)))
		{
			if (stoi(in1cur.substr(3, 2)) == stoi(in2cur.substr(3, 2)))
			{
				if (stoi(in1cur.substr(6, 2)) == stoi(in2cur.substr(6, 2)))
				{
					if (stoi(in1cur.substr(9, 3)) <= stoi(in2cur.substr(9, 3)))
					{
						outfile << in1cur;
						getline(infile1, in1cur);
					}
					else
					{
						outfile << in2cur;
						getline(infile2, in2cur);
					}
				}
				else
				{
					if (stoi(in1cur.substr(6, 2)) <= stoi(in2cur.substr(6, 2)))
					{
						outfile << in1cur;
						getline(infile1, in1cur);
					}
					else
					{
						outfile << in2cur;
						getline(infile2, in2cur);
					}
				}
			}
			else
			{
				if(stoi(in1cur.substr(3, 2)) <= stoi(in2cur.substr(3, 2)))
				{
					outfile << in1cur;
					getline(infile1, in1cur);
				}
				else
				{
					outfile << in2cur;
					getline(infile2, in2cur);
				}
			}
		}
		else 
		{
			if (stoi(in1cur.substr(0, 2)) <= stoi(in2cur.substr(0, 2)))
			{
				outfile << in1cur;
				getline(infile1, in1cur);
			}
			else
			{
				outfile << in2cur;
				getline(infile2, in2cur);
			}
		}
		outfile << "\n";
	}




	cout << "Success!\nThank you for using ComwpODG's log mixer.\n";

	//outfile << "###### This file was generated by ComwpODG's Log Mixer v 0.01a ######\n\n";
	system("pause");
}