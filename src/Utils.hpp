#ifndef __Utils__   
#define __Utils__ 

/**
 * @file
 * @author  <josemaria.martinezo@ehu.es>
 * @version 1.0
 *
 * @section DESCRIPTION
 * 
 * @brief Collection of functions to be used in MatrixToGraph
 * 
 * 
 */
 
#include <GeneralDefinitions.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>

using namespace std;

/** @class Utils
 * @brief Collection of functions to be used in MatrixToGraph. 
 */

class Utils 
{
	public:

	static AdjacencyMatrix AttributeMatrixToAdjacencyMatrix(AttributeMatrix attributeMatrix);
	static AdjacencyMatrix CSVToAdjacencyMatrix(std::string filename);
	static void AdjacencyMatrixToGraphviz(AdjacencyMatrix adjacencyMatrix, std::string filename);
	static std::vector<std::string> tokenize_string(std::string s, std::string delimiters);
  static std::vector<int> from_strings_to_ints(std::vector<std::string> v_strings);
};

#endif 
