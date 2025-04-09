
#include <iostream>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while (T --) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int dx = abs(x1 - x2);
 		int dy = abs(y1 - y2);
 		
 		if (dx < dy) swap(dx, dy);
 		if (dx == dy) {
		 	if (dx % 2 == 0)
		 		cout << 1 << endl;
	 		else
	 			cout << 2 << endl;
		 } 
		 else
		 	cout << 3 << endl;
		
	}
	
	return 0;
} 