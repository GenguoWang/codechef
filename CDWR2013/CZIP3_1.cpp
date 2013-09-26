#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    int T,N,K;
    string str,strTmp;
    char c;
    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        str = "";
        for(int i=0;i<N;++i)
        {
            cin >> c;
            str.append(1,c);
        }
        queue<string> bq,eq;
        map<string,int> bm,em;
        bq.push(str);
        bm[str] = 0;
        strTmp = str;
        sort(str.begin(),str.end());
        reverse(str.begin(),str.end());
        if(strTmp==str) 
        {
            cout << 0 << endl;
            continue;
        }
        eq.push(str);
        em[str] = 0;
        bool found = false;
        int ib=1,ie=1,jb,je,res,lb=0,le=0;
        while(!found)
        {
            jb=0;
            lb++;
            while(ib--)
            {
                str = bq.front();
                bq.pop();
                for(int i=0;i<=N-K;++i)
                {
                    strTmp = str;
                    reverse(strTmp.begin()+i,strTmp.begin()+i+K);
                    if(em.count(strTmp)>0)
                    {
                        found=true;
                        res = lb+em[strTmp];
                        break;
                    }
                    if(bm.count(strTmp)==0)
                    {
                        bm[strTmp] = lb;
                        jb++;
                        bq.push(strTmp);
                    }
                }
            }
            ib = jb;
            /*
            je=0;
            le++;
            while(ie--)
            {
                str = eq.front();
                eq.pop();
                for(int i=0;i<=N-K;++i)
                {
                    strTmp = str;
                    reverse(strTmp.begin()+i,strTmp.begin()+i+K);
                    if(bm.count(strTmp)>0)
                    {
                        found=true;
                        res = le+bm[strTmp];
                        break;
                    }
                    if(em.count(strTmp)==0)
                    {
                        em[strTmp] = le;
                        je++;
                        eq.push(strTmp);
                    }
                }
            }
            ie = je;
            */
            if(ib==0||ie==0)break;
        }
        //cout << lb <<' '<< le << endl;
        if(found)
        {
            cout << res << endl;
        }
        else
        {
            cout << "NP" << endl;
        }
    }
}
