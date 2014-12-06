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

using namespace std;

/** @class Utils
 * @brief Collection of functions to be used in MatrixToGraph. 
 */

class Utils 
{
	public:

	static AdjacencyMatrix AttributeMatrixToAdjacencyMatrix(AttributeMatrix attributeMatrix);

};

#endif 
