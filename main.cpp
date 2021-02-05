#include "main.h"
#include "word.h"

int main(int argc, char **argv, char **envp)
{
	int numTerms;	//this is the user entered number of words that are being added to the list
	cout << "Input the number of words to be entered: ";
	cin >> numTerms;
	cout << endl;
	cout << "-----------------------------------------" << endl;
	
	word inputStr;
	int size = 0;	//working size of list, total number of elements
	int idx = 0;	//reused index variable for loops

	word list[numTerms];	//dynamically allocate this array to be of size numTerms
	
	for(idx = 0; idx < numTerms; idx++)
	{
		cin >> inputStr.data;	//store the input string in the buffer
		inputStr.count = 1;		//initialize count of string to be one, since we've received one
		if(size > 0)			//if there's elements in the array
		{
			for(int innerIdx = 0; innerIdx < size; innerIdx++)
			{
				if(strcmp(list[innerIdx].data, inputStr.data) == 0)	//if the string is found in the list
				{
					list[innerIdx].count++;	//does a handshake and updates the count of the match and the buffer
					inputStr.count++;
				}
			}
		}	
		list[size] = inputStr;	//add the input string to the list
		size++;					//increment the size by one since we added a term to it
	}
	
	for(idx = 0; idx < size; idx++)	//output the data
	{
		cout << list[idx].data << " " << list[idx].count << endl;
	}
	
	return 0;
}
