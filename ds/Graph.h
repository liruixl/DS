#pragma once

class Graph
{
public:
	virtual int		n() = 0;
	virtual int		e() = 0;
	virtual int		first(int) = 0;
	virtual int		next(int, int) = 0;
	virtual void	setEdge(int, int, int) = 0;
	virtual void	delEdge(int, int) = 0;
	virtual int		weigth(int, int) = 0;
	virtual int		getMark(int) = 0;
	virtual void	setMark(int, int) = 0;
};