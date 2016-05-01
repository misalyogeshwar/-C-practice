#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    queue <string> q;
    q.push("1");
    int n = 12;
    while(n > 0)
    {
        string s1 = q.front();
        cout << "\n\t"<<q.front();
        string s2 = s1 + "1";
        s1 = s1 + "0";
        q.pop();
        q.push(s1);
        q.push(s2);
        n--;
    }

    return 0;
}
