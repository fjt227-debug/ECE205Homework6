#include <iostream> 
#include <vector>

using namespace std;

void SieveOfEratosthenes(int n)
{
	vector<bool> primes(n, true); //initialize all to true
	primes[0] = primes[1] = false; //0 is not prime
	if (n > 1) primes[1] = false; //1 is not prime

	//For each number mark all its multiples as not prime
	for (int i = 2; i * i < n; i++)
	{
		if (primes[i])
		{
			for (int j = i * i; j < n; j += i)
				primes[j] = false; //mark multiple as not prime
		}
	}

	//Print all prime numbers
	for (int i = 2; i < n; i++)
	{
		if (primes[i])
			cout << i << " ";
	}
	cout << endl;
}

int main()
{
	int n;

	cout << "Enter a number to see the primes lower than it: ";
	cin >> n;
	cout << endl;

	SieveOfEratosthenes(n);
}
