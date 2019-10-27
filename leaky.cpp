#include <bits/stdc++.h>
using namespace std;

int main()
{
    int incoming, outgoing, buck_size, n, store = 0;
    cout << "Enter bucket size, outgoing rate and no of inputs: " << endl;
    cin >> buck_size >> outgoing >> n;


    while(n--) 
    {
        cout << "Enter the incoming packet size : ";
        cin >> incoming;
        // cout << "Incoming packet size " << incoming << endl;
        if(incoming <= (buck_size - store))
        {
            store += incoming;
            cout << "Bucket buffer size " << store << " out of " << buck_size << endl;
        }
        else 
        {
            cout << "Dropped " << incoming - (buck_size - store) << " no of packets" << endl;
            store = buck_size;
            cout << "Bucket buffer size " << store << " out of " << buck_size << endl;
        }
        store = store - outgoing;
        if(store < 0)
        	store = 0;
        cout << "After outgoing" << endl;
        cout << store << " packets left out of " << buck_size << " in buffer" << endl;
    }
    
    return 0;
}
