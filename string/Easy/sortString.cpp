string sort(string s) {
    // complete the function here
    vector<int>frq(26,0);
    
    for(int i = 0 ; i < s.length() ; i++){
        frq[s[i] - 'a']++;
    }
    
    string res;
    
    for(int i = 0 ; i <26 ; i++){
        int len = frq[i];
        while(len > 0){
            res.push_back(i + 'a');
            len--;
        }
    }
    
    return res;
}