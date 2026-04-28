#include <iostream> 
#include <vector>

using namespace std;

int findMax(vector<int> myVector);
void fillHistogram(vector<int> myVector, vector<int>& histogram);
void printHistogram(vector<int> histogram);

int main()
{
	vector<int> myVector; //stores all numbers entered by user
	int number; //holds each number as it's entered

	cout << "Please enter a non-negative integer: " << endl;
	cin >> number;

	//Keeps asking for numbers until user enters a negative integer
	while (number >= 0)
	{
		myVector.push_back(number);

		cout << "Please enter a non-negative integer: " << endl;
		cin >> number;
	}

	int max = findMax(myVector);
	//Creates a histogram with enough bins, that start at 0 
	vector<int> histogram(max / 10 + 1, 0);

	fillHistogram(myVector, histogram); //count how many mumbers fall into each bin

	printHistogram(histogram); //displays each bin and its count

	return 0;
}

int findMax(vector<int> myVector)
{
	int max = 0;
	for (int i = 0; i < myVector.size(); i++)
		if (myVector[i] > max)
			max = myVector[i]; //update max if current number is larger
	return max;
}

void fillHistogram(vector<int> myVector, vector<int>& histogram)
{
	//Divide each value by 10 to get its bin index
	for (int i = 0; i < myVector.size(); i++)
		histogram[myVector[i] / 10]++; 
}

// Prints each bin's range and its count
void printHistogram(vector<int> histogram)
{
	for (int i = 0; i < histogram.size(); i++)
		cout << "Bin " << i + 1 << " (" << i * 10 << "-" << i * 10 + 9 << "): " << histogram[i] << endl;
}
