/**
 * @file
 * @author  <josemaria.martinezo@ehu.es>
 * @version 1.0
 *
 * @section DESCRIPTION
 * 
 * @brief Collection of functions to be used in MatrixToGraph
 * 
 */

#include <Utils.hpp>
#include <boost/graph/graphviz.hpp>

using namespace std;

/** 
 * @brief Transforms an AttributeMatrix into an AdjacencyMatrix
 * @param attributeMatrix AttributeMatrix to be converted into an AdjacencyMatrix
 * @return AdjacencyMatrix created from the attributeMatrix parameter
 */
AdjacencyMatrix Utils::AttributeMatrixToAdjacencyMatrix(AttributeMatrix attributeMatrix)
{
	AdjacencyMatrix adjacencyMatrix;
	return adjacencyMatrix;
}

AdjacencyMatrix Utils::CSVToAdjacencyMatrix(std::string filename)
{
	AdjacencyMatrix adjacencyMatrix;
	// Opens the log file (input) and new records file (output). 
	std::ifstream input_stream (filename.c_str());
	std::string line_from_file;
	size_t count = 0;
	while (input_stream.good ())
  {
		count++;
	  std::getline (input_stream, line_from_file);	
	  if (line_from_file.length() == 0) continue; 
	  // fields are delimited by "," and " "
	  std::vector<std::string> line_elements = Utils::tokenize_string(line_from_file, ", ");
	  if (count == 1) // this is the head, the name of the nodes
	  {
			adjacencyMatrix.Head = line_elements;
		}
		else 
		{
			line_elements.erase(line_elements.begin()); // the first element is the node name
			adjacencyMatrix.Body.push_back(Utils::from_strings_to_ints(line_elements));
		}
	}
	return adjacencyMatrix;
}

template <class Name>
class my_label_writer 
{
  public:
    my_label_writer(Name _name) : name(_name) {}
    template <class Edge>
    void operator()(std::ostream& out, const Edge& v) const {
      out << "[label=\"" << name[v] << "\"]";
    }
  private:
    Name name;
};


template <class Name>
class my_edge_writer 
{
  public:
    my_edge_writer(Name _name) : name(_name) {}
    template <class Edge>
    void operator()(std::ostream& out, const Edge& v) const {
      out << "[label=\"" << name[v][v] << "\"]";
    }
  private:
    Name name;
};

template <class WeightMap,class CapacityMap>
class edge_writer {
public:
  edge_writer(WeightMap w, CapacityMap c) : wm(w),cm(c) {}
  template <class Edge>
  void operator()(ostream &out, const Edge& e) const {
    out << "[label=\"" << wm[e] << "\", penwidth=\"" << cm[e] << "\",";
    out << "style=filled, color=\"red\"]";
  }
private:
  WeightMap wm;
  CapacityMap cm;
};

template <class WeightMap, class CapacityMap>
inline edge_writer<WeightMap,CapacityMap> 
make_edge_writer(WeightMap w,CapacityMap c) {
  return edge_writer<WeightMap,CapacityMap>(w,c);
}

void Utils::AdjacencyMatrixToGraphviz(AdjacencyMatrix adjacencyMatrix, std::string filename)
{
	std::ofstream output_stream;
  output_stream.open(filename.c_str());
  size_t n_vertex = adjacencyMatrix.Head.size();
  
 struct vert{
   std::string name;
 };

 struct edge{
   int capacity;
   int weight;
 }; 

  typedef pair<int,int> Edge;

  using namespace boost;
  
  typedef adjacency_list<listS, vecS, undirectedS, vert, edge> Graph;
	Graph g;

    for (size_t i = 0; i < n_vertex; i++)
			for (size_t j = i + 1; j < n_vertex; j++)
				{
					auto matrix = adjacencyMatrix.Body;
					if (matrix[i][j] != 0)
					{
						edge prop;
						prop.weight = matrix[i][j];
						prop.capacity = matrix[i][j];
						add_edge(i, j, prop, g);
					}
				}
				
	write_graphviz(output_stream, g, 
  my_label_writer<AdjacencyMatrixHead>(adjacencyMatrix.Head),
  make_edge_writer(boost::get(&edge::weight,g),boost::get(&edge::capacity,g)));

  output_stream.close();
}

std::vector<std::string> Utils::tokenize_string(std::string s, std::string delimiters)
{
	std::vector<std::string> result;
	// Constructs <code>boost::char_separator<char></code> from 'delimiters'
	boost::char_separator<char> sep(delimiters.c_str());
	// Performs the tokenization using boost libraries
	boost::tokenizer<boost::char_separator<char> > tokens(s, sep);
	// Extracts all the tokens and stores them in a <code>std::vector<std::string></code> structure
	for ( auto it = tokens.begin(); it != tokens.end(); ++it) { result.push_back(*it); }
	return result;
}

std::vector<int> Utils::from_strings_to_ints(std::vector<std::string> v_strings)
{
	std::vector<int> v_ints;
	for ( auto it = v_strings.begin(); it != v_strings.end(); ++it) 
	{ 
		v_ints.push_back(atoi((*it).c_str())); 
	}
	return v_ints;
}
