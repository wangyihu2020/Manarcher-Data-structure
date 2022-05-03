#include <iostream>
#include <vector>
#include <string>

using namespace std;
int check(string& s){
    string aux(2 * s.size() + 1, '0');
    int index = 0;
    for(char& c : aux){
        c = (index % 2 == 0) ? '#' : s[index / 2];
        index++;
    }

    vector<int> radius(aux.size());
    int R = -1;
    int i = 0;
    int C = -1;
    int maxVal = 0;
    while(i < radius.size()){
        radius[i] = i >= R ? 1 : min(R - i, radius[2 * C - i]);
        while(i + radius[i] < radius.size() && i - radius[i] >= 0){
            if(aux[i + radius[i]] != aux[i - radius[i]])
            {
                maxVal = max(radius[i], maxVal);
                break;
            }
            else {
                radius[i]++;
            }
            if(i + radius[i] > R){
                R = i + radius[i];
                C = i;
            }
            maxVal = max(radius[i], maxVal);
        }
        i++;
    }
    return maxVal - 1;
}
int main() {
    string s("abcdcbasshwsssssssss");
    int max = check(s);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
