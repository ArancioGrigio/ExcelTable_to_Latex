#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool tableTex(std::string filename);
const vector<string> explode(const string& s, const char& c);
int main(int argc, char** argv){
	if(argc != 5){
		cout << "Sintassi: " << endl << "./txtToTex filename.txt num_cols titolo label" << endl;
	}
	
	string filename = argv[1];
	int col_num = atoi(argv[2]);
	string titolo = argv[3];
	string label = argv[4];
	
	cout << "\\begin{table}[h!]" << endl;
    cout << "\t" << "\\centering" << endl;
    cout << "\t" << "\\caption{" << titolo << "}" << endl;
    cout << "\t" << "\\begin{tabular}{|";
    for(int i = 0; i < col_num; i++)
		cout << "c|";
    cout << "}" << endl;
    cout << "\t" << "\\hline" << endl;
	tableTex(filename);
	cout << "\t\\end{tabular}" << endl;
    cout << "\t\\label{tab:" << label << "}" << endl;
	cout << "\\end{table}" << endl << endl;
}


const vector<string> explode(const string& s, const char& c)
{
	string buff{""};
	vector<string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}


/* Legge una lista di quaterne di dati da un txt e li mette in valVec1 e sigmaVec1; e valVec2 e sigmaVec2 */
bool tableTex(std::string filename){
	
	
	
	
	/* Lettura file */
	string line = "";
	std::fstream InFile;
	InFile.open(filename, std::ios::in);
	if(InFile.good()){	//Verifica l'integrità del file da leggere
	while(getline(InFile, line)){
		vector<string> entries;
		entries = explode(line, ' ');
		int i;
		
		cout << "\t";
		for(i = 0; i < entries.size() - 1; i++)
			cout << entries[i] << " & ";
		cout << entries[i] << " \\" << "\\" << endl;
		cout << "\t" << "\\hline" << endl;
		/* Verifica se il valore SELEZIONATO è quello che indica la fine del file */
		if(InFile.eof())
			break;
	}
	}
	else{
		return false;
	}
	
	InFile.close();
	return true;
}
