//https://leetcode.com/problems/fraction-to-recurring-decimal/
class Solution {
public:
    string fractionToDecimal(long num, long den) {
        if(num==0)return "0";
        bool isNeg=(num<0||den<0)&&(num>0 || den>0) ?true:false;
        num=abs(num), den=abs(den);
        string ans;
        ans+=to_string(num/den);
        long rem=num%den;
        if(rem){
            ans+=".";
            unordered_map<long,long>s;
            long pos=0;
            string add;
            while(rem!=0){
                
                if(s.count(rem)>0){
                    cout<<s[rem];
                    add.insert(s[rem],"(");
                    add+=")";
                    break;
                }

                s[rem]=pos++;
                rem*=10;
                add+=to_string(rem/den);
                rem%=den;
            }
            ans+=add;  
            
        }
        if(isNeg)
            ans.insert(0,"-");
        return ans;
    }
};
