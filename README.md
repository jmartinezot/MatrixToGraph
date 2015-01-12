MatrixToGraph
=============

The utility **MatrixToGraph** creates a graph from an adjacency matrix with associated weights.

Maybe you need to install *cmake*, *boost* and/or *gnuplot*. If so, type

**sudo apt-get install cmake libboost-all-dev gnuplot**

To compile the utility in a Ubuntu system, just go to the MatrixToGraph directory and type

**cmake .**  
**make**

The usage is 

**./MatrixToGraph --CSV_filename=filename.csv --Graphviz_filename=filename.graph**

Once the file **filename.graph** has been generated, several graph types can be created.

- *Dot graph*: **dot -Tpdf filename.graph -o filename.pdf**
- *Circo graph*: **circo -Tpdf filename.graph -o filename.pdf**
- *Neato graph*: **neato -Tpdf filename.graph -o filename.pdf**
- *Twopi graph*: **twopi -Tpdf filename.graph -o filename.pdf**

The above commands create graphs in PDF format. Other formats are possible. For example, **dot -Tps filename.graph -o filename.ps** would create a graph in PS format.




