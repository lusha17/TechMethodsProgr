// LR6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector> 
#include <string> 
#include <iostream> 
#include <limits> 

 
class Graph { 
	size_t RootNum; 
	size_t RoadNum; 
 	size_t FirstRoot; 
 	std::vector<std::vector<int>*> Map; 
public: 
 	Graph(size_t a, size_t b, size_t N); 
 	void AddRout(size_t begin, size_t finish, size_t lengh); 
 	void Dijkstra(); 
 	~Graph(); 
}; 
 
 
 
 
Graph::Graph(size_t a, size_t b, size_t N) { 
	RootNum = a; 
 	RoadNum = b; 
 	FirstRoot = N; 
} 
 
 
void Graph::AddRout(size_t begin, size_t finish, size_t lengh) { 
	std::vector<int>* route = new std::vector<int>; 
 	route->push_back(begin); 
 	route->push_back(finish); 
 	route->push_back(lengh); 
 	Map.push_back(route); 
} 
 
 
void Graph::Dijkstra() { 
	int* routes = new int[RootNum]; 
 	bool* IsItVisit = new bool[RootNum]; 
 
 
 	for (size_t i = 0; i < RootNum; i++) { 
 		routes[i] = std::numeric_limits<int>::max(); 
 		IsItVisit[i] = false; 
 	} 
 
 
 	routes[FirstRoot] = 0; 
 	size_t id; 

 
 	for (size_t i = 0; i < RoadNum - 1; i++) { 
 		int min = std::numeric_limits<int>::max(); 
 
 
		for (size_t j = 0; j < RoadNum; j++) { 
 			if (min > routes[j] && !IsItVisit[j]) { 
 				min = routes[j]; 
				id = j; 
			} 
 		} 
 		IsItVisit[id] = true; 
 		for (int k = 0; k < RoadNum; k++) { 
 			for (size_t j = 0; j < Map.size(); j++) 
 			if ((*Map[j])[0] == id && (*Map[j])[1] == k && routes[id] != std::numeric_limits<int>::max() && !IsItVisit[k] && 
 				routes[id] + (*Map[j])[2] < routes[k]) 
 				routes[k] = routes[id] + (*Map[j])[2]; 
		} 
	} 

 
 	for (size_t i = 0; i < RootNum; i++) { 
		if (routes[i] != std::numeric_limits<int>::max()) std::cout << routes[i] << ' '; 
 	} 
 	std::cout << '\n'; 
} 


Graph::~Graph() { 
	for (auto it = Map.begin(); it != Map.end(); ++it) { 
 		delete *it; 
 	} 
 	Map.clear(); 
} 
 
int _tmain(int argc, _TCHAR* argv[]) { 
	size_t V, E, N; 
 	std::cin >> V >> E >> N; 
 	Graph Main(V, E, N); 
 	for (size_t i = 0; i < E; i++) { 
 		int start, finish, distance; 
 		std::cin >> start >> finish >> distance; 
		Main.AddRout(start, finish, distance); 
	} 
	Main.Dijkstra(); 
	system("pause"); 
	return 0; 
 } 


