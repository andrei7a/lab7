#include<iostream> 
using namespace std;

template<class Type>
class  Set {

public:
	Type *mass = (Type*)malloc(0); int num = 0;

	Set() {}

	template <class Type>
	Set( int num, Type n ...)
	{
		Type *temp = &n;
		for (int i = 0; i < num; i++)
		{
			mass = (Type*)realloc(mass, sizeof(Type)*(++this->num));
			mass[this->num - 1] = *temp;
			temp++;
		}
	}

	friend ostream& operator << (ostream& output, Set& temp)
	{
		for (int i = 0; i < temp.num; i++)
		{
			output << temp.mass[i] << " ";
		}
		return output;
	}

	
	friend void operator >> <Type>(istream& input, Set&	temp)
	{
		Type *N = (Type*)malloc(0);
		int n = 0;
		Type tempInt = 0;
		input >> tempInt;
		do {
			N = (Type*)realloc(N, sizeof(Type)*++n);
			N[n - 1] = tempInt;
			input >> tempInt;
		} while (tempInt != -1);
		temp.mass = N;
		temp.num = n;
	}

	
	template <class Type> friend void operator += ( Set& temp, Type tempNum)
	{
		temp.mass = (Type*)realloc(temp.mass, sizeof(Type)*++temp.num);
		temp.mass[temp.num - 1] = tempNum;
	}

	



template <class Type>	friend  Set  operator + <Type>(Set<Type>& x, Set<Type>& y) {
		Set<Type> temp(x);
		bool flag = 0;
		for (int i = 0; i < y.num; i++)
		{
			for (int j = 0; j < x.num; j++)
			{
				if (y.mass[i] == x.mass[j])
				{
					flag = 1;
				}
			}
			if (flag == 0)
			{
				temp += y.mass[i];
			}
			else
			{
				flag = 0;
			}
		}
		return temp;
	}

	operator int()
	{
	return this->num;
	}


	
	 Type &operator[] (int i) {
		return this->mass[i];
	}
	
	friend  bool  operator <= (Set& x, Set& y) {
		bool flag = 0;
		bool globalFlag = 1;
		for (int i = 0; i < y.num; i++)
		{
			for (int j = 0; j < x.num; j++)
			{
				if (y.mass[i] == x.mass[j])
				{
					flag = 1;
				}
			}
			if (flag == 0) { globalFlag = 0; }
			else { flag = 0; }
		}

		for (int i = 0; i < x.num; i++)
		{
			for (int j = 0; j < y.num; j++)
			{
				if (x.mass[i] == y.mass[j])
				{
					flag = 1;
				}
			}
			if (flag == 0) { globalFlag = 0; }
			else { flag = 0; }
		}

		return globalFlag;

	}



};
void main() {


	 Set <double> a;
	cin >> a;
	
	Set <double> b;
	cin >> b;

	Set<double> c;


	cout << endl;
	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	 c = (a + b);
	cout << "A+B: " << c << endl;
	cout << "A<=B: ";
	if (a <= b)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "A[3]: " << a[2] << endl;
	cout << "Int(A): " << int(a) << endl;


}