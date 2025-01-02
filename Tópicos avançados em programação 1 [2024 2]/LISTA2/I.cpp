#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long l = -2e9;
    long long r =  2e9;

    int n;
    scanf("%d", &n);

    char a1;
    char a2;
    char a3;
    int num;


    while(n--){
        getchar();
        scanf("%c%c ", &a1,&a2);
        scanf("%d", &num);
        scanf(" %c", &a3);
        printf("(%c)(%c)%d(%c)\n", a1, a2, num, a3);
        if(a3 == 'Y'){
            if(a2 == ' '){
                if(a1 == '<'){
                    r = r>num? num-1 : r;
                } else{
                    l = l<num? num+1: l;
                }
            } else {
                if(a1 == '<'){
                    r = r>num? num : r;
                } else{
                    l = l<num? num : l;
                }
            }
        } else {
            if(a2 == ' '){
                if(a1 == '<'){
                    l = !(l<num)? num+1 : l;
                } else{
                    r = !(r>num)? num-1 : r;
                }
            } else {
                if(a1 == '<'){
                    l = !(l<=num)? num : l;
                } else{
                    r = !(r<=num)? num : r;
                }
            }
        }
    }
    if(l>r){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    int result = (l+r)<<1;
    printf("%d\n", result);
}
