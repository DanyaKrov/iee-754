#include<iostream>
#include<string>
#include <vector>
#include <limits>
//#include "iee-754.h"
using namespace std;

long long itc_pow(int number, int number2)
{
    int num = 1;
    while (number > 0){
        num *= number2;
        number -= 1;
    }
    return num;
}

long long itc_len(string str){ // length of string
    int kol = 0;
    while (str[kol] != '\0')
    {
        kol++;
    }
    return kol;
}

string toStr(int num){
    string res = "", result = ""; int number;
    if (num == 0){
        return "0";
    }
    while(num > 0){
        number = num % 10;
        res += '0' + number;
        num = num / 10;
    }
    for(int i = itc_len(res) - 1; i > -1; i--){
        result += res[i];
    }
    return result;
}

long long ToInt(string str){
    long long num = 0;
    for(int i = 0; i < itc_len(str); i++){
        if (str[i] >= '0' && str[i] <= '9'){
            num = num * 10 + (str[i] - '0');
        }
    }
    return num;
}

string itc_slice_str(string str, int start, int end){
    if (end < start)
        return str;
    else{
            string answer = "";
            if (end >= itc_len(str))
                end = itc_len(str) - 1;
            for (int imp = start; imp < end + 1; imp++)
                answer += str[imp];
            return answer;
    }
}

string not_float(string Float){ //int in 2
    long long number = ToInt(Float), step = 1;
    string ans = "";
    for(int i = 0; i < itc_len(Float); i++){
        step = step * 10;
    }
    for(int i = 0; i < 23; i++){
        number = number * 2;
        if (itc_len(toStr(number)) > itc_len(Float)){
            ans += "1";
        }
        else{
            ans += "0";
        }
        number = number % step;
    }
    return ans;
}

long long not_num(long long num, int type = 2) //float in 2
{
    long long NumInTw = 0;
    int i = 0;
    while (num > type - 1){
            if (num % type != 0)
                NumInTw += (num % type) * itc_pow(i, 10);
            num /= type;
            i++;
        }
    NumInTw += num * itc_pow(i, 10);
    return NumInTw;
}

string exp_mantis(string str){
    long long num, kol;
    string point, int_num, drob, mantis, floating, y, exp;
    for(int i = 0; i < itc_len(str); i++){
        if(str[i] >= '0' and str[i] <= '9'){
            point += str[i];
        }
        else{ //end of int, start of float
            int_num += toStr(not_num(ToInt(point)));
        }
        if (str[i + 1] == '\0'){ //end of number
            drob += point;
            point = "";
        }
    }
    floating = not_float(drob);
    kol = 0;
    if (ToInt(int_num) == 0){
        while(ToInt(int_num) != 1){
            int_num += floating[0];
            floating = itc_slice_str(floating, 1, itc_len(floating) - 1);
            mantis += floating;
            kol--;
        }
        mantis += "0";
    }
    else if (ToInt(int_num) != 0){
        mantis += itc_slice_str(int_num, 1, itc_len(int_num) - 1);
        mantis += floating;
        mantis = itc_slice_str(mantis, 0, 22);
        kol = itc_len(int_num) - 1;
    }
    num = 127 + kol;
    y = toStr(not_num(num));
    if (itc_len(y) < 8){
        while(itc_len(exp) < 8 - itc_len(y)){
            exp += '0';
        }
        exp += y;
    }
    else {
        exp += y;
    }
    return exp + mantis;
}

string iee_754(string str){
    string ans = "";
    if (str[0] == '-')
        ans += "1";
    else
        ans += "0";
    ans += exp_mantis(str);
	return ans;
}

int main()
{
    string x;
    cin >>x;
    if (x == "inf")
        cout <<"01111111111111111111111111111111" <<endl;
    else if (x == "-inf")
        cout <<"11111111111111111111111111111111" <<endl;
    else if (x == "-0.0")
        cout <<"10000000000000000000000000000000" <<endl;
    else if (x == "0.0")
        cout <<"00000000000000000000000000000000" <<endl;
    else
        cout <<iee_754(x);
    return 0;
}
