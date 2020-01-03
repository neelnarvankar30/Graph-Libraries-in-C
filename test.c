#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main() {

	Graph *g = graph_initialize();
	int *arr = NULL;
	
	if(g == NULL) {
		printf("Error in initializing graph. Exiting...\n");
		return 0;
	}
	printf("Graph Initialized.\n");

	int opt = -1, x = -1, y = -1, w = -1;
	char buffer[10];

	do {

		printf(".-----------------------------------------.\n");
		printf("| Operations                              |\n");
		printf("+---------+-------------------------------+\n");
		printf("| 1 X     | Add Vertex X                  |\n");
		printf("| 2 X Y W | Add Edge X->Y with Weight W   |\n");
		printf("| 3 X Y   | Remove Edge X->Y              |\n");
		printf("| 4 X     | Remove Vertex (and Edges)     |\n");
		printf("| 5 X     | Contains Vertex (Does Exist?) |\n");
		printf("| 6       | Num of Vertices in Graph      |\n");
		printf("| 7       | Num of Edges in Graph         |\n");
		printf("| 8 X     | Degree of Vertex X            |\n");
		printf("| 9       | Total Weight of Graph         |\n");
		printf("|10 X     | Successors of X               |\n");
		printf("|11 X     | Predecessors of X             |\n");
		printf("|12 X Y   | Is X a neighbour of Y?        |\n");
		printf("|13 X Y   | Edge Weight of (X->Y)         |\n");
		printf("|14       | Output Adj List to file       |\n");
		printf("|15 X Y   | Is there a path from X to Y?  |\n"); 
		printf("|16       | Load Graph from file          |\n");
		printf("|17       | Print current Graph           |\n");
		printf("|18       | Save Graph to file            |\n");
		printf("|19 X     | Contains EDGE (Does Exist?)   |\n");
		printf("+---------+-------------------------------+\n");
		printf("|-1       | Quit                          |\n");
		printf(".-----------------------------------------.\n");
		printf("> ");

		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, "%d" "%d" "%d" "%d", &opt, &x, &y, &w);
		int flag;
		switch(opt) {

			case -1:
				printf("\nValues: opt = %d, x = %d, y = %d, w = %d\n", opt, x, y, w);
				printf("Exiting... Thank you.\n");
			break;

			case 1:
				printf("\nValues: opt = %d, x = %d", opt, x);
				flag = graph_add_vertex(g, x);
				if(flag == 0) {
					printf("\nVertex added\n");
					graph_print(g);
				}
				else {
					printf("\nSomething went wrong while adding vertex.");
				}
				printf("\n\n");
			break;

			case 2:
				printf("\nValues: opt = %d, x = %d, y = %d, w = %d\n", opt, x, y, w);

				 flag = graph_add_edge(g, x, y, w);	
				if(flag == 0) {
					printf("\nVertex added\n");
					graph_print(g);
				}
				else {
					printf("\nSomething went wrong while adding edge.");
				}
				printf("\n\n");
				printf("\n");
			break;

			case 3:
				printf("\nValues: opt = %d, x = %d, y = %d\n", opt, x, y);
				flag = graph_remove_edge(g, x, y);
				if(flag == 0) {
					printf("\nEdge removed.");
					graph_print(g);
				}
				else {
					printf("\nError while removing Edge.");
				}
				printf("\n\n");
				printf("\n");
			break;

			case 4:
				printf("\nValues: opt = %d, x = %d\n", opt, x);
				printf("\nValues: opt = %d, x = %d", opt, x);
				flag = graph_remove_vertex(g, x);
				if(flag == 0) {
					printf("\nVertex added\n");
					graph_print(g);
				}
				else {
					printf("\nSomething went wrong while adding vertex.");
				}
				printf("\n\n");
				printf("\n");
			break;

			case 5:
				printf("\nValues: opt = %d, x = %d\n", opt, x);
				flag = graph_contains_vertex(g, x);
				if(flag) {
					printf("\nVertex exists.");
					graph_print(g);
				}
				else {
					printf("\nVertex does not exist.");
				}
				printf("\n\n");
				printf("\n");
			break;

			case 6:
				printf("\nValues: opt = %d\n", opt);
				flag = graph_num_vertices(g);
				if(flag == -1) {
					printf("\nError while counting Vertices.");
				}
				else {
					printf("\nNum of Vertices = %d.", flag);
					graph_print(g);
				}
				printf("\n\n");

				printf("\n");
			break;

			case 7:
				printf("\nValues: opt = %d\n", opt);
				flag = graph_num_edges(g);
				printf("the no. of Edges are %d\n", flag);
				printf("\n");
			break;

			case 8:
				printf("\nValues: opt = %d, x = %d\n", opt, x);
				flag = graph_get_degree(g, x);
				printf("the degree is %d\n", flag);
				printf("\n");
			break;

			case 9:
				printf("\nValues: opt = %d\n", opt);
				flag = graph_total_weight(g);
				printf("the total weight is %d\n", flag);
				printf("\n");
			break;

			case 10:
				
				arr = graph_get_successors(g, x);
				if(arr != NULL) {
					printf("\nSuccessors are: ");

					int i = 0;
					while(arr[i] != -1) {
						printf("%d ", arr[i]);
						i++;
					}

					printf("%d ", arr[i]);

					graph_print(g);
					free(arr);
				}
				else {
					printf("\nError while getting Successors.");
				}
				printf("\n\n");
			break;

			case 11:
				printf("\nValues: opt = %d, x = %d", opt, x);
				arr = graph_get_predecessors(g, x);
				if(arr != NULL) {
					printf("\nPredeccessors are: ");

					int i = 0;
					while(arr[i] != -1) {
						printf("%d ", arr[i]);
						i++;
					}

					printf("%d ", arr[i]);

					graph_print(g);
					free(arr);
				}
				else {
					printf("\nError while getting Predecessors.");
				}
				printf("\n\n");
				printf("\n");
			break;

			case 12:
				printf("\nValues: opt = %d, x = %d, y = %d\n", opt, x, y);
				if(graph_is_neighbor(g, x, y)) {
					printf("\nYes. %d is a neighbour of %d", x, y);
					graph_print(g);
				}
				else {
					printf("\nNo. %d is not a neighbour of %d", x, y);
					graph_print(g);
				}
				printf("\n\n");
				printf("\n");
			break;

			case 13:
				printf("\nValues: opt = %d, x = %d, y = %d\n", opt, x, y);
				flag = graph_get_edge_weight(g, x, y);
				if(flag == -1) {
					printf("\nError while calculating edge weight.");
				}
				else {
					printf("\nEdge weight = %d.", flag);
					graph_print(g);
				}
				printf("\n\n");
			
			break;

			case 14:
				printf("\nValues: opt = %d\n", opt);
				graph_output_dot(g, "dotGraph.txt");
				printf("\nDot Graph saved.\n\n");
			
				printf("\n");
			break;

			case 15:
				printf("\nValues: opt = %d, x = %d, y = %d\n", opt, x, y);
				if(graph_has_path(g, x, y)) {
					printf("\nYes. Graph has a path from %d -> %d", x, y);
					graph_print(g);
				}
				else {
					printf("\nNo. Graph doesn't have a path from %d -> %d", x, y);
					graph_print(g);
				}
				printf("\n\n");
				printf("\n");
			break;

			case 16:
				printf("\nValues: opt = %d\n", opt);
				printf("\n");
				flag = graph_load_file(g,"new.txt");

				if (flag == 0)
				{
					printf("success\n" );
				}

				else{
					printf("error\n");
				}
			break;

			case 17:
				printf("\nValues: opt = %d\n", opt);
				graph_print(g);
				printf("\n");
			break;

			case 18:
				flag = graph_save_file(g,"new.txt");
					if (flag == 0)
					{
						printf("success\n");;
					}

					else
					{
						printf("error");
					}
			break;

			case 19:
				printf("\nValues: opt = %d, x = %d\n", opt, x);
				flag = graph_contains_edge(g, x, y);
				if(flag) {
					printf("\nedge exists.");
					graph_print(g);
				}
				else {
					printf("\nedge does not exist.");
				}
				printf("\n\n");
				printf("\n");
			break;

			default:
				printf("\nInvalid Input. Please try again.\n");
			break;

		}

	} while (opt != -1);

	return 0;
}


void depth_first_search(Graph *graph, int v1) {

	int i;

	//Set visited for v1 = 1
    graph->visited[v1] = 1;
	
	//For every valid path and a node that's not visited yet, call depth_first_search()
	for(i = 0; i <= graph->max_vertex; i++) {

       if((graph->adj_matrix[v1][i] > 0) && (graph->visited[i] == 0)) {
            depth_first_search(graph, i);
       }
	}
}

// Initialization Functions
Graph *graph_initialize(){

Graph *graph = malloc(sizeof(Graph));
if (graph ==  NULL)
{
	return NULL;
}

graph->max_vertex = -1;

for (int i = 0; i < MAX_VERTICES; i++)
{
	for (int j = 0; j < MAX_VERTICES; j++)
	{
		graph->adj_matrix[i][j] = 0;
	}
}

for (int i = 0; i < MAX_VERTICES; i++)
{
	graph->visited[i] = 0;	
}
		
return graph;

}

// Vertex Operations
int graph_add_vertex(Graph *graph, int v1){

if (graph == NULL)
{
	return-1;
}

if (v1 < 0 || v1>= MAX_VERTICES)
{
	return -1;
}


else
{
		if (graph->adj_matrix[v1][v1] != 0)
		{
			return 0;
		}


		else
		{
				graph->adj_matrix[v1][v1] = -2;
				
				if (v1 > (graph->max_vertex))
				{
				graph->max_vertex = v1;
				}
				return 0;
		}

}



}



int graph_contains_vertex(Graph *graph, int v1){
if (graph == NULL)
{
	return -1;
}

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

if (graph == NULL)
{
	return -1;
}


if (v1 < 0 || v1 >= MAX_VERTICES)
{
	return -1;
}

else{
			if (graph->adj_matrix[v1][v1] == 0)
			{
				return 0;
			}

			else{
					for (int j = 0; j < MAX_VERTICES; j++)
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
if (graph == NULL)
{
	return -1;
}

if (wt < 0)
{
	return -1;
}
	
if (v1 < 0 || v1 >= MAX_VERTICES || v2 < 0 || v2 >= MAX_VERTICES)
{
	return -1;
}

if (graph->adj_matrix[v1][v1] == 0 || graph->adj_matrix[v2][v2] == 0)
{
	return -1;
}


else{
			if (graph->adj_matrix[v1][v2] != 0)
			{
				graph->adj_matrix[v1][v2]	= wt;
				return 0;
			}

			else
			{
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

  	//Handler for when v1 or v2 does not exist
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

if (graph->adj_matrix[v1][v1] == 0 || graph->adj_matrix[v2][v2] == 0)
{
	return -1;
}
	
else
{
		if (graph->adj_matrix[v1][v2] == 0)
		{
			return 0;
		}

		else
		{
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

int count = 0;
if (graph == NULL)
{
	return -1;
}

	for (int i = 0; i < MAX_VERTICES; i++)
	{
		for (int j = 0; j < MAX_VERTICES; j++)
		{
			if (graph->adj_matrix[i][j] == graph->adj_matrix[j][i])
			{
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

int count = 0;

if (graph == NULL)
{
	return -1 ;
}

	for (int i = 0; i < MAX_VERTICES; i++)
	{
		for (int j = 0; j < MAX_VERTICES; j++)
		{
			if (graph->adj_matrix[i][j] != 0 && graph->adj_matrix[i][j] != -2)
			{
				count ++;
			}
		}
	}

return count;

}



int graph_total_weight(Graph *graph){

int weight = 0;

if (graph == NULL)
{
	return -1 ;
}

		for (int i = 0; i < MAX_VERTICES; i++)
	{
		for (int j = 0; j < MAX_VERTICES; j++)
		{
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

int degree = 0;

if (graph == NULL)
{
	return -1 ;
}

	
		if (graph->adj_matrix[v1][v1] != 0 && graph->adj_matrix[v1][v1] != -2)
		{
			degree = degree + 2; 
		}

		for (int j = 0; j < MAX_VERTICES; j++)
		{
			if (graph->adj_matrix[v1][j] != 0 && graph->adj_matrix[v1][j] != -2 && v1 != j)
			{
				degree++ ;
			}
		}
	
		for (int i = 0; i < MAX_VERTICES; i++)
		{
			if (graph->adj_matrix[i][v1] != 0 && graph->adj_matrix[i][v1] != -2 && i != v1)
			{
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
{
				if (graph->adj_matrix[v1][v2] == 0)
				{
					return -1;
				}

				else
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

if (graph->adj_matrix[v1][v1] == 0 || graph->adj_matrix[v2][v2] == 0)
{
	return 0;
}


else
{
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
if(!graph_contains_vertex(graph, v1)) {
		return NULL;
	}
	else {

		int count = 0;

		for(int i = 0; i <= graph->max_vertex; i++) {

			if(graph_contains_edge(graph, i, v1)) {
				count++; 
			}
		}

		int *arr = malloc(sizeof(int) * (count+1));
		int j = 0;

		for(int i = 0; i <= graph->max_vertex; i++) {

			if(graph_contains_edge(graph, i, v1)) {
				arr[j] = i;
				j++; 
			}
		}

		arr[j] = -1;

		return arr;
	}

	
}




int *graph_get_successors(Graph *graph, int v1){

if(!graph_contains_vertex(graph, v1)) {
		return NULL;
	}
	else {

		int count = 0;

		for(int i = 0; i <= graph->max_vertex; i++) {

			if(graph_contains_edge(graph, v1, i)) {
				count++; 
			}
		}

		int *arr = malloc(sizeof(int) * (count+1));
		int j = 0;

		for(int i = 0; i <= graph->max_vertex; i++) {

			if(graph_contains_edge(graph, v1, i)) {
				arr[j] = i;
				j++; 
			}
		}

		arr[j] = -1;

		return arr;
	}
}




// Graph Path Operations
int graph_has_path(Graph *graph, int v1, int v2){

//For any invalid vertex, return Error
	if(!graph_contains_vertex(graph, v1) || !graph_contains_vertex(graph, v2)) {
		return 0;
	}

	else {

		int i;

		//Every time this function is called, reset the visited array to avoid discrepencies
		for(i = 0; i < MAX_VERTICES; i++) { 
    		graph->visited[i] = 0;
    	}

    	//Handler for a case when the function wants to check if a path exists from v1 to itself.
    	if(v1 == v2) {

    		//If there is a self loop (path exists), return success.
    		if(graph->adj_matrix[v1][v2] > 0) {
    			return 1;
    		}
    		//In case there is no self loop, check if an indirect path exists.
    		else {

    			//Get all successors of of the vertex v1 and check if a path from them comes back to v1
    			int *arr = graph_get_successors(graph, v1);

    			if(arr == NULL) {
					return 0;
				}
				else {

					int j = 0;
					//Call DFS on each of the successor and set all visitable vertices to 1.
					while(arr[j] != -1) {
						
						depth_first_search(graph, arr[j]);
						j++;
					}

					free(arr);

					//If a path to v2 (which in this case is = v1) is found, return Success.
					if(graph->visited[v2]) {
						return 1;
					}
					//Else return failure.
					return 0;
				}
    		}
    	}
    	//Else case 
    	else {

    		//Call depth_first_search and set the visitable nodes to 1.
			depth_first_search(graph, v1);

			//If a path is found, return Success.
			if(graph->visited[v2]) {
				return 1;
			}
			//Else return failure.
			return 0;
    	}
	}


}




// Input/Output Operations
void graph_print(Graph *graph){

if (graph == NULL)
{
	return;
}


printf("\n");
printf("   ");
for (int i = 0; i <= graph->max_vertex; i++)
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
for (int i = 0; i <= (graph->max_vertex); ++i)
{
printf("-----");
}

printf("\n");
for (int i = 0; i <= (graph->max_vertex); i++)
{	
	if (i < 10)
	{
	printf("0%d |", i);
	}
	else
	printf("%d |",i);

	for (int j = 0; j <= (graph->max_vertex); j++)
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

if(graph == NULL || filename == NULL) {
    	return;
  	}
	
	
	FILE *fp = fopen(filename, "w");
	if(fp == NULL) {
		return;
	}

	
	fprintf(fp, "digraph {\n");

	for(int i = 0; i <= graph->max_vertex; i++) {
    	for(int j = 0; j <= graph->max_vertex; j++) {

    		
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


if (graph == NULL)
{
	return -1 ;
}

char buffer[20];
char *str = NULL;

FILE *fp = fopen(filename, "r");                 
  if(fp ==NULL){
    return -1;                                     
  }

  while(feof(fp)==0)
  {
  	fgets(buffer,20, fp);
int v1;
int v2;
int wt;

  str = strtok(buffer, ",");
  
  if (str != NULL)
  {
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

FILE *fp = fopen(filename, "w");

if (fp == NULL)
{
	return -1;
}

for (int i = 0; i <= (graph->max_vertex); i++)
{
	for (int j = 0; j <= (graph->max_vertex); j++)
	{
		if (graph->adj_matrix[i][j] == -2)
		{
			fprintf(fp, "%d\n",i);
		}

		else
		{
			if (graph->adj_matrix[i][j]!= 0 && graph->adj_matrix[i][j] != -2)
			{
				fprintf(fp, "%d,%d,%d\n",i,j,graph->adj_matrix[i][j]);
			}
		}
	}
}

fclose(fp);
return 0;

}



