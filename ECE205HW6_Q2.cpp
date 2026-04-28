#include <iostream>
#include <vector>

using namespace std;

vector<char> deleteRepeatedChars(vector<char> myVector);
vector<char> selectionSort(vector<char> myVector);

int main()
{
	vector<char> myVector; //stores all characters entered by user
	char input; //holds each character as its entered

	cout << "Please enter a char, enter 0 to quit: " << endl; 
	cin >> input;
	//Keep asking for characters unitl user enters a 0
	while (input != '0')
	{
		myVector.push_back(input); //add character to the vector

		cout << "Please enter a char, enter 0 to quit: " << endl;
		cin >> input;
	}

	myVector = deleteRepeatedChars(myVector); //remove any duplicate characters
	cout << "Test\n";
	myVector = selectionSort(myVector); //sort characters from z to a
	cout << "Array with repeated char's removed and inversed:\n";
	cout << "Test\n";
	for (int i = 0; i < myVector.size(); i++)
		cout << myVector[i] << endl; //print each character

}

vector<char> deleteRepeatedChars(vector<char> myVector)
{
	for (int i = 0; i < myVector.size(); i++)
		for (int j = i + 1; j < myVector.size(); j++)
			if (myVector[i] == myVector[j])
			{
				//shift all of the elements by 1 to the left
				for (int k = j; k < myVector.size(); k++)
					myVector[k] = myVector[k + 1];

				myVector.resize(myVector.size() - 1); //subtract 1 from the vector
				j--;
			}
	return myVector;
}

vector<char> selectionSort(vector<char> myVector)
{
	for (int i = 0; i < myVector.size() - 1; i++)
	{
		int maxIndex = i; //assume current position is the maximum
		for (int j = i + 1; j < myVector.size(); j++)
			if (myVector[j] > myVector[maxIndex])
				maxIndex = j; //update maximum if a larger character is found
		//swap the maximum character into the 1st position
		char temp = myVector[i];
		myVector[i] = myVector[maxIndex];
		myVector[maxIndex] = temp;
	}
	return myVector;
}
