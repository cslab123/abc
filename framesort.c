#include <bits/stdc++.h>
using namespace std;

#define MAX_MSG_SIZE 127

struct Frame
{
	int sequence;
	char data;
};

// compare function for sort by sequence number
bool compare(Frame f1, Frame f2)
{
	return (f1.sequence < f2.sequence);
}

// to print the message in the frame
void print_msg(Frame f[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		cout << f[i].data;
	cout << endl;
}

int main()
{
	char msg[MAX_MSG_SIZE];
	cout << "Enter your message" << endl;
	scanf("%[^\n]", msg);
	
	int no_of_frames = strlen(msg);
	
	Frame f[no_of_frames];
	
	int i;
	// creating frames of size 1 bit
	for(i = 0; i < no_of_frames; i++)
	{
		f[i].sequence = (i + 1);
		f[i].data = msg[i];
	}
	
	// random shuffle
	for(i = 0; i < no_of_frames/2; i++)
	{
		int idx = random() % no_of_frames;
		swap(f[i], f[idx]);
	}
	
	// print shuffled message
	printf("Suffled Message is ");
	print_msg(f, no_of_frames);
	
	// sort the message
	sort(f, f + no_of_frames, compare);
	
	// print sorted message
	printf("Recieved Message is ");
	print_msg(f, no_of_frames);
	
	return 0;
}
