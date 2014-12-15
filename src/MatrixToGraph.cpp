#include <Utils.hpp>

/** @mainpage MatrixToGraph
 * 
 * Utility to create a graph from a matrix.
 * 
*/

int main (int argc, char** argv)
{
	AttributeMatrix attributeMatrix;
	AdjacencyMatrix adjacencyMatrix;
	
	// read the matrix from a CSV file
	adjacencyMatrix = Utils::CSVToAdjacencyMatrix(argv[1]);

	// write AdjacencyMatrix to Graphviz format
	Utils::AdjacencyMatrixToGraphviz(adjacencyMatrix, argv[2]);

	return 0;
}
