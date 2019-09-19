#pragma once
#include "ds/Graph.h"
class Graphm :
	public Graph
{
private:
	int numVertex; //number of vertices
	int numEdge;
	int** matrix;
	int* mark;
public:

	enum Mark
	{
		Unvisited,
		Visited
	};

	Graphm(int numVert);
	~Graphm();

	int		n() override;
	int		e() override;
	int		first(int) override;
	//get v1's neighbor after v2
	int		next(int, int) override;
	void	setEdge(int, int, int) override;
	void	delEdge(int, int) override;
	int		weigth(int, int) override;
	int		getMark(int) override;
	void	setMark(int, int) override;
};

