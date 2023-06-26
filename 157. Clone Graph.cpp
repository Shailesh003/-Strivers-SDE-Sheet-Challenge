#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
void DFS(graphNode* node,graphNode* copy, vector<graphNode*> &visited){
	visited[copy->data]=copy;
	for(auto it: node->neighbours){
		if(visited[it->data]==NULL){
			graphNode* newNode=new graphNode(it->data);
			copy->neighbours.push_back(newNode);
			DFS(it,newNode,visited);
		}
		else{
			copy->neighbours.push_back(visited[it->data]);
		}
	}
}
graphNode *cloneGraph(graphNode *node)
{
    if(node==NULL)return NULL;
	graphNode* copy=new graphNode(node->data);
	vector<graphNode*> visited(100000,NULL);
	DFS(node,copy,visited);
	return copy;

}