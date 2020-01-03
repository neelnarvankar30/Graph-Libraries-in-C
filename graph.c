// Name: Neel Prasad Narvankar.




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

//The code has the following assumtions:
//The vertex in the matrix is 0 if no node exists
// The vertex is -2 if a vertex is present
// and a value greater that 0 if edge or self-loop.
	



// Initialization Functions
Graph *graph_initialize(){
// allocate memory on the heap for graph. 
int i, j;
Graph *graph = malloc(sizeof(Graph));
if (graph ==  NULL)
{
	return NULL;
}
//initialize max_vertex to -1 this will help the print function know where to print the graph
graph->max_vertex = -1;

for ( i = 0; i < MAX_VERTICES; i++)
{
	for ( j = 0; j < MAX_VERTICES; j++)
	{
		// set all the elements of the matrix to zero as mentioned before
		graph->adj_matrix[i][j] = 0;
	}
}

for ( i = 0; i < MAX_VERTICES; i++)
{
	//initialize visited to 0(will be used in has_path function)
	graph->visited[i] = 0;	
}
// return graph on sucess
return graph;

}

// Vertex Operations
int graph_add_vertex(Graph *graph, int v1){
// check if graph is not NULL.
int i, j;
if (graph == NULL)
{
	return -1;
}
// check if the value is within limits 
if (v1 < 0 || v1>= MAX_VERTICES)
{
	return -1;
}


else
{		//if the value is within limits we check if the vertex already exists
		if (graph->adj_matrix[v1][v1] != 0)
		{
			return 0;
		}


		else
		{		// if it dose not exsits add the vertex to the graph i.e set it to -2.
				graph->adj_matrix[v1][v1] = -2;
				// we now change the max_vertex to print it to the largest vertex
				if (v1 > (graph->max_vertex))
				{
				graph->max_vertex = v1;
				}
				return 0;
		}

}



}



int graph_contains_vertex(Graph *graph, int v1){
int i, j;
if (graph == NULL)
{
	return 0;
}
// check if the vertex exists or it has some weight(self-loop)
if (graph->adj_matrix[v1][v1] == -2|| graph->adj_matrix[v1][v1] > 0)
{
	return 1;
}

else
{
	return 0;
}


}



int graph_remove_vertex(Graph *graph, int v1){
int i, j;
if (graph == NULL)
{
	return -1;
}

// check if the vertex is within limits
if (v1 < 0 || v1 >= MAX_VERTICES)
{
	return -1;
}

else{ // if vertex it dose not exists return 0 
			if (graph->adj_matrix[v1][v1] == 0)
			{
				return 0;
			}

			else{ //remove the vertex and all the associated edges that means out going as well as incoming
					for ( j = 0; j < MAX_VERTICES; j++)
					{
						if (graph->adj_matrix[v1][j] != 0)
						{
							graph->adj_matrix[v1][j] = 0;	
						}

						if (graph->adj_matrix[j][v1] != 0)
						{
							graph->adj_matrix[j][v1] = 0;	
						}
					}
					return 0;
				}
}



return -1;
}

// Edge Operations
int graph_add_edge(Graph *graph, int v1, int v2, int wt){
int i, j;
if (graph == NULL)
{
	return -1;
}
// check if weight is greater than zero. 
if (wt < 0)
{
	return -1;
}
// check if vertices are within limits.  
if (v1 < 0 || v1 >= MAX_VERTICES || v2 < 0 || v2 >= MAX_VERTICES)
{
	return -1;
}
// check if vertex exists
if (graph->adj_matrix[v1][v1] == 0 || graph->adj_matrix[v2][v2] == 0)
{
	return -1;
}


else{ // if some edge with weigth already exisits update the weight
			if (graph->adj_matrix[v1][v2] != 0)
			{
				graph->adj_matrix[v1][v2]	= wt;
				return 0;
			}

			else
			{	// if no edge with weight exists add the edge with the weight.
				if (graph->adj_matrix[v1][v2] == 0)
				{
					graph->adj_matrix[v1][v2] = wt;
					return 0;
				}
			}
}

	return -1; 

}


int graph_contains_edge(Graph *graph, int v1, int v2){
if(graph == NULL || v1 < 0 || v1 >= MAX_VERTICES || v2 < 0 || v2 >= MAX_VERTICES) {
    	return 0;
  	}

  	//check if v1 or v2 exist
  	if(graph->adj_matrix[v1][v1] == 0 || graph->adj_matrix[v2][v2] == 0) {
  		return 0;
  	}

  	//Return 1 on success else 0
  	if(graph->adj_matrix[v1][v2] > 0) {
  		return 1;
  	}
  	else {
  		return 0;
  	}

}



int graph_remove_edge(Graph *graph, int v1, int v2){
if (graph == NULL)
{
	return -1;
}

	
if (v1 < 0 || v1 >= MAX_VERTICES || v2 < 0 || v2 >= MAX_VERTICES)
{
	return -1;
}
// check if vertex exists
if (graph->adj_matrix[v1][v1] == 0 || graph->adj_matrix[v2][v2] == 0)
{
	return -1;
}
	
else
{		// if no edge exist between the two return zero
		if (graph->adj_matrix[v1][v2] == 0)
		{
			return 0;
		}

		else
		{	// if the value is greater than zero that means the edge exists, remove it and return 0.
			if (graph->adj_matrix[v1][v2] != 0 && graph->adj_matrix[v1][v2] != -2)
			{
				graph->adj_matrix[v1][v2] = 0;
				return 0;
			}
		}

}

return -1;

}

// Graph Metrics Operations
int graph_num_vertices(Graph *graph){
// set the initial count to zero. 
int i, j;
int count = 0;
if (graph == NULL)
{
	return -1;
}

	for ( i = 0; i < MAX_VERTICES; i++)
	{
		for ( j = 0; j < MAX_VERTICES; j++)
		{
			if (graph->adj_matrix[i][j] == graph->adj_matrix[j][i])
			{ // check the diagonal of the matrix if it is -2 at any of the diagonal vertex increase the count. 
				if (graph->adj_matrix[i][j] == -2)
				{
					count ++ ;
				}
			}
		}
	}

return count;

}



int graph_num_edges(Graph *graph){
int i, j;
int count = 0;

if (graph == NULL)
{
	return -1 ;
}

	for ( i = 0; i < MAX_VERTICES; i++)
	{
		for ( j = 0; j < MAX_VERTICES; j++)
		{ // check each element of the matrix if it is not zero or -2 increase the count and return.
			if (graph->adj_matrix[i][j] != 0 && graph->adj_matrix[i][j] != -2)
			{
				count ++;
			}
		}
	}

return count;

}



int graph_total_weight(Graph *graph){
int i, j;
int weight = 0;

if (graph == NULL)
{
	return -1 ;
}

		for ( i = 0; i < MAX_VERTICES; i++)
	{
		for ( j = 0; j < MAX_VERTICES; j++)
		{ // add the weight of all the elements of the vertex which are not 0 or -2.
			if (graph->adj_matrix[i][j] != 0 && graph->adj_matrix[i][j] != -2)
			{
				weight = weight + graph->adj_matrix[i][j];
			}
		}
	}

return weight;




}

// Vertex Metrics Operations
int graph_get_degree(Graph *graph, int v1){
int i, j;
int degree = 0;

if (graph == NULL)
{
	return -1 ;
}

	
		if (graph->adj_matrix[v1][v1] != 0 && graph->adj_matrix[v1][v1] != -2)
		{ // check for a self-loop , if yes add 2 to the degree.
			degree = degree + 2; 
		}

		for ( j = 0; j < MAX_VERTICES; j++)
		{
			if (graph->adj_matrix[v1][j] != 0 && graph->adj_matrix[v1][j] != -2 && v1 != j)
			{ // travers the row of vertex if edge exists add one
				degree++ ;
			}
		}
	
		for ( i = 0; i < MAX_VERTICES; i++)
		{
			if (graph->adj_matrix[i][v1] != 0 && graph->adj_matrix[i][v1] != -2 && i != v1)
			{ // traverse all the columns to see incoming edges if yes increase degree.
				degree++ ;
			}
		}


return degree;

}


int graph_get_edge_weight(Graph *graph, int v1, int v2){

if (graph == NULL)
{
	return -1 ;
}

if (graph->adj_matrix[v1][v1] == 0 || graph->adj_matrix[v2][v2] == 0)
{
	return -1;
}

else
{                 //check if edge exists if not return -1
				if (graph->adj_matrix[v1][v2] == 0)
				{
					return -1;
				}

				else // if edge exists the return the edge weight.
				{
					return graph->adj_matrix[v1][v2];
				}


}


}



int graph_is_neighbor(Graph *graph, int v1, int v2){

if (graph == NULL)
{
	return 0 ;
}
// check if both the vertices exist
if (graph->adj_matrix[v1][v1] == 0 || graph->adj_matrix[v2][v2] == 0)
{
	return 0;
}


else
{ // go to the vertex and see if either has an edge to other if yes return 1. 
if ((graph->adj_matrix[v1][v2] != 0  && graph->adj_matrix[v1][v2] != -2) || (graph->adj_matrix[v2][v1] != 0 && graph->adj_matrix[v2][v1] != -2))
			{
				return 1;
			}
else
{
	return 0;
}

}

}


int *graph_get_predecessors(Graph *graph, int v1){
int i;
if(!graph_contains_vertex(graph, v1)) {
		return NULL;
	}
	else {

		int count = 0;
		// set count to zero which will be used to allocate memory dynamicly  
		for( i = 0; i <= graph->max_vertex; i++) {

			if(graph_contains_edge(graph, i, v1)) {
				count++; 
			}
		}
			// allocate memory on heap and no. of blocks from count. 
		int *arr = malloc(sizeof(int) * (count+1));
		int j = 0;

		for( i = 0; i <= graph->max_vertex; i++) {
				// check in loop if the there is an edge from that all the verices to the vertex we want. 
			if(graph_contains_edge(graph, i, v1)) {
				// if such condition exists then add the element in the dynamic ary. 
				arr[j] = i;
				j++; 
			}
		}
 // set the last element of ary to -1 so we know when to stop. 
		arr[j] = -1;

		return arr;
	}

	
}




int *graph_get_successors(Graph *graph, int v1){
int i;
if(!graph_contains_vertex(graph, v1)) {
		return NULL;
	}
	else {

		int count = 0;
// set count to zero which will be used to allocate memory dynamicly 
		for( i = 0; i <= graph->max_vertex; i++) {

			if(graph_contains_edge(graph, v1, i)) {
				count++; 
			}
		}
// allocate memory on heap and no. of blocks from count. 
		int *arr = malloc(sizeof(int) * (count+1));
		int j = 0;

		for( i = 0; i <= graph->max_vertex; i++) {
			// check in loop if the there is an edge from that vertex any of the vertices.
			if(graph_contains_edge(graph, v1, i)) {
				// if such condition exits then add the element to the ary.
				arr[j] = i;
				j++; 
			}
		}
// set the last element to -1 so we know when to stop.
		arr[j] = -1;

		return arr;
	}
}




// Graph Path Operations
//helper function to set visited of each vertex recursively
void helper(Graph *graph, int v1) {
//set the visited of that vertex to 1.
    int i, j;
    graph->visited[v1] = 1;
	
	for( i = 0; i <= graph->max_vertex; i++) {
//check in loop to see if the vertex exisits and is visited, if not call helper function on that vertex.
       if((graph->adj_matrix[v1][i] > 0) && (graph->visited[i] == 0)) {
           helper(graph, i);
       }
	}
}

int graph_has_path(Graph *graph, int v1, int v2){
int i, j;
if (graph == NULL)
{
	return 0;
}
		

// check if the vertices exists. 
	if(graph->adj_matrix[v1][v1] == 0 || graph->adj_matrix[v2][v2] == 0) {
		return 0;
	}

	else {
			// make all the elements of visited as 0 when they are visited make them 1.
		for( i = 0; i < MAX_VERTICES; i++) { 
    		graph->visited[i] = 0;
    	}
    	//call the helper function to check the visited of that vertex
		helper(graph, v1);
		// check if that visited list as the vertex v2 if yes return 1.
		if(graph->visited[v2]) {
			return 1;
		}

		return 0;
	}


}



// Input/Output Operations
//This function is used to print the graph 
void graph_print(Graph *graph){
int i, j;
if (graph == NULL)
{
	return;
}


printf("\n");
printf("   ");
for ( i = 0; i <= graph->max_vertex; i++)
{
	if (i<10)
	{
		printf("  0%d", i);
	}

	else
	printf("  %d", i);
}

printf("\n");

printf("    ");
for ( i = 0; i <= (graph->max_vertex); ++i)
{
printf("-----");
}

printf("\n");
for ( i = 0; i <= (graph->max_vertex); i++)
{	// traverse each element and print the where there is a value and print "••" where there is zero
	if (i < 10)
	{
	printf("0%d |", i);
	}
	else
	printf("%d |",i);

	for ( j = 0; j <= (graph->max_vertex); j++)
	{
		
		if (graph->adj_matrix[i][j] == 0)
		{
			printf(" •• ");
		}
		else
		{
		printf(" %d ", graph->adj_matrix[i][j] );
		}
	}

	printf("\n");
}



}



void graph_output_dot(Graph *graph, char *filename){
int i, j;
if(graph == NULL || filename == NULL) {
    	return;
  	}
	
	// funtion used to create dot output 
	// open a file with FILE pointer and give write permission 
	FILE *fp = fopen(filename, "w");
	if(fp == NULL) {
		return;
	}

	
	fprintf(fp, "digraph {\n");

	for( i = 0; i <= graph->max_vertex; i++) {
    	for( j = 0; j <= graph->max_vertex; j++) {

    		// traverse the entire graph and check where there is a node or an edge and print the output as given in dot file.
    		if(graph->adj_matrix[i][j] != 0) {

    			if(graph->adj_matrix[i][j] == -2) {
    				fprintf(fp, "%d;\n", i);
    			}
    			else {
    				fprintf(fp, "%d -> %d weight = %d;\n", i, j, graph->adj_matrix[i][j]);
    			}
    		}
    	}
    }

    fprintf(fp, "}\n");

    //Close file
	fclose(fp);




}



int graph_load_file(Graph *graph, char *filename){
//Function used to load a graph from a given file using strtok function. 
int i, j;
if (graph == NULL)
{
	return -1 ;
}

// create a char buffer and a char pointer which will get tokens from strtok
char buffer[20];
char *str = NULL;
// open a file using fopen and read permission.
FILE *fp = fopen(filename, "r");                 
  if(fp ==NULL){
    return -1;                                     
  }

// read from the file until we reach end of file. 
  while(feof(fp)==0)
  {
  	fgets(buffer,20, fp);
int v1;
int v2;
int wt;
// use strtok to get each token from the file and point it with str pointer, check the conditions if it is just the node or an edge between two nodes.
  str = strtok(buffer, ",");
  
  if (str != NULL)
  {
  	// use sscanf and store the token into values v1, v2 or v3 and pass it to the respected functions.
  sscanf(str, "%d", &v1);
  graph_add_vertex(graph, v1);	
  } 
  
  str =  strtok(NULL, ",");
  
  if (str != NULL)
  {
  sscanf(str, "%d", &v2);
  graph_add_vertex(graph , v2);
  }


  str = strtok(NULL, ",");

  if (str != NULL)
  {
  sscanf(str, "%d", &wt);
  graph_add_edge(graph ,v1, v2, wt);
  }

  }


 return 0;
}



int graph_save_file(Graph *graph, char *filename){
// funtion used to save a graph to a file
// open file using fopen and with w permission
int i, j;
FILE *fp = fopen(filename, "w");

if (fp == NULL)
{
	return -1;
}

for ( i = 0; i <= (graph->max_vertex); i++)
{
	for ( j = 0; j <= (graph->max_vertex); j++)
	{ // travrese recursively and wirte the vertex into the file 
		if (graph->adj_matrix[i][j] == -2)
		{
			fprintf(fp, "%d\n",i);
		}

		else
		{ // if not a vertex write the vertices and the edge weight. 
			if (graph->adj_matrix[i][j]!= 0 && graph->adj_matrix[i][j] != -2)
			{
				fprintf(fp, "%d,%d,%d\n",i,j,graph->adj_matrix[i][j]);
			}
		}
	}
}
// close file. 
fclose(fp);
return 0;

}



