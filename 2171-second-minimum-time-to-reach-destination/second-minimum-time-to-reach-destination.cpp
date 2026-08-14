class Solution {
public:

    int secondMinimum(int n, vector<vector<int>>& edges, int t, int c) {
        n++;
      vector<vector<int>> v(n,vector<int>(2,INT_MAX));
      priority_queue <array<int,2>, vector<array<int,2>>, greater<array<int,2>> > pq;
      vector<vector<int>> adj(n);
      for(auto &it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
      }
      v[1][0]=0;
      pq.push({0,1});
      n--;
      while(!pq.empty()){
        int dist=pq.top()[0];
        int node=pq.top()[1];
        pq.pop();
      
        if(node==n && dist==v[node][1] && dist!=v[node][0]){
           
        return dist;
        }
         if(node==n && dist==v[node][1])
         break;
        if(dist!=v[node][0] && dist!=v[node][1])
        continue;
        if(dist==INT_MAX)
        continue;
        
        for(auto &it:adj[node]){
          

              int y=dist/c;
y%=2;
if(y){
    int x=dist%c;
x=c-x;
dist+=x;
}

           int next=dist+t;
           int z=next/c;
           z%=2;
           if(it!=n && (z)){
            int x=next%c;
            x=c-x;
            next+=x;
           }
          
if(v[it][0]>(next)){
    v[it][1]=v[it][0];
    v[it][0]=next;
    pq.push({next,it});
    
}
else if(v[it][1]>(next) && v[it][0]!=next){
    v[it][1]=next;
    pq.push({next,it});
    
}
 
        }
      }
int dist=v[n][0];
//cout<<dist<<" ";
for(int i=0;i<2;i++){
    int y=dist/c;
y%=2;
if(y){
    int x=dist%c;
x=c-x;
dist+=x;
}
 dist=dist+t;
}
return dist;
    }
};