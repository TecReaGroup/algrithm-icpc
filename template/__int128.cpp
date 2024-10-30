#include <bits/stdc++.h>
using namespace std;

__int128 read()
{
	__int128 flag = 1, num = 0;
	char cum = getchar();
	while (cum < '0' || cum > '9') {
        if (cum == '-') flag = -1;
        cum = getchar();
    }
	while ( cum >= '0' && cum <= '9') {
        num = (num << 3) + ( num << 1) + (cum - '0'); // num = num * 10 + cum - '0';
        cum = getchar();
    }
	return flag*num;
}

void print(__int128 x)
{
    if (x < 0) {
        cout << '-';
        x = -x;
    }
	if ( x >= 10) {
        print( x/10 );
        printf("%d", (int) (x%10));
    }
	else printf("%d", (int) x);
	return ;
}

int main() {
    __int128 a = read();
    __int128 b = read();
    __int128 c = a + b;
    print(c);
    cout << endl;
    return 0;
}