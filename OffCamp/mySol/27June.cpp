#include <bits/stdc++.h>
using namespace std;
 
//Function for printing true and false 
void print_TF(bool f)
{
	if(f)cout << "true" << endl;
	else cout << "false" << endl;
}

//Function for getting parent elemnt of a node
int getParent(int id,int m)
{
	if(id==0)return -1;
	return (id-1)/m;
}

class TreeNode
{
	int n,m;
	unordered_map<int,int> lockHolding_map; // used to store id by which node is locked
	unordered_map<int,unordered_map<int,unordered_set<int>>> lockedChild_map; // used to store
	//the nodes of locked child at parent and lock in a set

	public:
	TreeNode(int x,int y)
	{
		n=x,m=y;
		lockHolding_map.clear();
		lockedChild_map.clear();
	}

	bool lock(int node,int id,int m)
	{
		if((lockHolding_map.find(node)!=lockHolding_map.end()) || lockedChild_map[node].size()>0)return false; // check if it is intially locked or not and also checks if the child odes are locked
		int parent = getParent(node,m);//get parent of the current node
		while (parent!=-1) 
		{
			if(lockHolding_map.find(parent)!=lockHolding_map.end())return false;//checks if parent is locked or not
			parent = getParent(parent,m);
		}
		
		lockHolding_map[node] = id;

		parent = getParent(node,m);
		while (parent!=-1) 
		{
			lockedChild_map[parent][id].insert(node);//insert the locked node in the set of parents.
			parent = getParent(parent,m);
		}
		return true;
	}

	bool unlock(int node, int id, int m)
	{
		if((lockHolding_map.find(node)==lockHolding_map.end()) || (lockHolding_map[node]!=id))return false;//checks if it is locked intially or not and checks if locked by same id.
		lockHolding_map.erase(node);
		int parent = getParent(node,m);

		while (parent!=-1) 
		{
			lockedChild_map[parent][id].erase(node);//removing the locked node drom its parents.
			if(lockedChild_map[parent][id].size()==0)lockedChild_map[parent].erase(id);
			parent = getParent(parent,m);
		}
		return true;
	}

	bool upgrade(int node,int id,int m)
	{
		if((lockHolding_map.find(node)!=lockHolding_map.end()) || (lockedChild_map[node].size()!=1) ||(lockedChild_map[node].find(id)==lockedChild_map[node].end()))return false; // checks if it is locked intially or not and checks if locked by same id and also the child nodes are locked.

		unordered_set<int> st = lockedChild_map[node][id];
		for(auto x:st)unlock(x,id,m);
		lock(node,id,m);
		return true;
	}
};

int main() 
{
	int n,m,q;
	cin >> n >> m >> q;
	TreeNode* root= new TreeNode(n,m);
	unordered_map<string,int> ind;
	int i=0;
	while (i<n) 
	{
		string node;
		cin >> node;
		ind[node] = i;
		i++;
	}

	for(int j=0;j<q;j++)
	{
		int op,id;
		string node;
		cin >> op >> node >> id;
		if(op==1)print_TF(root->lock(ind[node],id,m));
		else if(op==2)print_TF(root->unlock(ind[node],id,m));
		else print_TF(root->upgrade(ind[node],id,m));
	}
	return 0;
}


