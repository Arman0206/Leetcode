class Solution {
public:
void f(int index ,string& s,vector<string>& ans,string cur,int num,int count){
int n=s.size();
if(index==n){
    if(count<3)
    return;
    //x is the number
int x=0;
int check=1;
// check is ensuring is it a valid string or not

int y=0;
//number of digit is the number

int sz=0; 
//sz is basically the index of the string 
int n2=cur.size();
for(auto &it:cur){
    sz++;
    //when the current character is a . or that is break to current number
    if(it=='.' ){
        if(sz==1 || sz==n2){
        check=0;
        break;}
        x=0;
        y=0;
    continue;
    }
//i am increment the number of digits in the current number

    y++;
    x*=10;
    x+=(it-'0');
    if(y>1 && x<10){
        check =0;
        break;
    }
    if(y>1 && (x<0 || x>255)){
        check=0;
        break;
    }
}

if(check)
ans.push_back(cur);

return;
}

string cur2=cur;
char c=s[index];
int temp=num*10;
temp+=(c-'0');
cur+=c;
if(temp>=0 && temp<=255)
f(index+1,s,ans,cur,temp,count);

if(num>=0 && num<=255){
    count++;
    if(count>=4)
    return;
    char ch='.';
    if(cur2.size())
    ch=cur2.back();
    if(ch=='.')
    return;
    cur2+='.';
    f(index,s,ans,cur2,0,count);
}


}
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string cur;
f(0,s,ans,cur,0,0);
return ans;


    }
};