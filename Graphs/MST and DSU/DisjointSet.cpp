//0 base + 1 base indexing
//TC: O(1) , SC: O(N)

class DisjointSet {
	vector<int> rank, parent, size;

public:

	DisjointSet(int n) {
		rank.resize(n + 1, 0);
		size.resize(n + 1, 1);
		parent.resize(n + 1);
		for (int i = 0; i <= n; i++) parent[i] = i;
	}

	int ultimateParent(int u) {
		if (u == parent[u]) return u;

		return parent[u] = ultimateParent(parent[u]);
	}

	void unionBySize(int u, int v) {
		int pu = ultimateParent(u), pv = ultimateParent(v);

		if (pu != pv) {
			if (size[pu] >= size[pv]) {
				parent[pv] = pu;
				size[pu] += size[pv];
			}
			else {
				parent[pu] = pv;
				size[pv] += size[pu];
			}
		}
	}

	void unionByRank(int u, int v) {
		int pu = ultimateParent(u), pv = ultimateParent(v);

		if (pu != pv) {
			if (rank[pu] > rank[pv]) parent[pv] = pu;
			else if (rank[pv] > rank[pu]) parent[pu] = pv;
			else {
				parent[pv] = pu;
				rank[pu]++;
			}
		}
	}
};
