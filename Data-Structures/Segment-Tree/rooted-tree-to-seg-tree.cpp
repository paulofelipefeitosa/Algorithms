//each subtree is represented by a subsegment [from[node], to[node]] on the array
void dfs(int node)
{
	used[node] = true;
	pos[node] = ++count;
	from[node] = count;
	to[node] = count;
	for(int i = 0;i < child[node].size();i++)
		if(!used[child[node][i]])
		{
			dfs(child[node][i]);
			to[node] = max(to[node], to[child[node][i]]);
		}
}

