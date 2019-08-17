#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Point{
	T x;
	T y;
	Point(T xx, T yy): x(xx), y(yy){}
};

namespace LineSweep{
	
	long long dis(Point<long long> A, Point<long long> B){
		return abs(A.x - B.x) + abs(A.y - B.y);
	}
	
	long long closest_pairs(vector<Point<long long>> p){
		sort(p.begin(), p.end(), [](Point<long long> a, Point<long long> b)->bool{
			return a.x < b.x;
		});
		long long best = LONG_LONG_MAX;
		auto cmp = [](Point<long long> a, Point<long long> b){
			 return a.y < b.y; 
		};
		set<Point<long long>, decltype(cmp)> box;
		box.insert(p[0]);
		int left = 0;
		for(int i = 1; i < (int)p.size(); i++){
			while(left < i && p[i].x - p[left].x > best){
				box.erase(p[left]);
				left++;
			}
			for(auto it = box.lower_bound(Point<long long>(p[i].x - best, p[i].y - best)); it != box.end() && it->y - best <= p[i].y; it++){
				best = min(best, dis(p[i], *it));
			}
			box.insert(p[i]);
		}
		return best;
	}
}
	
	
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	Point<long long> p(2, 3);
	cout << p.x << " " << p.y << "\n";
	vector<Point<long long>> po;
	po.push_back(p);
	LineSweep::closest_pairs(po);
}
