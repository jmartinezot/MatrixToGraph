#include <Utils.hpp>
#include <boost/program_options.hpp>

/** @mainpage MatrixToGraph
 * 
 * Utility to create a graph from a matrix.
 * 
*/

using namespace std;
namespace po = boost::program_options;

int main (int argc, char** argv)
{
	AttributeMatrix attributeMatrix;
	AdjacencyMatrix adjacencyMatrix;
	
	std::string CSV_filename, Graphviz_filename;
	
   try {
	  // Parses the command line options.
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce help message")
            ("CSV_filename", po::value<std::string>(), "set the name of the CSV file which contains the matrix")
            ("Graphviz_filename", po::value<std::string>(), "set the name of the file containing the graph")
        ;

        po::variables_map vm;        
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);    

        if (vm.count("help")) {
            cout << desc << "\n";
            return 0;
        }
        
        if (vm.count("CSV_filename"))
			CSV_filename = vm["CSV_filename"].as<std::string>();
		else
			{
				cout << "CSV file name missing" << endl;
				cout << desc << endl;
				return 0;
			}    
        if (vm.count("Graphviz_filename"))
			Graphviz_filename = vm["Graphviz_filename"].as<std::string>();
		else
			{
				cout << "Graphviz filename missing" << endl;
				cout << desc << endl;
				return 0;
			}
    }
    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }

	
	// read the matrix from a CSV file
	adjacencyMatrix = Utils::CSVToAdjacencyMatrix(CSV_filename);

	// write AdjacencyMatrix to Graphviz format
	Utils::AdjacencyMatrixToGraphviz(adjacencyMatrix, Graphviz_filename);

	return 0;
}
