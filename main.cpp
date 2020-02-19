#include <iostream>
using namespace std;
bool underZero(string obj)
{
    return obj[0] == '-';
}

string reverse(string obj)
{
    for (int i = 0; i < obj.length()/2 ; i++)
    {
        int temp = obj[i];
        obj[i] = obj [obj.length() - i - 1];
        obj[obj.length() - i - 1] = temp;
    }
    return obj;
}

int compare(string obj1,string obj2)
{
    for (int i = 1 ; i <= obj1.length() - 1 ; i++)
    {
        if ((obj1[i]) - '0' > (obj2[i - 1]) - '0')
        {
            return 1;
        }
        else if ((obj1[i]) - '0' < (obj2[i - 1]) - '0')
        {
            return -1;
        }
    }
    return 0;
}

void popZeros(string &obj)
{
    for(int i = obj.length() - 1 ; i >= 0 ; i--)
    {
        if (obj[i] == '0' && i != 0)
        {
            obj.erase(obj.begin() + i);
        }
        else
        {
            break;
        }
    }
}

void changeMinusPos(string& insertNum , string& eraseNum)
{
    insertNum.insert(insertNum.begin() + 0,'-');
    eraseNum.erase(eraseNum.begin() + 0);
}

void Minus(string num1, string num2, string &num3)
{
    cout << "ENTER TO b2 bigger than b1" << endl;
    int n;
    n = num2.length() - num1.length();
    int carry= 0;
    int tempInt;

    for (int i = num1.length() - 1 ; i >= 1  ; i--)
    {
        cout << "entered to for:" << endl;
        tempInt = ((num2[i + n] - '0') - (num1[i] - '0') - carry) % 10;
        carry = 0;
        if (tempInt < 0)
        {
            carry = 1;
            tempInt = tempInt + 10;
        }
        num3.append(to_string(tempInt));
        cout << num3 << endl;
    }
    for (int i = n  ; i >= 0 ; i--)
    {
        cout << "enter to for second" << endl;

        if (i == 0 && ((num2[i] - '0') - carry) == 0)
        {
            continue;
        }
        tempInt = ((num2[i] - '0') - carry) % 10;
        carry = 0;
        if (tempInt < 0)
        {
            carry = 1;
            tempInt += 10;
        }
        num3.append(to_string(tempInt));
        cout<< num3 <<endl;
    }
    popZeros(num3);
}
void sumWithPositive(string num1, string num2, string &num3)
{
    cout << "enter to first if" << endl;
    if(underZero(num1) && underZero(num2))
    {
        num1.erase(num1.begin());
        num2.erase(num2.begin());
        num3.append("-");
    }
    if (num1.length() < num2.length())
    {
        string temp = num1;
        num1 = num2;
        num2 = temp;
    }
    int n;
    n = num1.length() - num2.length();
    int carry = 0;
    int tempInt;

    for (int i = num2.length() - 1 ; i >= 0  ; i--)
    {
        cout << "entered to for:" << endl;
        int tempSum = (num1[i + n] - '0') + (num2[i] - '0') + carry;
        tempInt = tempSum % 10;
        num3.append(to_string(tempInt));
        carry = tempSum / 10;
        cout << num3 << endl;

        if (i == 0 && carry == 1 && (num1.length() == num2.length()))
        {
            cout << "last if for equal side" << endl;
            tempInt = carry;
            num3.append(to_string(tempInt));
            cout << num3 << endl;
        }
    }
    for (int i = n - 1 ; i >= 0 ; i--)
    {
        cout << "enter to for second" << endl;
        tempInt = ((num1[i] - '0') + carry) % 10;
        carry = ((num1[i] - '0') + carry) / 10;
        num3.append(to_string(tempInt));
        cout<< num3 <<endl;
    }
    if (num3[0] == '-')
    {
        num3.erase(num3.begin() + 0);
        num3.insert(num3.begin() + num3.length() , '-');
    }
}

string sum (string num1 , string num2)
{
    string num3;
    cout << "enter to class" << endl;
    if ((underZero(num1) && !underZero(num2)) || (underZero(num2) && !underZero(num1)))
    {
        cout << "enter to b1 is - if"<<endl;
        if (underZero(num2))
        {
            changeMinusPos(num1,num2);
            num3.append("-");
        }
        if (num1.length() - 1 > num2.length() || compare(num1,num2) == 1)
        {
            changeMinusPos(num2,num1);

            Minus(num2, num1, num3);

            num3.append("-");
        }
        else
        {
            Minus(num1, num2, num3);
        }
        if (num3[0] == '-')
        {
            num3.erase(num3.begin() + 0);
            if (num3[num3.length() - 1] == '-')
            {
                num3.erase(num3.begin() + (num3.length() - 1));
            }
            else
            {
                num3.insert(num3.begin() + num3.length() , '-');
            }
        }
    }
    else
    {
        sumWithPositive(num1, num2, num3);
    }
    return reverse(num3);
}
int main() {
    string b1 = "529";
    string b2 = "-544";
//    cout << sum(b1,b2) << endl;
cout << compare(b2,b1)<< endl;
    return 0;
}
