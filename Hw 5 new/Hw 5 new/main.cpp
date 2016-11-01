#include <iostream>
#include <string>
#include <vector>

using namespace std;
//rewrite the function of 7.9 to use for generic type array elements
template <typename T>
int linearSearch(const T list[], T key, int arraysize)
{
    for(int i=0; i < arraysize; i++)
        if(key == list[i])
            return i;
    return -1;
}
//write a function to check if the elements in the array are sorted
template <typename T>
bool isSorted(const T list[], int size)
{
    bool sorted = true;
    for(int i=0; i < size; i++)
    {
        if(list[i] > list[i+1])
        {
            sorted = false;
            break;
        }
    }
    
    return sorted;
}
//implement a vector class from 12.2
	template <typename T>
	class vector{
	private:
 int vSize;
 int nums;
 T* elements;
 
	public:
 vector<T>()
 {
 T *vec = new T[vSize];
 for(int i=0;i < vSize; i++)
 vec[i]=0;
 }
 
 vector<T> (int size)
 {
 T *vec = new T[this->size];
 for(int i=0; i < vSize; i++)
 vec[i]=0;
 }
 
 vector<T> (int size, T defaultVal)
 {
 vSize = this->size;
 for(int i=0; i < vSize; i++)
 elements[i] = defaultVal;
 }
 
 void ensureCapacity()
 {
 if(nums >= vSize)
 {
 T *old = elements;
 vSize = 2 * nums;
 elements = new T[vSize];
 for (int i = 0; i < nums; i++)
 elements[i] = old[i];
 delete [] old;
 }
	
 }
        //push on to the stack
 void push_back(T element)
 {
 ensureCapacity();
 elements[nums] = element;
 nums++;
 }
 //pop off of the stack
 void pop_back()
 {
 return elements[nums-1];
 }
 
 unsigned const size()
 {
 return vSize;
 }
 
 T const at(int index)
 {
 for(int i=0; i<vSize; i++)
 {
 if(elements[i] == elements[index])
 return elements[i];
 }
 }
 
 bool const empty()
 {
 bool empty = false;
 for(int i=0; i<vSize;i++)
 if(elements[i]==NULL)
 empty = true;
 }
 
 void clear()
 {
 for(int i=0; i<vSize;i++)
 elements[i]==NULL;
 
 }
 
 void swap(vector &v2)
 {
 vSize= v2.vSize;
 for(int i=0; i<vSize;i++)
 elements[i]== v2.elements[i];
 }
	};
	
//write a function that shuffles the contents in a vector
template <typename T>
void shuffle(vector<T>& v)
{
    srand((unsigned int)time(NULL));
    for(int i=0; i<v.size(); i++)
    {
        int index = rand() % v.size();
        T temp = v[index];
        v[index]=v[i];
        v[i]=temp;
    }
}

//create a class called date
class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date()
    {
        year = 2000;
        month = 1;
        day = 1;
    }
    Date(int YEAR, int MONTH, int DAY)
    {
        year = YEAR;
        month = MONTH;
        day = DAY;
    }
};
class Transaction
{
private:
    Date date;
    char type;
    double amount;
    double balance;
    string description;
public:
    Transaction(char TYPE, double AMOUNT, double BALANCE, string description)
    {
        type = TYPE;
        if(type == 'D')
            balance += amount;
        if(type == 'W')
            balance -= amount;
    }
};
//create class called account to keep track of withdrawl and deposit
class Account
{
private:
    vector<Transaction> transactions;
    int id;
    double balance;
    static double annualInterestRate;
    string name;
    int numOfTransactions = 0;
    
public:
    Account(int ID, double startBalance, double startInterestRate)
    {
        id = ID;
        balance = startBalance;
        annualInterestRate = startInterestRate;
    }
    Account(string NAME, int ID, double startBalance, double startInterestRate)
    {
        name = NAME;
        id = ID;
        balance = startBalance;
        annualInterestRate = startInterestRate;
    }
    string getName()
    {
        return name;
    }
    int getID()
    {
        return id;
    }
    double getBalance()
    {
        return balance;
    }
    double getInterestRate()
    {
        return annualInterestRate;
    }
    int getNumOfTransactions()
    {
        return numOfTransactions;
    }
    void setID(int newID)
    {
        id = newID;
    }
    void setBalance(double newBalance)
    {
        balance = newBalance;
    }
    void setInterestRate(double newInterestRate)
    {
        annualInterestRate = newInterestRate;
    }
    double getMonthlyInterestRate()
    {
        double monthlyRate = annualInterestRate/12;
        return monthlyRate;
    }
    void withdraw(double amount)
    {
        balance -= amount;
        numOfTransactions++;
        transactions[numOfTransactions] = Transaction('W', amount, balance, "Withdrawl");
    }
    void deposit(double amount)
    {
        balance += amount;
        numOfTransactions++;
        transactions[numOfTransactions] = Transaction('D', amount, balance, "Deposit");
    }
    void printTransactions()
	    {
     for(int i=0; i<numOfTransactions; i++)
     {
	    }
};
int main() {
    
    // Problem 12.2
    int intList[] = { 1, 4, 4, 2, 5, -3, 6, 2};
    double doubleList[] = {1.1, 5.4, 6.0, 7.8, 9.0, 3.3};
    string stringList[] = {"Eric", "Steven", "Parker", "Micah"};
    
    cout << "Returns " << linearSearch(intList, 5, 6) << endl;
    cout << "Returns " << linearSearch(doubleList, 1.1, 6) << endl;
    cout << "Returns " << linearSearch(stringList, string("Eric"), 6) << endl;
    cout << endl;
    
    // Problem 12.4
    if(isSorted(intList, 6) == true) //use the list from previously in main
        cout << "The list of integers is sorted" << endl;
    else
        cout << "The list of integers is not sorted" << endl;
    if(isSorted(doubleList, 6)== true)
        cout << "The list of doubles is sorted" << endl;
    else
        cout << "The list of doubles is not sorted" << endl;
    if(isSorted(stringList, 6) == true)
        cout << "The list of strings is sorted" << endl;
    else
        cout << "The list of strings is not sorted" << endl;
    cout << endl;
    
    //Problem 12.20
    vector<int> nums(10);
    //cout << "Enter 10 integers: ";
    for(int i=0; i < nums.size(); i++)
        nums[i] = i;
    for(int i=0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    shuffle(nums);
    for(int i=0; i < nums.size(); i++)
        cout<< nums[i] << " ";
    cout << endl;
    
    //Problem 12.25
    //account of george, id number, balcance and interest rate
    Account Acc1("George", 1122, 1000, 1.5);
    //be able to deposit or withdraw money
    Acc1.deposit(30);
    Acc1.deposit(40);
    Acc1.deposit(50);
    Acc1.withdraw(5);
    Acc1.withdraw(4);
    Acc1.withdraw(2);
    
    cout << "Name: " << Acc1.getName() << endl;
    cout << "Interest Rate: " << Acc1.getInterestRate() << endl;
    cout << "Balance: " << Acc1.getBalance() << endl;
    Acc1.printTransactions();
    cout << endl;
    
    return 0;
}

