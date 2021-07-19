#define mp(x,y) make_pair(x,y)

class Solution {
public:
    
    map<pair<string,string>,int> mapit;
    
    bool solve(string a,string b) {
        if(a == b) return true;
        if(mapit[mp(a,b)] != 0) {
            if(mapit[mp(a,b)] == 1) {
                return true;
            } else {
                return false;
            }
        }
        int n = a.length();
        for(int i = 1; i < a.length(); i++) {
            if( (( solve(a.substr(0,i),b.substr(n-i,i)) == true )  
            && (solve(a.substr(i,n-i),b.substr(0,n-i)) == true)) 
            || 
            ((solve(a.substr(0,i),b.substr(0,i)) == true) 
            && (solve(a.substr(i,n-i),b.substr(i,n-1)) == true ))) {
                mapit[mp(a,b)] = 1;
                return true;
            } 
        } 
        mapit[mp(a,b)] = -1;
        return false;
    }
    
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        return solve(s1,s2);
    }   
};