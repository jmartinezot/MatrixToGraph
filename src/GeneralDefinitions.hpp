#ifndef __GeneralDefinitions__   
#define __GeneralDefinitions__

#include <vector>
#include <string>

typedef std::vector<std::vector<int> > AttributeMatrixBody;
typedef std::vector<std::vector<int> > AdjacencyMatrixBody;
typedef std::vector<std::string> AttributeMatrixHead;
typedef std::vector<std::string> AdjacencyMatrixHead;

class AttributeMatrix
{
	public:
	
	AttributeMatrixHead Head;
	AttributeMatrixBody Body;
};

class AdjacencyMatrix
{
	public:
	
	AdjacencyMatrixHead Head;
	AdjacencyMatrixBody Body;
};

#endif 
