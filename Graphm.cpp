#include "Graphm.h"

#include <cassert>


Graphm::Graphm(int numVert)
{
	numVertex = numVert;
	numEdge = 0;

	mark = new int[numVertex];
	for (int i = 0; i < numVertex; ++i)
		mark[i] = Unvisited;

	matrix = new int*[numVertex];
	for (int i = 0; i < numVertex; ++i)
	{
		matrix[i] = new int[numVertex];
	}

	for (int i = 0; i < numVertex; ++i)
	{
		for (int j = 0; j < numVertex; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}


Graphm::~Graphm()
{
	delete[] mark;
	for (int i = 0; i < numVertex; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int Graphm::n()
{
	return numVertex;
}

int Graphm::e()
{
	return numEdge;
}

int Graphm::first(int v)
{
	int i;
	for (i = 0; i < numVertex; ++i)
		if (matrix[v][i] != 0) break;
	return i; //return n if none
}

int Graphm::next(int v1, int v2)
{
	int i;
	for (i = v2 + 1; i < numVertex; ++i)
		if (matrix[v1][i] != 0) break;
	return i;
}

void Graphm::setEdge(int v1, int v2, int w)
{
	assert(w > 0, "Illegal weight value");
	if (matrix[v1][v2] == 0) numEdge++;
	matrix[v1][v2] = w;
}

void Graphm::delEdge(int v1, int v2)
{
	if (matrix[v1][v2] != 0) numEdge--;
	matrix[v1][v2] = 0;
}

int Graphm::weigth(int v1, int v2)
{
	return matrix[v1][v2];
}

int Graphm::getMark(int v)
{
	return mark[v];
}

void Graphm::setMark(int v1, int m)
{
	mark[v1] = m;
}
