#include <Utils.hpp>

/** @mainpage MatrixToGraph
 * 
 * Utility to create a graph from a matrix.
 * 
*/

int main (int argc, char** argv)
{
	AttributeMatrix attributeMatrix;
	AdjacencyMatrix adjacencyMatrix = Utils::AttributeMatrixToAdjacencyMatrix(attributeMatrix);
	return 0;
}
